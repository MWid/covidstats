#include "RKICasesRepository.h"
#include <iostream>

using namespace std;
using namespace covidstats;

int main() {
  auto repo = new casesrepository::RKICasesRepository{};
  cout << "New cases: " << repo->getNewCases() << endl;
}
