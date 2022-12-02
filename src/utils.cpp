#include "utils.hpp"

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace utils {
const std::string load_input(const std::string filename) {
  std::ifstream in_file;
  in_file.open(filename);

  std::stringstream str_stream;
  if (!in_file.is_open()) {
    std::cout << "failed to open " << filename << '\n';
  } else {
    str_stream << in_file.rdbuf();
  }
  return str_stream.str();
}

// one quirk of this is that double newline at the end of the file is
// required i tried fixing it with using ss.eof but unfortunately
// that didnt work, leaving it as is atm
const std::vector<std::vector<uint32_t>> split2numbers(const std::string input) {
  auto ss = std::stringstream{input};

  auto result = std::vector<std::vector<uint32_t>>{};
  auto group = std::vector<uint32_t>{};
  for (std::string line; std::getline(ss, line, '\n');) {
    if (line.empty()) {
      result.push_back(group);
      group.clear();
      continue;
    }
    group.push_back(std::stoi(line));
  }
  return result;
}

const std::vector<std::string> split(const std::string input, const char delim) {
  auto ss = std::stringstream{input};

  auto result = std::vector<std::string>{};
  for (std::string line; std::getline(ss, line, delim);) {
    result.push_back(line);
  }
  return result;
}

} // namespace utils
