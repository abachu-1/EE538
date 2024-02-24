#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.

// 2. Write some unit tests for them in student_test.cc
std::vector<int> Reverse(std::vector<int> input) {
// std::vector<int> revarray{};
int left=0;
int right=(input.size())-1;
int temp;
while (left < right){
    temp=input[left];
    input[left]=input[right];
    input[right]=temp;
    left++;
    right--;    
}

return input;
}

std::vector<int> PlusOne(std::vector<int> input) {

    int digits=input.size()-1;
    if(input.size()==0) return {};

    while (digits>=0 && input[digits]==9 ){
        input[digits]=0;
        digits--;


    }
    

    if (digits<0){
        input.insert(input.begin(), 1);
    }

    else {
        input[digits]=input[digits]+1;
        digits--;
    }


return input;
}
