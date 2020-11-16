#ifndef SRC_APP
#define SRC_APP
#include "ResultStream/ResultStream.h"

#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include <string>

namespace covidstats {
class App {
public:
  App(int argc, char *argv[]);
  int run();

private:
  void handleCommandLine();
  std::unique_ptr<resultstream::ResultStream> makeOutputStream();

  po::options_description desc_;
  po::variables_map vm_;
  std::string fileName_;
};
} // namespace covidstats
#endif /* SRC_APP */
