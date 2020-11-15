#ifndef LIB_INCLUDE_RESULTSTREAM_RESULTSTREAM
#define LIB_INCLUDE_RESULTSTREAM_RESULTSTREAM
namespace covidstats {
namespace resultstream {
class ResultStream {
public:
  virtual ~ResultStream() = default;
  virtual void write(int data) = 0;
};
} // namespace resultstream
} // namespace covidstats
#endif /* LIB_INCLUDE_RESULTSTREAM_RESULTSTREAM */
