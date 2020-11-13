#ifndef LIB_INCLUDE_CASESREPOSITORY
#define LIB_INCLUDE_CASESREPOSITORY

namespace covidstats {
namespace casesrepository {
class CasesRepository {
public:
  virtual ~CasesRepository() = default;
  virtual int getNewCases() = 0;
};
} // namespace casesrepository
} // namespace covidstats
#endif /* LIB_INCLUDE_CASESREPOSITORY */
