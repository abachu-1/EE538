#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
void UniqueVectorNotBySet(std::vector<int> &input) {
    std::vector <int> temp;
    for (int i: input){
        if(std::find(temp.begin(), temp.end(), i)==temp.end()){
            temp.push_back(i);
        }
    }

    input=temp;


}

void UniqueVectorBySet(std::vector<int> &input) {

    std::set<int> temp_1 (input.begin(), input.end());
    input.assign(temp_1.begin(), temp_1.end());


}

std::vector<int> IntersectVectors(const std::vector<int> &input1, const std::vector<int> &input2) {

    std::vector<int> temp_3;

    for (int i : input1) {

        if (std::find(input2.begin(), input2.end(), i) != input2.end()) {
                temp_3.push_back(i);
            }
    }

    UniqueVectorNotBySet(temp_3);
    return temp_3;
}

std::set<int> DiffVectors(const std::vector<int> &input1, const std::vector<int> &input2){

    std::set<int> set1(input1.begin(), input1.end());
    std::set<int> set2(input2.begin(), input2.end());

    std::set<int> temp_4;
    for (int num : set1) {
        
        if (set2.count(num) == 0) {

            temp_4.insert(num);
        }
    }

    return temp_4;
}


