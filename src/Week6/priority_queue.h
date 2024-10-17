#pragma once
#include "min_heap.h"

class PriorityQueue {
private:
    MinHeap heap;
public:
    PriorityQueue(int n);
    PriorityQueue() {}
    void push(int val);  
    void pop();          
    int top();           
    bool isEmpty();      
    int size();  
};