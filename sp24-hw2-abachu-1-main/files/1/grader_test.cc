#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

std::ostream& operator<<(std::ostream& os, const std::map<char, int>& m) {
  os << "{ ";
  for (auto it = m.begin(); it != m.end(); ++it) {
    os << "{"
       << "'" << it->first << "', " << it->second << "}";
    auto it_next = it;
    if (++it_next != m.end()) {
      os << ", ";
    }
  }
  os << " }";
  return os;
}

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------
TEST(CountCharactersTest, BasicTest) {
  std::string input = "This is a test";
  std::cout << "input: " << input << std::endl;
  std::map<char, int> expected = {{'T', 1}, {'h', 1}, {'i', 2}, {'s', 3},
                                  {' ', 3}, {'a', 1}, {'t', 2}, {'e', 1}};
  std::cout << "expected: " << expected << std::endl;
  std::map<char, int> actual = CountCharacters(input);
  std::cout << "actual: " << actual << std::endl;
  EXPECT_EQ(actual, expected);
}

TEST(CountCharactersTest, EmptyInput) {
  std::string input = "";
  std::cout << "input: " << input << std::endl;
  std::map<char, int> expected = {};
  std::cout << "expected: " << expected << std::endl;
  std::map<char, int> actual = CountCharacters(input);
  std::cout << "actual: " << actual << std::endl;
  EXPECT_EQ(actual, expected);
}

TEST(CountCharactersTest, SingleCharacterInput) {
  std::string input = "a";
  std::cout << "input: " << input << std::endl;
  std::map<char, int> expected = {{'a', 1}};
  std::map<char, int> actual = CountCharacters(input);
  EXPECT_EQ(actual, expected);
}

TEST(CountCharactersTest, MultipleSentences) {
  std::string input = "This is a test. And this is another test!";
  std::cout << "input: " << input << std::endl;
  std::map<char, int> expected = {{' ', 8}, {'!', 1}, {'.', 1}, {'A', 1},
                                  {'T', 1}, {'a', 2}, {'d', 1}, {'e', 3},
                                  {'h', 3}, {'i', 4}, {'n', 2}, {'o', 1},
                                  {'r', 1}, {'s', 6}, {'t', 6}};
  std::cout << "expected: " << expected << std::endl;
  std::map<char, int> actual = CountCharacters(input);
  std::cout << "actual: " << actual << std::endl;
  EXPECT_EQ(actual, expected);
}
