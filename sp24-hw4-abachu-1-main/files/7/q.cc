#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>
#include <map>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
std::vector<int> DFS(int s, std::map<int, std::vector<int>> &adjList) {
    std::vector<int> visitedNodes;
    std::stack<int> stack;
    std::unordered_set<int> visited;

    stack.push(s);
    visited.insert(s);

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();
        visitedNodes.push_back(current);

        for (int neighbor : adjList[current]) {
            if (visited.find(neighbor) == visited.end()) {
                stack.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    return visitedNodes;
}