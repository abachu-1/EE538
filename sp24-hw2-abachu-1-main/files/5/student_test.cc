#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(PushBackTest, test1) {
  int *array = nullptr;
  int size = 0;
  push_back(array, size, 20);
  push_back(array, size, 30);

  EXPECT_EQ(size, 2);
  EXPECT_EQ(array[0], 20);
  EXPECT_EQ(array[1], 30);
  delete[] array;
}

TEST(PopBackTest, test2) {
  int *array = new int[3]{100, 200, 300};
  int size = 3;

  pop_back(array, size);

  EXPECT_EQ(size, 2);
  EXPECT_EQ(array[0], 100);
  EXPECT_EQ(array[1], 200);
  delete[] array;
}

TEST(InsertTest, test3) {
  int *array = new int[4]{10, 30, 40, 50};
  int size = 4;

  insert(array, size, 20, 1);

  EXPECT_EQ(size, 5);
  EXPECT_EQ(array[0], 10);
  EXPECT_EQ(array[1], 20);
  EXPECT_EQ(array[2], 30);
  EXPECT_EQ(array[3], 40);
  EXPECT_EQ(array[4], 50);
  delete[] array;
}

TEST(InsertTest, test4) {
  int *array = new int[3]{120, 210, 300};
  int size = 3;

  insert(array, size, 400, -1);

  EXPECT_EQ(size, 3);
  EXPECT_EQ(array[0], 120);
  EXPECT_EQ(array[1], 210);
  EXPECT_EQ(array[2], 300);
  delete[] array;
}

TEST(EraseTest, test5) {
  int *array = new int[4]{110, 210, 330, 410};
  int size = 4;

  erase(array, size, 1);

  EXPECT_EQ(size, 3);
  EXPECT_EQ(array[0], 110);
  EXPECT_EQ(array[1], 330);
  EXPECT_EQ(array[2], 410);
  delete[] array;
}

TEST(EraseTest, test6) {
  int *array = new int[3]{102, 202, 3};
  int size = 3;

  erase(array, size, 3);

  EXPECT_EQ(size, 3);
  EXPECT_EQ(array[0], 102);
  EXPECT_EQ(array[1], 202);
  EXPECT_EQ(array[2], 3);

  delete[] array;
}

TEST(FindTest, test7) {
  int array[5] = {110, 220, 360, 470, 500};
  int size = 5;

  EXPECT_EQ(find(array, size, 220), 1);
  EXPECT_EQ(find(array, size, 470), 3);
}

TEST(FindTest, test8) {
  int array[3] = {10, 20, 30};
  int size = 3;

  EXPECT_EQ(find(array, size, 440), -1);
  EXPECT_EQ(find(array, size, 505), -1);
}
