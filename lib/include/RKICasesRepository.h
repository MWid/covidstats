#ifndef LIB_INCLUDE_RKICASESREPOSITORY
#define LIB_INCLUDE_RKICASESREPOSITORY

#include "CasesRepository.h"

#include <nlohmann/json_fwd.hpp>
#include <string>

namespace covidstats {
namespace casesrepository {
class RKICasesRepository : public CasesRepository {
public:
  int getNewCases();

private:
  nlohmann::json downloadData();
};
} // namespace casesrepository
} // namespace covidstats
#endif /* LIB_INCLUDE_RKICASESREPOSITORY */
