#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <string>
#include <unordered_set>
#include <vector>

#include "utils.hpp"

namespace d08
{
const std::vector<std::vector<size_t>> to_trees(std::vector<std::string> lines)
{
  std::vector<std::vector<size_t>> trees    = {{}};
  std::vector<size_t>              treeline = {};
  for (auto line : lines)
  {
    treeline.clear();
    for (char c : line)
    {
      treeline.push_back(c - '0');
    }
    trees.push_back(treeline);
  }
  return trees;
}

// cpp 23 aparrently has zip which would clean this up a lot as we could then use accumulate but
// for now I will stick to looping and manual index operations
const size_t count_treeline(std::vector<size_t> treeline)
{
  size_t visible = 0;
  bool   first   = true;
  for (auto t : treeline)
  {
    if (first)
    {
      first = false;
      visible++;
    } else if (t < treeline.at(visible))
    {
      visible++;
    }
    else
    {
      break;
    }
  }
  return visible;
}

const size_t count_visible(std::vector<std::vector<size_t>> forest)
{
  size_t visible = 0;
  for (auto horizontal : forest)
  {
    visible += count_treeline(horizontal);
    std::reverse(horizontal.begin(), horizontal.end());
    visible += count_treeline(horizontal);
    // TODO: remove
    std::reverse(horizontal.begin(), horizontal.end());
  }

  utils::flip(forest);
  for (auto vertical : forest)
  {
    visible += count_treeline(vertical);
    std::reverse(vertical.begin(), vertical.end());
    visible += count_treeline(vertical);
  }

  return visible;
}

const uint32_t part_one(std::vector<std::string> treelines)
{
  const auto forest = to_trees(treelines);
  for (auto ts : forest)
  {
    for (auto t : ts)
    {
      std::cout << t;
    }
    std::cout << '\n';
  }

  return count_visible(forest);
}
const uint32_t part_two(std::vector<std::string> treelines)
{
  const auto trees = to_trees(treelines);
  return 1;
}
}  // namespace d08
