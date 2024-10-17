#pragma once
#include "../../Week3/list.h"

class Queue{
public:
    Queue(int n);
    void enqueue(int val);  
    int dequeue();          
    int front();           
    bool isEmpty();      
    int size();
private:
    List list;
};