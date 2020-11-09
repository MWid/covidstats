#include "RKICasesRepository.h"
#include "gtest/gtest.h"

using namespace covidstats;

TEST(RKICasesRepository, GetNewCases) {
  EXPECT_EQ(casesrepository::RKICasesRepository{}.getNewCases(), 42);
}
