// The cpprestsdk defines a macro "U" for platform strings.
// This macro does not work together with gtest hence we turn it off.
// We do not need it here anyway.
#define _TURN_OFF_PLATFORM_STRING
#include "RKICasesRepository.h"
#include "gtest/gtest.h"

using namespace covidstats;

TEST(RKICasesRepository, GetNewCases) {
  EXPECT_GT(casesrepository::RKICasesRepository{}.getNewCases(), 0);
}
