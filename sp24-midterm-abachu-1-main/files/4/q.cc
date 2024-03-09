
#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

MyVector::MyVector(){   
    size_=0;
    data_=nullptr;
    error_=ErrorCode::kNoError;
}

MyVector::MyVector(int size) {
    size_=size;
    data_=new int[size_];
    error_=ErrorCode::kNoError;
    for (int i = 0; i < size_; i++) {    //initializing vector elements to zero
        data_[i] = 0;
    }

}

MyVector::MyVector(const MyVector& rhs){
    size_=rhs.size_;
    data_=new int[size_];
    error_=rhs.error_;

    for (int i=0; i<size_; i++){
        data_[i]=rhs.data_[i];
    }

}
MyVector:: ~MyVector(){
    delete[] data_;
    data_=nullptr;
    size_=0;
    error_=ErrorCode::kNoError;

}

void MyVector::push_back(int value) {

    int* new_array= new int [size_+1];

    for (int i=0; i<size_; i++){
        new_array[i]=data_[i];
    }
    
    new_array[size_]=value;   //adding new value
    delete[] data_;
    data_=new_array;
    size_++;  //incrementing the size of new array
    error_=ErrorCode::kNoError;
}

int MyVector::pop_back(){
    int x=0;
    if (size_==0) {
        error_=ErrorCode::kPopFromEmptyVector;
        return -1; 
    }
    int* new_array= new int [size_-1];
        for (int i=0; i<size_-1; i++){
        new_array[i]=data_[i];
    }
    x= data_[size_-1];   //returning the last value
    delete[] data_;
    data_=new_array;
    size_--;  //decrementing the size
    error_=ErrorCode::kNoError;
    return x;
}


void MyVector::push_front(int value){
    int* new_array= new int [size_+1];
    new_array[0]=value;    //pushing the value at index 0
    for (int i=0; i<size_; i++) {
        new_array[i+1]=data_[i];
    }

    delete[] data_;
    data_=new_array;
    size_++;

}

int MyVector::pop_front(){
    int x=0;
    if (size_==0) {
        error_=ErrorCode::kPopFromEmptyVector;
        return -1; 
    }   

    int* new_array= new int [size_-1];
    for (int i=1; i<size_;i++){
        new_array[i-1]=data_[i];
    }
    
    x= data_[0];    //returning the 0th index valued element in the array
    delete[] data_;
    data_=new_array;
    size_--;
    return x; 

}

void MyVector::insert(int value, int index){
    if ((index < -1 || index >=size_)){   //if index is out of bound
        error_=ErrorCode::kIndexError;
        return;
    }
    int* new_array= new int [size_+1];
    if (index == -1){    
        new_array[0]=value;
        for (int i=0; i<size_;i++){
            new_array[i+1]=data_[i];
        }
        error_=ErrorCode::kNoError;
    }
    else {

        for (int i=0; i<=index;i++){  //inserting value at given index
            new_array[i]=data_[i];
        }

        new_array[index+1]=value;

        for (int i=index+1; i<size_;i++){
            new_array[i+1]=data_[i];
        }
        error_=ErrorCode::kNoError;
    }

    delete[] data_;
    data_=new_array;
    size_++;
    

}

int MyVector::at(int index) {    
    if (index>=size_||index<0){
        error_=ErrorCode::kIndexError;
        return -1;
    }
    else {
        error_=ErrorCode::kNoError;
        return data_[index];   //retuning the value at given index
    }

}

int MyVector::find(int item){
    for (int i=0; i<size_;i++) {
        if (data_[i]==item) {
            error_=ErrorCode::kNoError;
            return i;   //returning the index of givren elemnent
        }

    }
    error_=ErrorCode::kNotFound;
    return -1;
}


ErrorCode MyVector::get_error() const{
    return error_;
}

int MyVector::size() const{
    return size_;
    
}

std::vector<int> MyVector::ConvertToStdVector(){
    std::vector <int> temp;
    for (int i=0; i<size_;i++){
        temp.push_back(data_[i]);   //pushing back elements to std::vector 
    }
    error_=ErrorCode::kNoError;
    return temp;

}
