#define _TURN_OFF_PLATFORM_STRING
#include "RKICasesRepository.h"
#include "gtest/gtest.h"

using namespace covidstats;

TEST(RKICasesRepository, GetNewCases) {
  EXPECT_GT(casesrepository::RKICasesRepository{}.getNewCases(), 0);
}
