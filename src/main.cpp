#include "CasesRepository/RKICasesRepository.h"

#include <iostream>
#include <memory>

using namespace std;
using namespace covidstats;

int main() {
  auto repo = std::make_unique<casesrepository::RKICasesRepository>();
  cout << "New cases: " << repo->getNewCases() << endl;
}
