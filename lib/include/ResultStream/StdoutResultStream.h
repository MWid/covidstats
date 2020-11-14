#include "ResultStream.h"

#include <iosfwd>

namespace covidstats {
namespace resultstream {
class StdoutResultStream : public ResultStream {
public:
  virtual void write(int data);
};
} // namespace resultstream
} // namespace covidstats
