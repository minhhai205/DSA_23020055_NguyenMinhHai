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

    if(index == 1) {
        addFirst(val); return;
    }

    if(index == size() + 1){
        addLast(val); return;
    }

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
 
    if(index == 1){
        deleteFirst();
        return;
    }

    if(index == size()){
        deleteLast();
        return;
    }

    node tmp = head;
    for(int i = 1; i < index; i++){
        tmp = tmp->next;
    }

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;

    delete tmp;  
    --currSize;
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


int main() {
    // Tạo danh sách liên kết đôi
    DoubleLinkedList dll;

    // Thêm phần tử vào đầu danh sách
    dll.addFirst(10);    // Danh sách: 10
    dll.addFirst(5);     // Danh sách: 5 10

    // Thêm phần tử vào cuối danh sách
    dll.addLast(20);     // Danh sách: 5 10 20
    dll.addLast(25);     // Danh sách: 5 10 20 25

    // Thêm phần tử vào vị trí giữa
    dll.addMiddle(15, 3);  // Danh sách: 5 10 15 20 25
    dll.addMiddle(30, 6);  // Danh sách: 5 10 15 20 25 30

    // In danh sách từ đầu đến cuối
    std::cout << "Danh sách từ đầu: ";
    dll.printFirst();
    std::cout << std::endl;

    // In danh sách từ cuối về đầu
    std::cout << "Danh sách từ cuối: ";
    dll.printLast();
    std::cout << std::endl;

    // Xóa phần tử đầu tiên
    dll.deleteFirst();  // Danh sách: 10 15 20 25 30
    std::cout << "Sau khi xóa phần tử đầu tiên: ";
    dll.printFirst();
    std::cout << std::endl;

    // Xóa phần tử cuối cùng
    dll.deleteLast();   // Danh sách: 10 15 20 25
    std::cout << "Sau khi xóa phần tử cuối cùng: ";
    dll.printFirst();
    std::cout << std::endl;

    // Xóa phần tử ở vị trí giữa (vị trí 2)
    dll.deleteMiddle(2);  // Danh sách: 10 20 25
    std::cout << "Sau khi xóa phần tử ở vị trí giữa: ";
    dll.printFirst();
    std::cout << std::endl;
    return 0;
}
