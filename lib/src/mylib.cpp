#include "../include/mylib.h"
#include <stdexcept>

namespace mylib {
int factorial(int n) {
  if (n < 0)
    throw std::invalid_argument("Input must not be negative!");

  return n <= 1 ? n : n * factorial(n - 1);
}
} // namespace mylib
