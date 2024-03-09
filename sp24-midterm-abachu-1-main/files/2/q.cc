#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
using namespace std;
Node::Node(int val) {
    value = val;
    next = nullptr;
}
LinkedList::LinkedList(){
    head=nullptr;       
    tail=nullptr;

}
LinkedList::~LinkedList(){
    Node* temp=head;
    while (temp!=nullptr){
        Node* next= temp->next;   //deleting each and every node
        delete temp;
        temp=next;
    }

}
void LinkedList::push_back(int value){
    Node* temp = new Node(value);
    if (head==nullptr) 
    {
        head=temp; 
        tail=temp; 
    }
    else {
        tail->next=temp;    //updating tail pointer
        tail=temp;
    }
}

int LinkedList::back() {
    if (head==nullptr) {return -1;}
    else {
        return tail->value;        //returning tail value
    }
}
int LinkedList::front() {
    if (head==nullptr) {return -1;}
    else {
        return head->value;   //returning head value
    }
}

void LinkedList::pop_back() {
    Node* temp= head;
    if (head==nullptr){ return;}
    else if (head==tail){
        delete head;
        head=nullptr;
        tail=nullptr;
    }
    else {
        Node *temp=head;
        while (temp->next != tail){    //iterating till the last before element
            temp=temp->next;
        }
        delete tail;   //deleting the tail node
        tail=temp;
        tail->next=nullptr;
    }
}
