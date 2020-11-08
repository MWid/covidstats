#include "mylib.h"
#include "gtest/gtest.h"

TEST(FactorialsTest, ComputeFactorials) {
  EXPECT_EQ(mylib::factorial(1), 1);
  EXPECT_EQ(mylib::factorial(2), 2);
  EXPECT_EQ(mylib::factorial(3), 6);
  EXPECT_EQ(mylib::factorial(10), 3628800);
}
