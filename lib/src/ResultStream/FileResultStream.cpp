#include "ResultStream/FileResultStream.h"

#include <fstream>

namespace covidstats {
namespace resultstream {
FileResultStream::FileResultStream(const std::string &filename)
    : fileStream_(filename, std::ios::out) {}

void FileResultStream::write(int data) { fileStream_ << data << "\n"; }
} // namespace resultstream
} // namespace covidstats
