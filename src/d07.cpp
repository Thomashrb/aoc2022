#include "utils.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

namespace d07 {
uint32_t parse_size(std::ifstream &cmds, std::vector<uint32_t> &sizes) {
  uint32_t acc = 0;
  std::vector<std::string> tokens;
  for (std::string cmd; std::getline(cmds, cmd) && cmd != "$ cd ..";) {
    if (std::isdigit(cmd[0])) {
      tokens = utils::split(cmd, ' ');
      acc += utils::to_uint32(tokens.at(0));
    } else if (cmd.starts_with("$ cd")) {
      acc += parse_size(cmds, sizes);
    }
  }
  sizes.push_back(acc);
  return acc;
}

const uint32_t part_one(std::ifstream &cmds) {
  std::vector<uint32_t> sizes;
  parse_size(cmds, sizes);

  return std::accumulate(sizes.begin(), sizes.end(), 0,
      [](uint32_t acc, uint32_t size){ if (size < 100'000){ return acc += size; } else { return acc; } });
}

const uint32_t part_two(std::ifstream &cmds) {
  uint32_t min_delete = 0;
  std::vector<uint32_t> sizes;
  uint32_t all_files = parse_size(cmds, sizes);

  uint32_t TOTAL_SIZE = 70'000'000;
  uint32_t WANTED_SIZE = 30'000'000;
  uint32_t needed_min_size = WANTED_SIZE - (TOTAL_SIZE - all_files);

  std::sort(sizes.begin(), sizes.end());
  return *std::ranges::lower_bound(sizes, needed_min_size);
}
} // namespace d07
