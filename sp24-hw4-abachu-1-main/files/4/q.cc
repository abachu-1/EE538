#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <iostream>
#include <limits.h>
#include <map>
#include <set>
using namespace std;
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
StudentMaxHeap::StudentMaxHeap(std::vector<Student>& input) {
    ConvertToHeap(input);
}

Student StudentMaxHeap::GetParent(int i) {
    if (i <= 0 || static_cast<size_t>(i) >= data_.size()) {
        return Student("NO_NAME", INT_MIN);
    }
    return data_[(i - 1) / 2];
}

Student StudentMaxHeap::GetLeft(int i) {
    size_t left_index = 2 * i + 1;
    if (left_index >= data_.size()) {
        return Student("NO_NAME", INT_MIN);
    }
    return data_[left_index];
}

Student StudentMaxHeap::GetRight(int i) {
    size_t right_index = 2 * i + 2;
    if (right_index >= data_.size()) {
        return Student("NO_NAME", INT_MIN);
    }
    return data_[right_index];
}

int StudentMaxHeap::GetParentIndex(int i) {
    if (i <= 0 || static_cast<size_t>(i) >= data_.size()) {
        return INT_MAX;
    }
    return (i - 1) / 2;
}

int StudentMaxHeap::GetLeftIndex(int i) {
    size_t left_index = 2 * i + 1;
    if (left_index >= data_.size()) {
        return INT_MAX;
    }
    return left_index;
}

int StudentMaxHeap::GetRightIndex(int i) {
    size_t right_index = 2 * i + 2;
    if (right_index >= data_.size()) {
        return INT_MAX;
    }
    return right_index;
}

int StudentMaxHeap::GetLargestChildIndex(int i) {
    int left_index = GetLeftIndex(i);
    int right_index = GetRightIndex(i);

    if (left_index == INT_MAX && right_index == INT_MAX) {
        return INT_MAX;
    } else if (right_index == INT_MAX) {
        return left_index;
    } else {
        return (data_[left_index] > data_[right_index]) ? left_index : right_index;
    }
}

Student StudentMaxHeap::top() {
    if (empty()) {
        return Student("NO_NAME", INT_MIN);
    }
    return data_[0];
}

void StudentMaxHeap::push(const Student& student) {
    data_.push_back(student);
    TrickleUp(data_.size() - 1);
}

bool StudentMaxHeap::pop() {
    if (empty()) {
        return false;
    }
    data_[0] = data_.back();
    data_.pop_back();
    TrickleDown(0);
    return true;
}

void StudentMaxHeap::TrickleUp(int i) {
    while (i > 0 && data_[i] > GetParent(i)) {
        int parent_index = GetParentIndex(i);
        std::swap(data_[i], data_[parent_index]);
        i = parent_index;
    }
}

void StudentMaxHeap::TrickleDown(int i) {
    while (true) {
        int largest_child_index = GetLargestChildIndex(i);
        if (largest_child_index == INT_MAX || data_[i] > data_[largest_child_index]) {
            break;
        }
        std::swap(data_[i], data_[largest_child_index]);
        i = largest_child_index;
    }
}

void StudentMaxHeap::ConvertToHeap(const std::vector<Student>& input) {
    data_ = input;
    for (int i = static_cast<int>(data_.size()) / 2 - 1; i >= 0; --i) {
        TrickleDown(i);
    }
}

void HeapSort(std::vector<Student>& input) {
    StudentMaxHeap maxHeap(input);

    for (int i = static_cast<int>(input.size()) - 1; i >= 0; --i) {
        input[i] = maxHeap.top();
        maxHeap.pop();
    }
}
