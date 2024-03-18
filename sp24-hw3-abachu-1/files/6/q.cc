#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
#include<stack>
bool CPPLib::CheckValidExpression(const std::string& input){
  std::stack <char> q;
  for(auto & i : input){
      if(i == '(' || i == '{' || i == '['){
          q.push(i);
        }
      if(( i == ')' || i == '}' || i == ']')  ){
          if(q.empty()) return false;
          if(i == ')' and q.top() == '(') q.pop();
          else if(i == '}' and q.top()== '{') q.pop();
          else if(i== ']' and q.top() == '[') q.pop();
          else return false;
        }
      }
  if(!q.empty()) return false;
  else return true;
  
}
bool CPPLib::IsPalindrome(const std::string& input) {

    std::string str1;
    

    for (int i=input.length()-1; i>=0; i--){
        str1+=input[i];
    }

    if (input == str1) return true;
    else return false;

}

int CPPLib::OddChar(const std::string& input) {

    int out=0;

    for (char c: input){
        out^=c;
    }

    return out;
}

