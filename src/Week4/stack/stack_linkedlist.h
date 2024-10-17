#pragma once
#include "../../Week3/linkedlist.h"

class Stack {
public:
    Stack(){}
    void push(int val);  
    void pop();          
    int top();           
    bool isEmpty();      
    int size();          
private:
    LinkedList linkedList;
};