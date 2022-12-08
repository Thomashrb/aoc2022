#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>
#include <vector>

namespace utils {
const std::string load_input(const std::string filename);

const std::vector<std::string> split(const std::string input, char delim);

uint32_t to_uint32(const std::string& str);
}

#endif // UTILS_HPP
