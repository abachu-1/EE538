#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(SwapByPointer, test1) {
  float a = 3;
  SwapByPointer(&a, nullptr);
  EXPECT_EQ(a, 3);
}

TEST(SwapByPointer, test2) {
  float b = 2;
  SwapByPointer(nullptr, &b);
  EXPECT_EQ(b, 2);
}

TEST(SwapByPointer, test3) {
  float a = 10;
  float b = 20;
  SwapByPointer(&a, &b);
  EXPECT_EQ(a, 20);
  EXPECT_EQ(b, 10);
}


TEST(SwapByReference, test4) {
  float a = 10;
  float b = 20;
  SwapByReference(a, b);
  EXPECT_EQ(a, 20);
  EXPECT_EQ(b, 10);
}
