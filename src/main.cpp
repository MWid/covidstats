#include "RKICasesRepository.h"
#include <iostream>

using namespace std;
using namespace covidstats;

int main() {
  cout << "New cases: " << casesrepository::RKICasesRepository{}.getNewCases()
       << endl;
}
