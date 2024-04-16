#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
Queue::Queue(const Queue& rhs) {
    v_=rhs.v_;

    
}

Queue& Queue::operator=(const Queue& rhs){
    v_=rhs.v_;
    return *this;
}

Queue Queue::operator+(const Queue& rhs) {

    Queue x;
    for (auto &i:rhs.v_) (x.v_).push_back(i);
    for (auto &i:v_) (x.v_).push_back(i);

    return x;

}

bool Queue:: Enqueue(int value){
    v_.push_back(value);
    return true;
}

bool Queue:: Dequeue(){
    if (v_.size()!= 0){
        v_.erase(v_.begin());
        return true;
    }
   else return false;
}

bool Queue:: IsEmpty(){
    if (v_.size()==0) return true;
    else return false;
}

int Queue::Front(){
    if (v_.size()!=0) return v_[0];
    else return -1;
}
