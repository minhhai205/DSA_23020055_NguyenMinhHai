#pragma once
#include "../../Week3/list.h"

class Stack {
public:
    Stack(int n){}
    void push(int val);  
    void pop();          
    int top();           
    bool isEmpty();      
    int size();          
private:
    List list;
};