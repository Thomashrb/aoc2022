#include "utils.hpp"
#include <cstddef>
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

const std::vector<std::string> split(const std::string input, const char delim) {
  auto ss = std::stringstream{input};

  auto result = std::vector<std::string>{};
  for (std::string line; std::getline(ss, line, delim);) {
    result.push_back(line);
  }
  return result;
}

uint32_t to_uint32(const std::string& str) {
  uint32_t result = 0;
  for (const auto& c : str) {
    if (!std::isdigit(c)) {
      std::cout << "Error: " << str << " is not a number" << std::endl;
      return 0;
    }
    result *= 10;
    result += c - '0';
  }
  return result;
}
} // namespace utils
