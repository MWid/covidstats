#ifndef LIB_INCLUDE_RKICASESREPOSITORY
#define LIB_INCLUDE_RKICASESREPOSITORY

#include "CasesRepository.h"

#include <cpprest/http_client.h>
#include <nlohmann/json_fwd.hpp>

namespace covidstats {
namespace casesrepository {
class RKICasesRepository : public CasesRepository {
public:
  RKICasesRepository();
  int getNewCases();

private:
  nlohmann::json retrieveData();
  web::http::client::http_client client_;
};
} // namespace casesrepository
} // namespace covidstats
#endif /* LIB_INCLUDE_RKICASESREPOSITORY */
