#include "App.h"

#include "CasesRepository/RKICasesRepository.h"
#include "ResultStream/FileResultStream.h"
#include "ResultStream/StdoutResultStream.h"

#include <boost/algorithm/string.hpp>

#include <cstdio>
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

namespace covidstats {
App::App(int argc, char *argv[])
    : desc_{"Allowed options"}, vm_{}, fileName_{} {
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

  handleCommandLine();

  auto outputStream = makeOutputStream();

  auto repo = std::make_unique<casesrepository::RKICasesRepository>();
  auto newCases = repo->getNewCases();
  outputStream->write(newCases);
  return EXIT_SUCCESS;
}

void App::handleCommandLine() {
  if (vm_.count("output")) {
    fileName_ = vm_["output"].as<std::string>();
    boost::trim(fileName_);
  }
}

std::unique_ptr<resultstream::ResultStream> App::makeOutputStream() {
  if (fileName_.empty()) {
    return std::make_unique<resultstream::StdoutResultStream>();
  }

  if (fs::exists(fileName_)) {
    if (!fs::is_regular_file(fileName_)) {
      std::cout << "Cannot write to " << fileName_
                << " because it is not a regular file.\n";
      std::exit(EXIT_FAILURE);
    } else {
      std::cout << fileName_
                << " already exists.\nShould it be replaced? [y]es, [n]o: ";
      char input;
      std::cin >> input;
      // Here we are actually cheating: We always abort the app unless the
      // user types in 'y'.
      if (input != 'y') {
        std::cout << "\nAbort!\n";
        std::exit(EXIT_FAILURE);
      }
    }
  }
  return std::make_unique<resultstream::FileResultStream>(fileName_);
}

} // namespace covidstats
