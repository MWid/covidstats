#ifndef LIB_INCLUDE_RKICASESREPOSITORY
#define LIB_INCLUDE_RKICASESREPOSITORY

#include "CasesRepository.h"

#include <cpprest/http_client.h>
#include <nlohmann/json_fwd.hpp>

namespace covidstats {
namespace casesrepository {

// This class uses the official data for COVID19 infections as provided by the
// RKI.
class RKICasesRepository : public CasesRepository {
public:
  virtual int getNewCases();

private:
  nlohmann::json retrieveNewCases();
  web::http::client::http_client client_{
      web::http::client::http_client{_XPLATSTR(
          "https://services7.arcgis.com/mOBPykOjAyBO2ZKk/arcgis/rest/services/"
          "RKI_COVID19/FeatureServer/0/")}};
};
} // namespace casesrepository
} // namespace covidstats
#endif /* LIB_INCLUDE_RKICASESREPOSITORY */
