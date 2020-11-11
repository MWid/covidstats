#include "../include/RKICasesRepository.h"

#include <cpprest/http_client.h>
#include <cpprest/uri_builder.h>
#include <nlohmann/json.hpp>

namespace covidstats {
namespace casesrepository {

int RKICasesRepository::getNewCases() {
  auto jsonData = downloadData();
  return jsonData["features"][0]["attributes"]["numberOfCases"].get<int>();
  //   return computeNewCases();
};

nlohmann::json RKICasesRepository::downloadData() {
  auto client = web::http::client::http_client{
      U("https://services7.arcgis.com/mOBPykOjAyBO2ZKk/arcgis/rest/services/"
        "RKI_COVID19/FeatureServer/0/")};
  auto uriBuilder = web::uri_builder{U("/query")};
  uriBuilder.append_query(U("where"), U("NeuerFall in (-1,1)"));
  uriBuilder.append_query(
      U("outStatistics"),
      U("[{\"statisticType\":\"SUM\",\"onStatisticField\":\"AnzahlFall\","
        "\"outStatisticFieldName\":\"numberOfCases\"}]"));
  uriBuilder.append_query(U("f"), U("json"));

  auto jsonStringTask =
      client.request(web::http::methods::GET, uriBuilder.to_string())
          .then([=](web::http::http_response response) {
            return response.extract_utf8string();
          })
          .then([=](std::string utf8string) { return utf8string; });

  jsonStringTask.wait();

  return nlohmann::json::parse(jsonStringTask.get());
}; // namespace casesrepository
} // namespace casesrepository
} // namespace covidstats
