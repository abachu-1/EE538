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
void push_back(int *&array, int &size, int element) {
    int* newarray = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newarray[i] = array[i];
    }

    newarray[size] = element;
    size++;
    delete[] array;
    array = newarray;
}

void pop_back(int *&array, int &size) {
    if (size == 0) {
        return; // Nothing to pop
    }

    int* newarray = new int[size - 1];
    for (int i = 0; i < size - 1; i++) {
        newarray[i] = array[i];
    }
    size--;
    delete[] array;
    array = (size > 0) ? newarray : nullptr;
}

void insert(int *&array, int &size, int element, int index) {
    if (index < 0 || index > size) {
        return;
    } else if (index == size) {
        push_back(array, size, element);
    } else {
        int* newarray = new int[size + 1];
        for (int i = 0; i < index; i++) {
            newarray[i] = array[i];
        }

        newarray[index] = element;

        for (int j = index; j < size; j++) {
            newarray[j + 1] = array[j];
        }

        size++;

        delete[] array;
        array = newarray;
    }
}

int erase(int *&array, int &size, int index) {
    if (index < 0 || index >= size) {
        return -1;
    } else if (index == size - 1) {
        pop_back(array, size);
        return 0;
    } else {
        int* newarray = new int[size - 1];
        for (int i = 0; i < index; i++) {
            newarray[i] = array[i];
        }
        for (int j = index + 1; j < size; j++) {
            newarray[j - 1] = array[j];
        }
        size--;
        delete[] array;
        array = newarray;
        return 0;
    }
}

int find(const int *array, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;
}
