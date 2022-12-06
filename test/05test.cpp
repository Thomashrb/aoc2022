#include "utils.hpp"
#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <d05.cpp>
#include <iostream>
#include <stack>
#include <vector>

const std::vector<std::stack<char>> test_stacks() {
   std::stack<char> s1;
   std::stack<char> s2;
   std::stack<char> s3;

   s1.push('Z');
   s1.push('N');

   s2.push('M');
   s2.push('C');
   s2.push('D');

   s3.push('P');

   return {s1,s2,s3};
}

const std::vector<std::string> test_input =
{"move 1 from 2 to 1",
 "move 3 from 1 to 3",
 "move 2 from 2 to 1",
 "move 1 from 1 to 2"};



const auto raw_input = utils::load_input("d05input.txt");
const auto input = utils::split(raw_input, '\n');

TEST_CASE("Day 05-1", "[part 1]") {
  auto test = d05::part_one(::test_stacks(), ::test_input);
  auto answer = d05::part_one(d05::stacks(), ::input);

  REQUIRE("CMZ" == test);
  REQUIRE("MQSHJMWNH" == answer);
}

TEST_CASE("Day 05-2", "[part 2]") {
  auto test = d05::part_two(::test_stacks(), ::test_input);
  auto answer = d05::part_two(d05::stacks(), ::input);

  REQUIRE("MCD" == test);
  REQUIRE("LLWJRBHVZ" == answer);
}
