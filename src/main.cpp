#include "CasesRepository/RKICasesRepository.h"
#include "ResultStream/StdoutResultStream.h"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <memory>

using namespace std;
using namespace covidstats;

int main() {
  try {
    auto repo = std::make_unique<casesrepository::RKICasesRepository>();
    auto newCases = repo->getNewCases();
    auto output = std::make_unique<resultstream::StdoutResultStream>();
    output->write(newCases);
    return EXIT_SUCCESS;
  } catch (exception &e) {
    cout << "Es ist ein unerwarteter Fehler aufgetreten. Die Anwendung muss "
            "beendet werden."
         << "\n"
         << e.what() << "\n";
    return EXIT_FAILURE;
  }
}
