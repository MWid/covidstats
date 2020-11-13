#ifndef LIB_INCLUDE_RKICASESREPOSITORY
#define LIB_INCLUDE_RKICASESREPOSITORY

#include "CasesRepository.h"

#include <cpprest/http_client.h>
#include <nlohmann/json_fwd.hpp>

namespace covidstats {
namespace casesrepository {
class RKICasesRepository : public CasesRepository {
public:
  int getNewCases();

private:
  nlohmann::json retrieveData();
  web::http::client::http_client client_{
      web::http::client::http_client{_XPLATSTR(
          "https://services7.arcgis.com/mOBPykOjAyBO2ZKk/arcgis/rest/services/"
          "RKI_COVID19/FeatureServer/0/")}};
};
} // namespace casesrepository
} // namespace covidstats
#endif /* LIB_INCLUDE_RKICASESREPOSITORY */
