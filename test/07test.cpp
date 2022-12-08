#include "utils.hpp"
#include <catch2/catch_test_macros.hpp>
#include <d07.cpp>

const std::vector<std::string> test_input =
{ "$ cd /",
  "$ ls",
  "dir a",
  "14848514 b.txt",
  "8504156 c.dat",
  "dir d",
  "$ cd a",
  "$ ls",
  "dir e",
  "29116 f",
  "2557 g",
  "62596 h.lst",
  "$ cd e",
  "$ ls",
  "584 i",
  "$ cd ..",
  "$ cd ..",
  "$ cd d",
  "$ ls",
  "4060174 j",
  "8033020 d.log",
  "5626152 d.ext",
  "7214296 k" };



const auto raw_input = utils::load_input("d07input.txt");
const auto input = utils::split(raw_input, '\n');

TEST_CASE("Day 07-1", "[part 1]") {
  auto test = d07::part_one(::test_input);
  auto answer = d07::part_one(::input);

  REQUIRE(95437 == test);
  REQUIRE(1845346 == answer);
}

TEST_CASE("Day 07-2", "[part 2]") {
  auto test = d07::part_two(::test_input);
//  auto answer = d07::part_two(::input);

  REQUIRE(24933642 == test);
//  REQUIRE(1845346 == answer);
}
