#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <utility>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
int FindNumberOfUniquePathsHelper(const std::vector<std::vector<int>> &grid, const std::pair<int, int> &current, const std::pair<int, int> &end) {
    if (current.first < 0 || current.second < 0 || current.first >= grid.size() || current.second >= grid[0].size() || grid[current.first][current.second] == 0) {
        return 0;
    }
    if (current == end) return 1;
    int right = FindNumberOfUniquePathsHelper(grid, {current.first, current.second + 1}, end);
    int down = FindNumberOfUniquePathsHelper(grid, {current.first + 1, current.second}, end);
    return right + down;
}

int FindNumberOfUniquePaths(const std::vector<std::vector<int>> &grid, const std::pair<int, int> start, const std::pair<int, int> end) {
    
    if (grid.empty() || start.first < 0 || start.second < 0 || end.first < 0 || end.second < 0 ||
        start.first >= grid.size() || start.second >= grid[0].size() || end.first >= grid.size() || end.second >= grid[0].size() ||
        grid[start.first][start.second] == 0 || grid[end.first][end.second] == 0) {
        return 0;
    }

    
    return FindNumberOfUniquePathsHelper(grid, start, end);
}
