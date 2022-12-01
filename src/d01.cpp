#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

namespace d01 {
const int part_one(std::vector<std::vector<uint32_t>> calorie_lists) {
  uint32_t max_calories = 0;
  uint32_t list_sum;

  for (auto cs : calorie_lists) {
    list_sum = 0;
    for (uint32_t c : cs) {
      list_sum += c;
    }
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
    list_sum = 0;
    for (uint32_t c : cs) {
      list_sum += c;
    }
    max3(&top3_calories, list_sum);
  }

  return top3_calories.at(0) + top3_calories.at(1) + top3_calories.at(2);
}

} // namespace d01
