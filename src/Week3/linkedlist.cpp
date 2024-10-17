#include "linkedlist.h"
#include<iostream>

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    currSize = 0;
}

int LinkedList::size(){
    return currSize;
}

int LinkedList::getIndex(int index){
    if(index > size() || index <= 0) return INT_MIN;

    node tmp = head;
    for(int i = 1; i < index; i++){
        tmp = tmp->next;
    }
    return tmp->data;
}

void LinkedList::insertFirst(int val){
    node tmp = new Node(val);
	tmp->next = head;
	head = tmp;
    ++currSize;

    if(head->next == NULL) tail = head;
}


void LinkedList::insertLast(int val){
    node tmp = new Node(val);
    if(head == nullptr){
        head = tmp; tail = tmp;
    }
    else{
        tail->next = tmp;
        tail = tail->next;
    }
    ++currSize;
}


void LinkedList::insertMiddle(int val, int index){
    int n = size();
	if(index <= 0 || index > n + 1) return;

	else if(index == 1){ 
        insertFirst(val); 
    }

    else if(index == n + 1){
        insertLast(val); 
    }

	else{
        node p = head;
        for(int i = 1; i < index - 1; i++){
            p = p->next;
        }
        
        node tmp = new Node(val);
        tmp->next = p->next;
        p->next = tmp;
        ++currSize;
    }
}


void LinkedList::deleteFirst(){
    if(head == NULL) return;
    head = head->next;
    --currSize;
}


void LinkedList::deleteLast(){
    if(head == NULL) return;
    else if(head->next == NULL) head = NULL;
    else{
        node p = head;
        while(p->next->next != NULL){
            p = p->next;
        }
        tail = p;
        p->next = NULL;
    }
    --currSize;
}


void LinkedList::deleteMiddle(int index){
    int n = size();
    if(index <= 0 || index > n) return;
	else if(index == 1) {
		deleteFirst();
	}
    else if(index == n){
        deleteLast();
    }
    else{
        node p = head;
        for(int i=1; i<index-1; i++){
            p = p->next;
        }
        p->next = p->next->next;
        --currSize;
    }
}

void LinkedList::printFirst(){
    node tmp = head;
	while(tmp != NULL){
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
}

void printLastHelper(node tmp) {
    if (tmp == NULL) return;
    printLastHelper(tmp->next);  
    std::cout << tmp->data << " ";    
}

void LinkedList::printLast(){
    printLastHelper(head);
}
