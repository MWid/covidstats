#include "App.h"

#include "CasesRepository/RKICasesRepository.h"
#include "ResultStream/FileResultStream.h"
#include "ResultStream/StdoutResultStream.h"

#include <cstdio>
#include <iostream>

namespace covidstats {
App::App(int argc, char *argv[])
    : fileName_{}, desc_{"Allowed options"}, vm_{} {
  desc_.add_options()
      // First parameter describes option name/short name
      // The second is parameter to option
      // The third is description
      ("help,h",
       "print usage message")("output,o", po::value(&fileName_),
                              "pathname for output (if empty, stdout is used)");

  store(parse_command_line(argc, argv, desc_), vm_);
}

int App::run() {
  if (vm_.count("help")) {
    std::cout << "covidstats - Command line tool to retrieve the new cases of "
                 "COVID 19 infections as published by RKI.\n";
    std::cout << desc_ << "\n";
    return EXIT_SUCCESS;
  }

  auto output = static_cast<std::unique_ptr<resultstream::ResultStream>>(
      std::make_unique<resultstream::StdoutResultStream>());
  if (vm_.count("output")) {
    output = std::make_unique<resultstream::FileResultStream>(
        vm_["output"].as<std::string>());
  }

  auto repo = std::make_unique<casesrepository::RKICasesRepository>();
  auto newCases = repo->getNewCases();
  output->write(newCases);
  return EXIT_SUCCESS;
}
} // namespace covidstats
