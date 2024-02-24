#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
std::map<char, int> CountCharacters(std::string& input) {
    std::map <char, int> letter;
    for (auto i: input){
        letter[i]+=1;
    }
    return letter;
}
