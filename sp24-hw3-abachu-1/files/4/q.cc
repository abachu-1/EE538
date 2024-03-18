#include "q.h"
#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <unordered_set>

SinglyLinkedList::SinglyLinkedList(const std::vector<int> &v) {
    size_ = 0;
    head_ = nullptr;

    for (int i : v) {
        push_back(i);
    }
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList &rhs) {
    size_ = 0;
    head_ = nullptr;
    ListNode *current_node = rhs.head_;

    while (current_node != nullptr) {
        push_back(current_node->val);
        current_node = current_node->next;
    }
}

SinglyLinkedList::~SinglyLinkedList() {
    while (!empty()) {
        pop_back();
    }
}

bool SinglyLinkedList::empty() {
    return size_ == 0;
}

int SinglyLinkedList::size() {
    return size_;
}

ListNode *SinglyLinkedList::head() {
    return head_;
}

void SinglyLinkedList::push_back(int i) {
    ListNode *newnode = new ListNode(i);

    if (empty()) {
        head_ = newnode;
    } 

    else {
        ListNode *current_node = head_;

        while (current_node->next != nullptr) {
            current_node = current_node->next;
        }

        current_node->next = newnode;
    }

    size_++;
}

bool SinglyLinkedList::pop_back() {
    if (empty()) {
        return false;
    }

    if (size_ == 1) {
        delete head_;
        head_ = nullptr;
    } 
    
    else {
        ListNode *current_node = head_;
        ListNode *previous_node = nullptr;

        while (current_node->next != nullptr) {
            previous_node = current_node;
            current_node = current_node->next;
        }

        delete current_node;
        previous_node->next = nullptr;
    }

    size_--;
    return true;
}

int SinglyLinkedList::back() {
    if (empty()) {
        return -1;
    } 
    
    else {
        ListNode *current_node = head_;

        while (current_node->next != nullptr) {
            current_node = current_node->next;
        }

        return current_node->val;
    }
}

ListNode *SinglyLinkedList::GetBackPointer() {
    if (empty()) {
        return nullptr;
    }

    ListNode *current_node = head_;
    while (current_node->next != nullptr) {
        current_node = current_node->next;
    }

    return current_node;
}

ListNode *SinglyLinkedList::GetIthPointer(int i) {
    if (i < 0 || i >= size_) {
        return nullptr;
    }

    ListNode *current_node = head_;

    for (int j = 0; j < i; j++) {
        current_node = current_node->next;
    }

    return current_node;
}

int &SinglyLinkedList::operator[](int i) {
    int x = -1;

    ListNode *node = GetIthPointer(i);
    if (node == nullptr)
        return x;
    else
        return node->val;
}

void SinglyLinkedList::print() {
    ListNode *current_node = head_;
    while (current_node != nullptr) {
        std::cout << current_node->val << " ";
        current_node = current_node->next;
    }
    std::cout << std::endl;
}

std::vector<int> SinglyLinkedList::convert_to_vector() {
    std::vector<int> x;
    ListNode *current_node = head_;
    while (current_node != nullptr) {
        x.push_back(current_node->val);
        current_node = current_node->next;
    }

    return x;
}

ListNode *SinglyLinkedList::erase(int i) {
    if (i < 0 || i >= size_) {
        return nullptr;
    }

    ListNode *current_node = head_;
    ListNode *previous_node = nullptr;

    for (int j = 0; j < i; j++) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (previous_node != nullptr) {
        previous_node->next = current_node->next;
    } 
    
    else {
        head_ = current_node->next;
    }
    delete current_node;
    size_--;
    return previous_node;
}

ListNode *SinglyLinkedList::erase(ListNode *p) {
    if (p == nullptr) return nullptr;

    ListNode *current_node = head_;
    ListNode *previous_node = nullptr;

    while (current_node != p && current_node != nullptr) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == nullptr) return nullptr;
    if (previous_node != nullptr) previous_node->next = current_node->next;
    else head_ = current_node->next;

    delete current_node;
    size_--;
    return previous_node;
}

ListNode *SinglyLinkedList::GetPrevious(ListNode *p) {
    if (p == head_ || p == nullptr) return nullptr;

    ListNode *current_node = head_;
    ListNode *previous_node = nullptr;

    while (current_node != p && current_node != nullptr) {
        previous_node = current_node;
        current_node = current_node->next;
    }

    return previous_node;
}

void SinglyLinkedList::remove_duplicates() {
    std::unordered_set<int> x;
    ListNode *current_node = head_;
    ListNode *previous_node = nullptr;

    while (current_node != nullptr) {
        if (x.find(current_node->val) != x.end()) {
            previous_node->next = current_node->next;
            delete current_node;
            current_node = previous_node->next;
        } else {
            x.insert(current_node->val);
            previous_node = current_node;
            current_node = current_node->next;
        }
    }
}

void SinglyLinkedList::reverse() {
    ListNode *current_node = head_;
    ListNode *previous_node = nullptr, *next = nullptr;

    while (current_node != nullptr) {
        next = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next;
    }

    head_ = previous_node;
}
