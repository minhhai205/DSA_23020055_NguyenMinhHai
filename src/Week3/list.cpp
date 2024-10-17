#include "list.h"
#include<iostream>
#include <limits.h>

int List::length(){
    return currSize;
}

List::List(int n){
    a = new int[n];
    size = n;
    currSize = 0;
}

int List::getIndex(int index){
    if(currSize <= 0 || index >= currSize) return INT_MIN;
    return *(a + index);
}

void List::addFirst(int val){
    if(currSize >= size) return;
    for(int i=0; i<currSize; i++){
        *(a + i + 1) = *(a + i);
    }
    *a = val;
    currSize++;
}

void List::addLast(int val){
    if(currSize >= size) return;
    *(a + currSize) = val;
    currSize++;
}

void List::addMiddle(int val, int index){
    if(currSize >= size) return;
    for(int i=index; i<currSize; i++){
        *(a + i + 1) = *(a + i);
    }
    *(a + index) = val;
    ++currSize;
}

void List::deleteFirst(){
    for(int i=0; i < currSize - 1; i++){
        *(a + i) = *(a + i + 1);
    }
    --currSize;
}

void List::deleteLast(){
    --currSize;
}

void List::deleteMiddle(int index){
    for(int i=index; i<currSize-1; i++){
        *(a + i) = *(a + i + 1);
    }
    --currSize;
}

void List::printFirst(){
    for(int i=0; i<currSize; i++){
        std::cout << *(a + i) << " ";
    } 
}

void List::printLast(){
    for(int i = currSize - 1; i>=0; i--){
        std::cout << *(a + i) << " ";
    }
}
