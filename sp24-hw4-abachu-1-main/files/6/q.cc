#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
#include <functional>
using DfsFunction = std::function<void(std::vector<std::vector<char>>&, size_t, size_t)>;

DfsFunction dfs = [](std::vector<std::vector<char>>& maze, size_t row, size_t col) {
    if (row >= maze.size() || col >= maze[0].size() || maze[row][col] != '1') {
        return;
    }

    maze[row][col] = '2'; 

    dfs(maze, row - 1, col);  
    dfs(maze, row + 1, col);  
    dfs(maze, row, col - 1);  
    dfs(maze, row, col + 1);  
};

int NumConnectedComponents(std::vector<std::vector<char>>& maze) {
    if (maze.empty() || maze[0].empty()) {
        return 0;  // No connected components in an empty grid
    }

    int numComponents = 0;

    for (size_t i = 0; i < maze.size(); ++i) {
        for (size_t j = 0; j < maze[0].size(); ++j) {
            if (maze[i][j] == '1') {
                ++numComponents;
                dfs(maze, i, j);
            }
        }
    }

    return numComponents;
}




