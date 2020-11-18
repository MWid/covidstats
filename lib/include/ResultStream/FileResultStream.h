#ifndef LIB_INCLUDE_RESULTSTREAM_FILERESULTSTREAM
#define LIB_INCLUDE_RESULTSTREAM_FILERESULTSTREAM
#include "ResultStream.h"

#include <fstream>
#include <string>

namespace covidstats {
namespace resultstream {
class FileResultStream : public ResultStream {
public:
  FileResultStream(const std::string &filename);
  virtual void write(int data) override;

private:
  std::ofstream fileStream_;
};
} // namespace resultstream
} // namespace covidstats
#endif /* LIB_INCLUDE_RESULTSTREAM_FILERESULTSTREAM */
