#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>
#include <vector>

namespace utils {
const std::string load_input(const std::string filename);

const std::vector<std::vector<uint32_t>> split2numbers(const std::string input);

const std::vector<std::string> split(const std::string input, char delim);
}

#endif // UTILS_HPP
