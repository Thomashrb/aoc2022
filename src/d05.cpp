#include <algorithm>
#include <numeric>
#include <pthread.h>
#include <stack>
#include <stdio.h>
#include <string>
#include <vector>

namespace d05 {

//    [B]             [B] [S]
//    [M]             [P] [L] [B] [J]
//    [D]     [R]     [V] [D] [Q] [D]
//    [T] [R] [Z]     [H] [H] [G] [C]
//    [P] [W] [J] [B] [J] [F] [J] [S]
//[N] [S] [Z] [V] [M] [N] [Z] [F] [M]
//[W] [Z] [H] [D] [H] [G] [Q] [S] [W]
//[B] [L] [Q] [W] [S] [L] [J] [W] [Z]
// 1   2   3   4   5   6   7   8   9
const std::vector<std::stack<char>> stacks() {
  std::stack<char> s1;
  std::stack<char> s2;
  std::stack<char> s3;
  std::stack<char> s4;
  std::stack<char> s5;
  std::stack<char> s6;
  std::stack<char> s7;
  std::stack<char> s8;
  std::stack<char> s9;

  for (char c : {'B','W','N'}) {
    s1.push(c);
  }

  for (char c : {'L','Z','S','P','T','D','M','B'}) {
    s2.push(c);
  }

  for (char c : {'Q','H','Z','W','R'}) {
    s3.push(c);
  }

  for (char c : {'W','D','V','J','Z','R'}) {
    s4.push(c);
  }

  for (char c : {'S','H','M','B'}) {
    s5.push(c);
  }

  for (char c : {'L','G','N','J','H','V','P','B'}) {
    s6.push(c);
  }

  for (char c : {'J','Q','Z','F','H','D','L','S'}) {
    s7.push(c);
  }

  for (char c : {'W','S','F','J','G','Q','B'}) {
    s8.push(c);
  }

  for (char c : {'Z','W','M','S','C','D','J'}) {
    s9.push(c);
  }

  return {s1, s2, s3, s4, s5, s6, s7, s8, s9};
}

void do_line_part_one(std::vector<std::stack<char>> *stacks, std::string instruction) {
  uint32_t mv_count;
  uint32_t mv_src;
  uint32_t mv_dest;
  sscanf(instruction.c_str(), "move %i from %i to %i", &mv_count, &mv_src, &mv_dest);

  char mv_element;
  for (int i = 0; i < mv_count; i++) {
    mv_element = stacks->at(mv_src - 1).top();
    stacks->at(mv_src - 1).pop();
    stacks->at(mv_dest - 1).push(mv_element);
  }
}

const std::string part_one(std::vector<std::stack<char>> stacks, std::vector<std::string> instructions) {
  for (std::string ins : instructions) {
    do_line_part_one(&stacks, ins);
  }

  auto fold_tops = [](std::string acc, std::stack<char> stack) {
    return acc + stack.top();
  };

  return std::accumulate(stacks.begin(), stacks.end(), std::string(), fold_tops);
}

// I would have chose a different data structure for this problem :)
// perhaps this would be an opportunity to learn templates
// if I revisit this solution?
void do_line_part_two(std::vector<std::stack<char>> *stacks, std::string instruction) {
  uint32_t mv_count;
  uint32_t mv_src;
  uint32_t mv_dest;
  sscanf(instruction.c_str(), "move %i from %i to %i", &mv_count, &mv_src, &mv_dest);

  std::vector<char> mv_elements = {};
  for (int i = 0; i < mv_count; i++) {
    mv_elements.push_back(stacks->at(mv_src - 1).top());
    stacks->at(mv_src - 1).pop();
  }
  std::reverse(mv_elements.begin(), mv_elements.end());
  for (char c: mv_elements) {
    stacks->at(mv_dest - 1).push(c);
  }
}

const std::string part_two(std::vector<std::stack<char>> stacks, std::vector<std::string> instructions) {
  for (std::string ins : instructions) {
    do_line_part_two(&stacks, ins);
  }

  auto fold_tops = [](std::string acc, std::stack<char> stack) {
    return acc + stack.top();
  };

  return std::accumulate(stacks.begin(), stacks.end(), std::string(), fold_tops);
}

} // namespace d05
