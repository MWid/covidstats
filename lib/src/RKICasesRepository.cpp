#include "../include/RKICasesRepository.h"

#include <cpprest/uri_builder.h>
#include <exception>
#include <nlohmann/json.hpp>

namespace {
const std::string numberOfNewCases = "numberOfNewCases";

utility::string_t getQueryUriForNewCases() {
  auto uriBuilder = web::uri_builder{U("/query")};

  // see
  // https://www.arcgis.com/home/item.html?id=f10774f1c63e40168479a1feb6c7ca74
  // for the documentation of this query
  uriBuilder.append_query(U("where"), U("NeuerFall in (-1,1)"));
  uriBuilder.append_query(
      U("outStatistics"),
      utility::conversions::to_string_t(
          "[{\"statisticType\":\"SUM\",\"onStatisticField\":\"AnzahlFall\","
          "\"outStatisticFieldName\":\"" +
          numberOfNewCases + "\"}]"));
  uriBuilder.append_query(U("f"), U("json"));
  return uriBuilder.to_string();
};
} // namespace

namespace covidstats {
namespace casesrepository {

RKICasesRepository::RKICasesRepository()
    : client_{web::http::client::http_client{U(
          "https://services7.arcgis.com/mOBPykOjAyBO2ZKk/arcgis/rest/services/"
          "RKI_COVID19/FeatureServer/0/")}} {}

int RKICasesRepository::getNewCases() {
  try {
    auto jsonData = retrieveData();
    return jsonData["features"][0]["attributes"][numberOfNewCases].get<int>();
  } catch (web::http::http_exception &e) {
    throw std::runtime_error(e.what());
  }
};

nlohmann::json RKICasesRepository::retrieveData() {
  auto jsonStringTask =
      client_.request(web::http::methods::GET, getQueryUriForNewCases())
          .then([=](web::http::http_response response) {
            return response.extract_utf8string();
          })
          .then([=](std::string utf8string) { return utf8string; });

  jsonStringTask.wait();

  return nlohmann::json::parse(jsonStringTask.get());
};
} // namespace casesrepository
} // namespace covidstats
