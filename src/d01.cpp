#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <sstream>

namespace d01 {
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

const int part_one(std::vector<std::vector<uint32_t>> calorie_lists) {
  uint32_t max_calories = 0;
  uint32_t list_sum;

  for (auto cs : calorie_lists) {
    list_sum = std::accumulate(cs.begin(), cs.end(), 0);
    if (max_calories < list_sum) {
      max_calories = list_sum;
    }
  }
  return max_calories;
}

void max3(std::array<uint32_t, 3> *top3, uint32_t cand) {
  std::sort(top3->begin(), top3->end());

  for (uint32_t i : *top3) {
    if (cand > i) {
      top3->at(0) = cand;
      break;
    }
  }
}

const int part_two(std::vector<std::vector<uint32_t>> calorie_lists) {
  std::array<uint32_t, 3> top3_calories = {0, 0, 0};
  uint32_t list_sum;

  for (auto cs : calorie_lists) {
    list_sum = std::accumulate(cs.begin(), cs.end(), 0);
    max3(&top3_calories, list_sum);
  }

  return std::accumulate(top3_calories.begin(), top3_calories.end(), 0);
}

} // namespace d01
