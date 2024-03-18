#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
DoubleStack::DoubleStack(){}
void DoubleStack::push(int num){

   if (num %2 ==0) evenVec_.push_back(num);
   else oddVec_.push_back(num);
}

void DoubleStack:: pop(){
   if(evenVec_.size()!=0 && oddVec_.size()!=0){
      if ((evenVec_[evenVec_.size()-1]) >= oddVec_[oddVec_.size()-1]) evenVec_.pop_back();
      else oddVec_.pop_back(); 
   }
   else if (evenVec_.size()!=0 && oddVec_.size()==0) evenVec_.pop_back();

   else if (evenVec_.size()==0 && oddVec_.size()!=0) oddVec_.pop_back();

}


int DoubleStack::top(){

   if (evenVec_.size()!=0 && oddVec_.size()!=0) {
      if ((evenVec_[evenVec_.size()-1]) >= oddVec_[oddVec_.size()-1]) return evenVec_[evenVec_.size()-1];
      if ((evenVec_[evenVec_.size()-1]) < oddVec_[oddVec_.size()-1]) return oddVec_[oddVec_.size()-1];
   }

   else if (evenVec_.size()==0 && oddVec_.size()!=0) return oddVec_[oddVec_.size()-1];

   else if (evenVec_.size()!=0 && oddVec_.size()==0) return evenVec_[evenVec_.size()-1];

   else return -1;

}


int DoubleStack:: size(){
   int total_size;
   total_size = oddVec_.size() + evenVec_.size();
   return total_size;

}

bool DoubleStack::empty(){
   if (evenVec_.size()==0 && oddVec_.size()==0) return true;
   else return false;

}