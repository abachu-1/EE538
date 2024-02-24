#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
std::vector<int> Flatten3DVector(
    std::vector<std::vector<std::vector<int>>> input) {
        std::vector <int> one_d;
        int i, j, k;

         for (auto i: input) {
            for (auto j:i) {
                for (auto k:j){
                    one_d.push_back(k);

                }
            }
        }

        return one_d;
    }

