#include "../include/RKICasesRepository.h"

#include <cpprest/uri_builder.h>
#include <exception>
#include <nlohmann/json.hpp>

namespace covidstats {
namespace casesrepository {

RKICasesRepository::RKICasesRepository()
    : client_{web::http::client::http_client{U(
          "https://services7.arcgis.com/mOBPykOjAyBO2ZKk/arcgis/rest/services/"
          "RKI_COVID19/FeatureServer/0/")}} {}

int RKICasesRepository::getNewCases() {
  try {
    auto jsonData = downloadData();
    return jsonData["features"][0]["attributes"]["numberOfCases"].get<int>();
  } catch (web::http::http_exception &e) {
    throw std::runtime_error(e.what());
  }
};

nlohmann::json RKICasesRepository::downloadData() {
  auto uriBuilder = web::uri_builder{U("/query")};

  // see
  // https://www.arcgis.com/home/item.html?id=f10774f1c63e40168479a1feb6c7ca74
  // for the documentation of this query
  uriBuilder.append_query(U("where"), U("NeuerFall in (-1,1)"));
  uriBuilder.append_query(
      U("outStatistics"),
      U("[{\"statisticType\":\"SUM\",\"onStatisticField\":\"AnzahlFall\","
        "\"outStatisticFieldName\":\"numberOfCases\"}]"));
  uriBuilder.append_query(U("f"), U("json"));

  auto jsonStringTask =
      client_.request(web::http::methods::GET, uriBuilder.to_string())
          .then([=](web::http::http_response response) {
            return response.extract_utf8string();
          })
          .then([=](std::string utf8string) { return utf8string; });

  jsonStringTask.wait();

  return nlohmann::json::parse(jsonStringTask.get());
}; // namespace casesrepository
} // namespace casesrepository
} // namespace covidstats
