#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

namespace d03 {
std::unordered_set<char> intersection(std::string s1, std::string s2) {
  std::string accumulator;
  std::unordered_set<char> result;

  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());
  std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                        std::back_inserter(accumulator));

  for (char c : accumulator) {
    result.insert(c);
  }

  return result;
}

std::unordered_set<char> intersection(std::string s1,
                                      std::unordered_set<char> set) {
  std::string accumulator;
  std::unordered_set<char> result;
  std::string s2;

  for (char c : set) {
    s2 += c;
  }

  std::sort(s1.begin(), s1.end());
  std::sort(s2.begin(), s2.end());
  std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                        std::back_inserter(accumulator));

  for (char c : accumulator) {
    result.insert(c);
  }

  return result;
}

const uint32_t valueof(char c) {
  if (std::isupper(c)) {
    // 'A' = 65 and A-Z should map to 27-52
    return (c + 27) - 65;
  }
  if (std::islower(c)) {
    // 'a' = 97 and a-z should map to 1-26
    return c - 96;
  }

  std::cout << "Unexpected input " << c << '\n';
  return 0;
}

int part_one(std::vector<std::string> rucksacks) {
  uint32_t result = 0;
  uint32_t rucksize = 0;
  std::string s1;
  std::string s2;

  for (std::string s : rucksacks) {
    rucksize = s.length();
    s1 = s.substr(0, rucksize / 2);
    s2 = s.substr(rucksize / 2, rucksize);
    for (char c : intersection(s1, s2)) {
      result += valueof(c);
    }
  }
  return result;
}

int part_two(std::vector<std::string> rucksacks) {
  uint32_t result = 0;

  for (uint32_t i = 0; i < rucksacks.size(); i += 3) {
    for (char c :
         intersection(rucksacks.at(i + 2),
                      intersection(rucksacks.at(i), rucksacks.at(i + 1)))) {
      result += valueof(c);
    }
  }
  return result;
}
} // namespace d03
