#pragma once
#include "../../Week3/linkedlist.h"

class Queue{
public:
    Queue(int n);
    void enqueue(int val);  
    int dequeue();          
    int front();           
    bool isEmpty();      
    int size();
private:
    LinkedList linkedList;
};