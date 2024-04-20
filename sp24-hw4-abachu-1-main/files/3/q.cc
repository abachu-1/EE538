#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
std::vector<int> ProductOfKHighestNumbers(const std::vector<int> &input, int k) {
    std::vector<int> result;

    if (input.empty() || k <= 0 || k > static_cast<int>(input.size())) {
        return result; 
    }

    std::vector<int> sortedInput = input;
    std::sort(sortedInput.begin(), sortedInput.end(), std::greater<int>());
    int product = 1;
    for (int i = 0; i < k; ++i) {
        product *= sortedInput[i];
    }
    result.push_back(product);

    return result;
}

