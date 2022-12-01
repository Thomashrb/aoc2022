#ifndef UTILS_HPP
#define UTILS_HPP
#include <string>
#include <vector>

namespace utils {
const std::string load_input(const std::string filename);

const std::vector<std::vector<uint32_t>> split2numbers(const std::string input);
}

#endif // UTILS_HPP
