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

Calculator::Calculator(){

}
Calculator::Calculator(const Calculator &other){
    history=other.history;
}
float Calculator::Calculate(int a, int b, Operation operation){
    float output;
    switch(operation){
        case Operation::kAdd:
            output = a+b;
            break;
        case Operation::kSubtract:
            output=a-b;
            break;
        case Operation::kDivision:
            if (b==0){
                error_code=ErrorCode::kDivisionByZero;
                output=0;
                break;
            }
            else {
                output=static_cast<float>(a) / b;
                break;
            }
        case Operation::kMultiplication:
            output=a*b;
            break;
    }
    error_code=ErrorCode::kNoError;
    history.push_back({a,b,operation, output});
    return output;
}
float Calculator::Calculate(int a, Operation operation){
    int b=0;
    if (!history.empty()) b=history.back().result;
    return Calculate(a, b, operation);
}

CalculationRecord Calculator::History(int index){
    CalculationRecord rec;
    if (index < 0 || index >= history.size()) {
        error_code = ErrorCode::kInvalidIndex;
        rec = {0, 0, Operation::kAdd, 0};
    } else {
        rec = history[history.size() - index - 1];
        error_code = ErrorCode::kNoError;
    }
    return rec;

}
