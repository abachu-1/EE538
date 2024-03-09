#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
#include<algorithm>

using namespace std;

int findInsertionIndex(const std::vector<int>& sortedVector, int n) {
    for (size_t i = 0; i < sortedVector.size(); ++i) {
        
        if (sortedVector[i] >= n) {
            return i;  //returning i ; ie.; index
        }
    }
    
    return sortedVector.size();
}

MySet::MySet(std::vector<int>& elements) {
    sort(elements.begin(), elements.end());
    for (size_t i = 0; i < elements.size(); ++i) {
        if (i == 0 || elements[i] != elements[i - 1]) {
            elements_.push_back(elements[i]);  //pushing back unique elements to elements_ as setr consists only unique elements
        }
    }
}

MySet::MySet(const MySet& rhs) {
    elements_=rhs.elements_;
}

void MySet::insert(int value) {   
    int ind = findInsertionIndex(elements_, value);  //inserting the value using findInsertionIndex function
    if (ind == elements_.size() || elements_[ind] != value) {
        elements_.insert(elements_.begin() + ind, value);
    }
}

bool MySet::is_in(int item) {
    return std::find(elements_.begin(), elements_.end(), item) != elements_.end();
}

int MySet::size() const {
    return elements_.size();  //returning size
}

vector<int> MySet::ConvertToStdVector() {
    return elements_;
}
