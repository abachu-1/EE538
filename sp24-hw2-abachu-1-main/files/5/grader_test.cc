#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "q.h"
#include "gmock/gmock-more-matchers.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

// Test cases for push_back function
TEST(PushBackTest, PositiveValues) {
  int *array = nullptr;
  int size = 0;

  push_back(array, size, 10);
  push_back(array, size, 20);

  EXPECT_EQ(size, 2);
  EXPECT_EQ(array[0], 10);
  EXPECT_EQ(array[1], 20);

  delete[] array;
}

TEST(PushBackTest, EmptyArray) {
  int *array = nullptr;
  int size = 0;

  push_back(array, size, 10);

  EXPECT_EQ(size, 1);
  EXPECT_EQ(array[0], 10);

  delete[] array;
}

// Test cases for pop_back function
TEST(PopBackTest, PositiveValues) {
  int *array = new int[3]{10, 20, 30};
  int size = 3;

  pop_back(array, size);

  EXPECT_EQ(size, 2);
  EXPECT_EQ(array[0], 10);
  EXPECT_EQ(array[1], 20);

  delete[] array;
}

TEST(PopBackTest, EmptyArray) {
  int *array = nullptr;
  int size = 0;

  pop_back(array, size);

  EXPECT_EQ(size, 0);
  EXPECT_EQ(array, nullptr);
}

// Test cases for insert function
TEST(InsertTest, PositiveValues) {
  int *array = new int[3]{10, 30, 40};
  int size = 3;

  insert(array, size, 20, 1);

  EXPECT_EQ(size, 4);
  EXPECT_EQ(array[0], 10);
  EXPECT_EQ(array[1], 20);
  EXPECT_EQ(array[2], 30);
  EXPECT_EQ(array[3], 40);

  delete[] array;
}

TEST(InsertTest, InvalidIndex) {
  int *array = new int[3]{10, 20, 30};
  int size = 3;

  insert(array, size, 40, -1);

  EXPECT_EQ(size, 3);
  EXPECT_EQ(array[0], 10);
  EXPECT_EQ(array[1], 20);
  EXPECT_EQ(array[2], 30);

  delete[] array;
}

// Test cases for erase function
TEST(EraseTest, PositiveValues) {
  int *array = new int[4]{10, 20, 30, 40};
  int size = 4;

  erase(array, size, 1);

  EXPECT_EQ(size, 3);
  EXPECT_EQ(array[0], 10);
  EXPECT_EQ(array[1], 30);
  EXPECT_EQ(array[2], 40);

  delete[] array;
}

TEST(EraseTest, InvalidIndex) {
  int *array = new int[3]{10, 20, 30};
  int size = 3;

  erase(array, size, 3);

  EXPECT_EQ(size, 3);
  EXPECT_EQ(array[0], 10);
  EXPECT_EQ(array[1], 20);
  EXPECT_EQ(array[2], 30);

  delete[] array;
}

// Test cases for find function
TEST(FindTest, PositiveValues) {
  int array[5] = {10, 20, 30, 40, 50};
  int size = 5;

  EXPECT_EQ(find(array, size, 20), 1);
  EXPECT_EQ(find(array, size, 40), 3);
}

TEST(FindTest, ElementNotFound) {
  int array[3] = {10, 20, 30};
  int size = 3;

  EXPECT_EQ(find(array, size, 40), -1);
  EXPECT_EQ(find(array, size, 50), -1);
}
