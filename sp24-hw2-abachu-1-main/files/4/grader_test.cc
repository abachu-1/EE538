#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"
using ::testing::ElementsAre;
using ::testing::ElementsAreArray;
using ::testing::UnorderedElementsAre;
using ::testing::UnorderedElementsAreArray;

template <class T>
void PrintCollection(T input, std::string_view name = "") {
  if (!name.empty()) {
    std::cout << name << ": ";
  }
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}

// Write several test cases for each function.
//-----------------------------------------------------------------------------
TEST(UniqueVectorNotBySet, test1) {
  std::vector<int> v = {1, 1, 2, 2};
  PrintCollection(v, "in");

  UniqueVectorNotBySet(v);

  EXPECT_THAT(v, ElementsAreArray({1, 2}));
}

TEST(UniqueVectorNotBySet, test2) {
  std::vector<int> v = {};
  PrintCollection(v, "in");

  UniqueVectorNotBySet(v);

  EXPECT_TRUE(v.empty());
}

TEST(UniqueVectorNotBySet, test3) {
  std::vector<int> v = {1, 2};
  PrintCollection(v, "in");

  UniqueVectorNotBySet(v);

  EXPECT_THAT(v, ElementsAreArray({1, 2}));
}
//-----------------------------------------------------------------------------
TEST(UniqueVectorBySet, test1) {
  std::vector<int> v = {1, 1, 2, 2};
  PrintCollection(v, "in");

  UniqueVectorBySet(v);

  EXPECT_THAT(v, ElementsAreArray({1, 2}));
}

TEST(UniqueVectorBySet, test2) {
  std::vector<int> v = {};
  PrintCollection(v, "in");

  UniqueVectorBySet(v);

  EXPECT_TRUE(v.empty());
}
TEST(UniqueVectorBySet, test3) {
  std::vector<int> v = {1, 2};
  PrintCollection(v, "in");

  UniqueVectorBySet(v);

  EXPECT_THAT(v, ElementsAreArray({1, 2}));
}
//-----------------------------------------------------------------------------
TEST(IntersectVectors, test1) {
  std::vector<int> v1 = {1, 1, 2, 2};
  std::vector<int> v2 = {3, 3, 2};
  PrintCollection(v1, "v1");
  PrintCollection(v2, "v2");

  auto actual = IntersectVectors(v1, v2);

  EXPECT_THAT(actual, ElementsAreArray({2}));
}

TEST(IntersectVectors, test2) {
  std::vector<int> v1 = {1, 1, 2, 2, 3};
  std::vector<int> v2 = {3, 3, 2};
  PrintCollection(v1, "v1");
  PrintCollection(v2, "v2");

  auto actual = IntersectVectors(v1, v2);

  EXPECT_THAT(actual, ElementsAreArray({2, 3}));
}
//-----------------------------------------------------------------------------
// Test case for DiffVectors function
TEST(DiffVectorsTest, Test1) {
  // Test input vectors
  std::vector<int> input1{1, 2, 3, 4, 5};
  std::vector<int> input2{3, 4, 5, 6, 7};

  PrintCollection(input1, "v1");
  PrintCollection(input1, "v2");

  // Expected result set
  std::set<int> expected{1, 2};

  // Call the DiffVectors function
  std::set<int> result = DiffVectors(input1, input2);

  // Check if the result set matches the expected set
  ASSERT_EQ(result, expected);
}

TEST(DiffVectorsTest, Test2) {
  // Test input vectors
  std::vector<int> input1{1, 2, 3, 4, 5};
  std::vector<int> input2{6, 7, 8, 9, 10};

  PrintCollection(input1, "v1");
  PrintCollection(input1, "v2");

  // Expected result set
  std::set<int> expected{1, 2, 3, 4, 5};

  // Call the DiffVectors function
  std::set<int> result = DiffVectors(input1, input2);

  // Check if the result set matches the expected set
  ASSERT_EQ(result, expected);
}

TEST(DiffVectorsTest, Test3) {
  // Test input vectors with duplicates
  std::vector<int> input1{1, 2, 2, 3, 4, 5, 5};
  std::vector<int> input2{3, 4, 4, 5, 5, 6, 7};

  PrintCollection(input1, "v1");
  PrintCollection(input1, "v2");

  // Expected result set
  std::set<int> expected{1, 2};

  // Call the DiffVectors function
  std::set<int> result = DiffVectors(input1, input2);

  // Check if the result set matches the expected set
  ASSERT_EQ(result, expected);
}