namespace covidstats {
namespace resultstream {
class ResultStream {
public:
  virtual ~ResultStream() = default;
  virtual void write(int data) = 0;
};
} // namespace resultstream
} // namespace covidstats
