#ifndef LIB_INCLUDE_RESULTSTREAM_STDOUTRESULTSTREAM
#define LIB_INCLUDE_RESULTSTREAM_STDOUTRESULTSTREAM
#include "ResultStream.h"

#include <iosfwd>

namespace covidstats {
namespace resultstream {
class StdoutResultStream : public ResultStream {
public:
  virtual void write(int data) override;
};
} // namespace resultstream
} // namespace covidstats
#endif /* LIB_INCLUDE_RESULTSTREAM_STDOUTRESULTSTREAM */
