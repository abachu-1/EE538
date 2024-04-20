#include <climits>
#include <iostream>
#include <string>

#include "q.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::ElementsAre;
using ::testing::ElementsAreArray;
using ::testing::Eq;
using ::testing::Pair;
using ::testing::UnorderedElementsAre;
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
// Test for a graph with a single node
TEST(DFSTest, SingleNode) {
  std::map<int, std::vector<int>> graph = {{0, {}}};
  auto result = DFS(0, graph);
  EXPECT_THAT(result, UnorderedElementsAre(0));
}

// Test for a graph with multiple nodes and no cycles
TEST(DFSTest, MultipleNodesNoCycle) {
  std::map<int, std::vector<int>> graph = {{0, {1}}, {1, {2}}, {2, {}}};
  auto result = DFS(0, graph);
  EXPECT_THAT(result, UnorderedElementsAre(0, 1, 2));
}

// Test for a graph with cycles
TEST(DFSTest, GraphWithCycles) {
  std::map<int, std::vector<int>> graph = {
      {0, {1, 2}}, {1, {2}}, {2, {0, 3}}, {3, {2}}};
  auto result = DFS(2, graph);
  EXPECT_THAT(result, UnorderedElementsAre(2, 3, 0, 1));
}

// Test for a disconnected graph
TEST(DFSTest, DisconnectedGraph) {
  std::map<int, std::vector<int>> graph = {
      {0, {1}}, {1, {}}, {2, {3}}, {3, {}}};
  auto result = DFS(0, graph);
  EXPECT_THAT(result, UnorderedElementsAre(
                          0, 1)); // Only visits the connected component
}
