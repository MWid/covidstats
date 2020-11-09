#include "../include/RKICasesRepository.h"

#include <cpprest/http_client.h>

namespace covidstats {
namespace casesrepository {

int RKICasesRepository::getNewCases() {
  downloadData();
  return 42;
  //   return computeNewCases();
};

void RKICasesRepository::downloadData() {
  auto client = web::http::client::http_client{
      U("https://services7.arcgis.com/mOBPykOjAyBO2ZKk/arcgis/rest/services/"
        "RKI_COVID19/FeatureServer/0/"
        "query?where=1%3D1&outFields=*&outSR=4326&f=json")};
  auto jsonStringTask =
      client.request(web::http::methods::GET)
          .then([=](web::http::http_response response) {
            return response.extract_utf8string();
          })
          .then([=](std::string utf8string) { return utf8string; });

  jsonStringTask.wait();

  jsonData_ = jsonStringTask.get();
};
} // namespace casesrepository
} // namespace covidstats
