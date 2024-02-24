#include "q.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

#include <iostream>
#include <set>
#include <string>
#include <vector>

TEST(SetOperationsTest, SetDifferenceTest) {
  std::set<int> set1 = {1, 2, 3, 4, 5};
  std::set<int> set2 = {4, 5, 6, 7, 8};

  std::set<int> expected = {1, 2, 3};
  std::set<int> actual = setDifference(set1, set2);

  ASSERT_EQ(expected, actual);
}

TEST(SetOperationsTest, AreDisjointTest) {
  std::set<int> set1 = {1, 2, 3};
  std::set<int> set2 = {4, 5, 6};

  bool expected = true;
  bool actual = areDisjoint(set1, set2);

  ASSERT_EQ(expected, actual);
}

TEST(SetOperationsTest, AreNotDisjointTest) {
  std::set<int> set1 = {1, 2, 3};
  std::set<int> set2 = {3, 4, 5};

  bool expected = false;
  bool actual = areDisjoint(set1, set2);

  ASSERT_EQ(expected, actual);
}

TEST(SetOperationsTest, EmptySetDifferenceTest) {
  std::set<int> set1 = {1, 2, 3};
  std::set<int> set2 = {};

  std::set<int> expected = {1, 2, 3};
  std::set<int> actual = setDifference(set1, set2);

  ASSERT_EQ(expected, actual);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
