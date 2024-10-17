#include "double_linkedlist.h"
#include<iostream>

DoubleLinkedList::DoubleLinkedList(){
    head = NULL;
    tail = NULL;
    currSize = 0;
}

int DoubleLinkedList::size(){
    return currSize;
}

int DoubleLinkedList::getIndex(int index){
    if(index > size() || index <= 0) return INT_MIN;

    node tmp = head;
    for(int i = 1; i < index; i++){
        tmp = tmp->next;
    }
    return tmp->data;
}

void DoubleLinkedList::addFirst(int val){
    node tmp = new Node(val);

    if(head == NULL){
        head = tmp; 
        tail = tmp;
    }

    else {
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
    }

    ++currSize;
}

void DoubleLinkedList::addMiddle(int val, int index){
    if(index <= 0 || index > size() + 1) return;

    else if(index == 1) {
        addFirst(val);
    }

    else if(index == size() + 1){
        addLast(val);
    }

    else {
        node newNode = new Node(val);
        node tmp = head;
        for(int i = 1; i < index - 1; i++){
            tmp = tmp->next;
        } 
        newNode->next = tmp->next;
        tmp->next->prev = newNode;
        newNode->prev = tmp;
        tmp->next = newNode;

        ++currSize;
    }
}

void DoubleLinkedList::addLast(int val){
    node tmp = new Node(val);

    if(head == NULL){
        head = tmp; 
        tail = tmp;
    }

    else {
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
    }
    ++currSize;
}

void DoubleLinkedList::deleteFirst(){
    if(head == NULL) return;

    node tmp = head;

    if(head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    delete tmp;  // Xóa nút đầu tiên
    --currSize;
}

void DoubleLinkedList::deleteLast(){
    if(head == NULL) return;

    node tmp = tail;

    if(head == tail){
        head = NULL;
        tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    delete tmp;  // Xóa nút cuối cùng
    --currSize;
}

void DoubleLinkedList::deleteMiddle(int index){
    if(index <= 0 || index > size()) return;
 
    else if(index == 1){
        deleteFirst();
    }

    else if(index == size()){
        deleteLast();
    }

    else {
        node tmp = head;
        for(int i = 1; i < index; i++){
            tmp = tmp->next;
        }

        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;

        delete tmp;  
        --currSize;
    }
}

void DoubleLinkedList::printFirst(){
    node tmp = head;
    while(tmp != NULL){
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }
}

void DoubleLinkedList::printLast(){
    node tmp = tail;
    while(tmp != NULL){
        std::cout << tmp->data << " ";
        tmp = tmp->prev;
    }
}
