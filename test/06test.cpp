#include "utils.hpp"
#include <catch2/catch_test_macros.hpp>
#include <d06.cpp>

const std::string test_input0 = "mjqjpqmgbljsphdztnvjfqwrcgsmlb";
const std::string test_input1 = "bvwbjplbgvbhsrlpgdmjqwftvncz";
const std::string test_input2 = "nppdvjthqldpwncqszvftbrmjlhg";
const std::string test_input3 = "nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg";
const std::string test_input4 = "zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw";


const auto raw_input = utils::load_input("d06input.txt");

TEST_CASE("Day 06-1", "[part 1]") {
  auto test1 = d06::part_one(::test_input1);
  auto test2 = d06::part_one(::test_input2);
  auto test3 = d06::part_one(::test_input3);
  auto test4 = d06::part_one(::test_input4);
  auto answer = d06::part_one(::raw_input);

  REQUIRE(5 == test1);
  REQUIRE(6 == test2);
  REQUIRE(10 == test3);
  REQUIRE(11 == test4);
  REQUIRE(1909 == answer);
}

TEST_CASE("Day 06-2", "[part 2]") {
  auto test0 = d06::part_two(::test_input0);
  auto test1 = d06::part_two(::test_input1);
  auto test2 = d06::part_two(::test_input2);
  auto test3 = d06::part_two(::test_input3);
  auto test4 = d06::part_two(::test_input4);
  auto answer = d06::part_two(::raw_input);

  REQUIRE(19 == test0);
  REQUIRE(23 == test1);
  REQUIRE(23 == test2);
  REQUIRE(29 == test3);
  REQUIRE(26 == test4);
  REQUIRE(3380 == answer);
}
