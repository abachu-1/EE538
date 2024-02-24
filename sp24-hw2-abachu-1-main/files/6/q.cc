#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
bool areDisjoint(const std::set<int> &set1, const std::set<int> &set2){
    for (auto& i : set1){
        if(set2.find(i) != set2.end()) return false;
    }

    return true;
}

std::set<int> setDifference(const std::set<int> &set1, const std::set<int> &set2){

    std::set<int> temp;
    for(const auto& i: set1){
        if(set2.find(i)==set2.end()){
            temp.insert(i);

        }
    }

    return temp;


}


