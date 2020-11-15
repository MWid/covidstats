#include "ResultStream/StdoutResultStream.h"

#include <iostream>

namespace covidstats {
namespace resultstream {
void StdoutResultStream::write(int data) { std::cout << data << "\n"; }
} // namespace resultstream
} // namespace covidstats
