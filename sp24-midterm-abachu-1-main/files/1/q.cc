#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

using namespace std;

int evaluateExpression(const std::string &expr) {
    int tot_sum = 0;    //declaring tot_sum variable
    string cur_str;

    for (auto it = expr.begin(); it != expr.end(); it++) {
        if (*it == ' ')   //ignoring spaces
            continue;
        else if (*it == '-' || *it == '+') {
            if (!cur_str.empty())
                tot_sum += stoi(cur_str);
            cur_str = *it;
        } else {
            cur_str += *it;
        }
    }
    if (!cur_str.empty())    
        tot_sum += stoi(cur_str);   //for last string element
    return tot_sum;
}
