#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <random>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
enum class Direction { Right, Down, Left, Up };

std::vector<std::vector<int>> HikerPathHelper(std::vector<std::vector<int>>& maze,
                                              size_t row, size_t col,
                                              std::vector<std::vector<bool>>& visited) {
    if (row >= maze.size() || col >= maze[0].size() || maze[row][col] == 1 || visited[row][col]) {
        return {};
    }

    visited[row][col] = true;

    if (row == maze.size() - 1 && col == maze[0].size() - 1) {
        return {{static_cast<int>(row), static_cast<int>(col)}};
    }

    std::vector<Direction> directions = {Direction::Right, Direction::Down, Direction::Left, Direction::Up};

    // Randomly shuffle the directions
    std::random_device rd;
    std::default_random_engine rng(rd());
    std::shuffle(directions.begin(), directions.end(), rng);

    for (const auto& direction : directions) {
        size_t nextRow = row, nextCol = col;

        switch (direction) {
            case Direction::Right:
                nextCol++;
                break;
            case Direction::Down:
                nextRow++;
                break;
            case Direction::Left:
                nextCol--;
                break;
            case Direction::Up:
                nextRow--;
                break;
        }

        auto path = HikerPathHelper(maze, nextRow, nextCol, visited);

        if (!path.empty()) {
            path.insert(path.begin(), {static_cast<int>(row), static_cast<int>(col)});
            return path;
        }
    }

    return {};
}

std::vector<std::vector<int>> HikerPath(std::vector<std::vector<int>>& maze) {
    if (maze.empty() || maze[0].empty()) {
        return {{-1, -1}};
    }

    std::vector<std::vector<bool>> visited(maze.size(), std::vector<bool>(maze[0].size(), false));

    auto result = HikerPathHelper(maze, 0, 0, visited);

    return result.empty() ? std::vector<std::vector<int>>{{-1, -1}} : result;
}