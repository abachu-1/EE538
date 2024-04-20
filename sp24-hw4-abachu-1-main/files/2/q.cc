#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>

// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
#include <map>
#include <set>
#include <queue>
#include <stack>

std::vector<int> Graph::DFS(int root) {
  std::vector<int> visited;
  std::map<int, bool> marks;
  DFS_helper(root, marks, visited);
  return visited;
}

std::vector<int> Graph::DFSAll() {
  std::vector<int> visited;
  std::map<int, bool> marks;
  for (const auto &node : adjacency_list_) {
    if (!marks[node.first]) {
      DFS_helper(node.first, marks, visited);
    }
  }
  return visited;
}

BFSReturnValue Graph::BFS(int root) {
  BFSReturnValue result;
  const int SENTINEL_VALUE = 2147483647;  // Use a sentinel value for infinity
  std::vector<int> distance(adjacency_list_.size(), SENTINEL_VALUE);
  std::vector<int> previous(adjacency_list_.size(), -1);
  std::vector<int> visited;

  if (adjacency_list_.find(root) == adjacency_list_.end()) {
    result.distance = distance;
    result.visited = visited;

    for (size_t i = 0; i < adjacency_list_.size(); ++i) {
      if (adjacency_list_.find(i) == adjacency_list_.end()) {
        result.distance[i] = SENTINEL_VALUE;
        result.path[i] = {static_cast<int>(i)};
      }
    }

    return result;
  }

  std::queue<int> queue;
  queue.push(root);
  distance[root] = 0;
  visited.push_back(root);

  while (!queue.empty()) {
    int current = queue.front();
    queue.pop();

    for (int neighbor : adjacency_list_[current]) {
      if (distance[neighbor] == SENTINEL_VALUE) {
        distance[neighbor] = distance[current] + 1;
        previous[neighbor] = current;
        queue.push(neighbor);
        visited.push_back(neighbor);
      }
    }
  }

  result.distance = distance;
  result.visited = visited;
  for (size_t i = 0; i < adjacency_list_.size(); ++i) {
    result.path[i] = {}; // Initialize path as an empty set
    if (distance[i] != SENTINEL_VALUE) {
      int current = i;
      while (current != root) {
        result.path[i].insert(result.path[i].begin(), current);
        current = previous[current];
      }
      result.path[i].insert(result.path[i].begin(), root);
    } else {
    }
  }

  return result;
}


bool Graph::IsPathBetweenNodes(int i, int j) {
  if (adjacency_list_.find(i) == adjacency_list_.end() ||
      adjacency_list_.find(j) == adjacency_list_.end()) {
    return false;
  }

  std::vector<int> visited = DFS(i);
  return std::find(visited.begin(), visited.end(), j) != visited.end();
  return std::find(visited.begin(), visited.end(), j) != visited.end();
}

bool Graph::IsBidirectional() {
  for (const auto &node : adjacency_list_) {
    for (int neighbor : node.second) {
      if (adjacency_list_[neighbor].find(node.first) == adjacency_list_[neighbor].end()) {
        return false;
      }
    }
  }
  return true;
}

bool Graph::IsConnected() {
  for (const auto &node : adjacency_list_) {
    std::vector<int> visited = DFS(node.first);
    if (visited.size() != adjacency_list_.size()) {
      return false;
    }
  }
  return true;
}

bool Graph::ReachesACycle(int start_node) {
  std::map<int, NodeStatus> status;
  return ReachesACycleHelper(start_node, status);
}

bool Graph::HasCycle() {
  for (const auto &node : adjacency_list_) {
    std::map<int, NodeStatus> status;
    if (ReachesACycleHelper(node.first, status)) {
      return true;
    }
  }
  return false;
}

void Graph::DFS_helper(int root, std::map<int, bool> &marks, std::vector<int> &visited) {
  std::stack<int> stack;
  stack.push(root);

  while (!stack.empty()) {
    int current = stack.top();
    stack.pop();

    if (!marks[current]) {
      marks[current] = true;
      visited.push_back(current);

      // Push neighbors in reverse order to maintain the expected order
      std::vector<int> neighbors(adjacency_list_[current].begin(), adjacency_list_[current].end());
      std::reverse(neighbors.begin(), neighbors.end());
      for (int neighbor : neighbors) {
        if (!marks[neighbor]) {
          stack.push(neighbor);
        }
      }
    }
  }
}


void Graph::BFS_helper(int root, std::vector<int> &distance,
                       std::vector<int> &previous, std::vector<int> &visited) {
  std::queue<int> queue;
  queue.push(root);

  distance[root] = 0;
  visited.push_back(root);

  while (!queue.empty()) {
    int current = queue.front();
    queue.pop();

    for (int neighbor : adjacency_list_[current]) {
      if (distance[neighbor] == -1) {
        distance[neighbor] = distance[current] + 1;
        previous[neighbor] = current;
        visited.push_back(neighbor);
        queue.push(neighbor);
      }
    }
  }
}

bool Graph::ReachesACycleHelper(int start_node, std::map<int, NodeStatus> &status) {
  if (status[start_node] == NodeStatus::Visited) {
    return false;
  }

  status[start_node] = NodeStatus::Visiting;

  for (int neighbor : adjacency_list_[start_node]) {
    if (status[neighbor] == NodeStatus::Visiting || ReachesACycleHelper(neighbor, status)) {
      return true;
    }
  }
  status[start_node] = NodeStatus::Visited;
  return false;
}

