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

TEST(UniqueVectorNotBySet, test1) {
  std::vector<int> v = {1, 1, 2, 2, 3, 4};
  

  UniqueVectorNotBySet(v);

  EXPECT_THAT(v, ElementsAreArray({1, 2, 3, 4}));
}

TEST(UniqueVectorNotBySet, test2) {
  std::vector<int> v = {};
  

  UniqueVectorNotBySet(v);

  EXPECT_TRUE(v.empty());
}

TEST(UniqueVectorBySet, test1) {
  std::vector<int> v = {1, 1, 2, 2};
  

  UniqueVectorBySet(v);

  EXPECT_THAT(v, ElementsAreArray({1, 2}));
}

TEST(UniqueVectorBySet, test2) {
  std::vector<int> v = {};

  UniqueVectorBySet(v);

  EXPECT_TRUE(v.empty());
}

TEST(UniqueVectorBySet, test3) {
  std::vector<int> v = {10, 20};

  UniqueVectorBySet(v);

  EXPECT_THAT(v, ElementsAreArray({10, 20}));
}

TEST(IntersectVectors, test1) {
  std::vector<int> v1 = {1, 1, 2, 2, 5};
  std::vector<int> v2 = {3, 3, 2, 4};

  auto actual = IntersectVectors(v1, v2);

  EXPECT_THAT(actual, ElementsAreArray({2}));
}


TEST(DiffVectorsTest, Test1) {

  std::vector<int> input1{1, 2, 3, 4, 5, 8};
  std::vector<int> input2{3, 4, 5, 6, 7};

  PrintCollection(input1, "v1");
  PrintCollection(input1, "v2");

  
  std::set<int> expected{1, 2, 8};

  
  std::set<int> result = DiffVectors(input1, input2);

 
  ASSERT_EQ(result, expected);
}
