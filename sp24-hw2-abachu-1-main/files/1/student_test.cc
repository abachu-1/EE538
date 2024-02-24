#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(CountCharactersTest, test1) {
    std::string input = "$Test";
    std::map<char, int> expected={{'T', 1}, {'e', 1}, {'s', 1}, {'t', 1}, {'$', 1}};
    EXPECT_EQ(CountCharacters(input), expected);
}
