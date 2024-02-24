#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
bool IsPrime(int number) {
    if(number<2){
        return false;
    }
    else {
        
        for (int i=2; i<number; i++) {
            if (number %i == 0) {
                return false;
    }

    }
    }

return true;

}
