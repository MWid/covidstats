#ifndef SRC_APP
#define SRC_APP
#include <boost/program_options.hpp>
namespace po = boost::program_options;

#include <string>

namespace covidstats {
class App {
public:
  App(int argc, char *argv[]);
  int run();

private:
  std::string fileName_;
  po::options_description desc_;
  po::variables_map vm_;
};
} // namespace covidstats
#endif /* SRC_APP */
