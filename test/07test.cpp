#include "utils.hpp"
#include <catch2/catch_test_macros.hpp>
#include <d07.cpp>
#include <fstream>

std::string inputfile = "d07input.txt";

TEST_CASE("Day 07-1", "[part 1]") {
  std::ifstream input(::inputfile.c_str());
  auto answer = d07::part_one(input);

  REQUIRE(1845346 == answer);
}

TEST_CASE("Day 07-2", "[part 2]") {
  std::ifstream input(::inputfile.c_str());
  auto answer = d07::part_two(input);

  REQUIRE(3636703 == answer);
}
