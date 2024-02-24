#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(SetOperationsTest, test1) {
  std::set<int> set1 = {1, 2, 3, 4, 5, 9};
  std::set<int> set2 = {4, 5, 6, 7, 8, 8};
  std::set<int> expected = {1, 2, 3, 9};
  std::set<int> actual = setDifference(set1, set2);
  ASSERT_EQ(expected, actual);
}

TEST(SetOperationsTest, test2) {
  std::set<int> set1 = {1, 2, 3};
  std::set<int> set2 = {4, 5, 6};
  bool expected = true;
  bool actual = areDisjoint(set1, set2);
  ASSERT_EQ(expected, actual);
}

TEST(SetOperationsTest, test3) {
  std::set<int> set1 = {1, 2, 4};
  std::set<int> set2 = {4, 5, 6};
  bool expected = false;
  bool actual = areDisjoint(set1, set2);
  ASSERT_EQ(expected, actual);
}
