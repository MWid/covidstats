#ifndef LIB_INCLUDE_RKICASESREPOSITORY
#define LIB_INCLUDE_RKICASESREPOSITORY

#include "CasesRepository.h"

#include <string>

namespace covidstats {
namespace casesrepository {
class RKICasesRepository : public CasesRepository {
public:
  int getNewCases();

private:
  std::string jsonData_ = "";
  void downloadData();
};
} // namespace casesrepository
} // namespace covidstats
#endif /* LIB_INCLUDE_RKICASESREPOSITORY */
