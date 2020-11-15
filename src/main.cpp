#include "App.h"

#include <cstdlib>
#include <exception>
#include <iostream>

using namespace std;
using namespace covidstats;

int main(int argc, char *argv[]) {
  try {
    auto app = App{argc, argv};
    return app.run();
  } catch (exception &e) {
    cout
        << "An unexpected error has occurred. The application must be closed.\n"
        << e.what() << "\n";
    return EXIT_FAILURE;
  }
}
