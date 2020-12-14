#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include "../src/floorplan.hpp"

TEST_CASE("testing is_valid_expression" * doctest::timeout(300)) {
  fp::FloorplanTester tester;
  
  std::vector<int> expression{1,2,1};
  REQUIRE(tester.is_valid_expression(expression) == false);

  expression = {-1,2,1};
  REQUIRE(tester.is_valid_expression(expression) == false);

  expression = {1,-2,1};
  REQUIRE(tester.is_valid_expression(expression) == false);

  expression = {1,2,-1};
  REQUIRE(tester.is_valid_expression(expression) == true);

  expression = {1,2,-1,3};
  REQUIRE(tester.is_valid_expression(expression) == false);

  expression = {1,2,-1,-1};
  REQUIRE(tester.is_valid_expression(expression) == false);

  expression = {1,2,3,4,5,-1,-2,-1,-2};
  REQUIRE(tester.is_valid_expression(expression) == true);
}


TEST_CASE("testing operation M1" * doctest::timeout(300)) {
  fp::FloorplanTester tester;
  
  std::vector<int> prop{1,2,3,4,5,-1,-1,-1,-1};

  REQUIRE(tester.operand_swap(prop) == true);
}


TEST_CASE("testing operation M2" * doctest::timeout(300)) {
  fp::FloorplanTester tester;
  
  std::vector<int> prop{1,2,3,4,5,-1,-1,-1,-1};

  REQUIRE(tester.complement_cutline(prop) == true);
}



TEST_CASE("testing operation M3" * doctest::timeout(300)) {
  fp::FloorplanTester tester;
  
  std::vector<int> prop{1,2,3,4,5,-1,-1,-1,-1};

  REQUIRE(tester.complement_last2cutline(prop) == true);
  REQUIRE(tester.is_valid_expression(prop) == true);
  REQUIRE(prop == std::vector<int>{1,2,3,4,5,-1,-1,-2,-2});
}



TEST_CASE("testing operation M4" * doctest::timeout(300)) {
  fp::FloorplanTester tester;
  
  std::vector<int> prop{1,2,3,4,5,-1,-1,-1,-1};
  std::vector<int> curr{1,2,3,4,5,-1,-1,-1,-1};

  tester.operator_operand_swap(curr, prop);
  REQUIRE(tester.is_valid_expression(prop) == true);
  REQUIRE(curr == std::vector<int>{1,2,3,4,5,-1,-1,-1,-1});
}


TEST_CASE("testing operation M5" * doctest::timeout(300)) {
  fp::FloorplanTester tester;
  
  std::vector<int> prop{1,2,3,4,5,-1,-1,-1,-1};

  REQUIRE(tester.complement_first2cutline(prop) == true);
  REQUIRE(tester.is_valid_expression(prop) == true);
  REQUIRE(prop == std::vector<int>{1,2,3,4,5,-2,-2,-1,-1});
}


TEST_CASE("testing operation M6" * doctest::timeout(300)) {
  fp::FloorplanTester tester;
  
  std::vector<int> curr{1,2,3,4,5,-1,-1,-1,-1};
    
  tester.rotate_module(curr);
  REQUIRE(curr == std::vector<int>{1,2,3,4,5,-1,-1,-1,-1});
}


// TODO: complete the following unittests
// 1. is_valid_expression?
// 2. pack
// 3. operations