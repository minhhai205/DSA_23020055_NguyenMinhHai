#include "linkedlist.h"
#include<iostream>

LinkedList::LinkedList(){
    head = NULL;
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
}


void LinkedList::insertLast(int val){
    node tmp = new Node(val);
    if(head == NULL) head = tmp;
    else{
        node p = head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
    ++currSize;
}


void LinkedList::insertMiddle(int val, int index){
	if(index <= 0 || index > size() + 1) return;
	if(index == 1){
		insertFirst(val); return;
	}
	node p = head;
	for(int i = 1; i < index - 1; i++){
		p = p->next;
	}
	
	node tmp = new Node(val);
	tmp->next = p->next;
	p->next = tmp;
    ++currSize;
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
        p->next = NULL;
    }
    --currSize;
}


void LinkedList::deleteMiddle(int index){
    if(index <= 0 || index > size()) return;
	else if(index == 1) {
		head = head->next;
	}
    else{
        node p = head;
        for(int i=1; i<index-1; i++){
            p = p->next;
        }
        p->next = p->next->next;
    }
    --currSize;
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

int main() {
    // Tạo danh sách liên kết đơn
    LinkedList list;

    // Thêm phần tử vào đầu danh sách
    list.insertFirst(10);  // Danh sách: 10
    list.insertFirst(5);   // Danh sách: 5 10

    // Thêm phần tử vào cuối danh sách
    list.insertLast(20);   // Danh sách: 5 10 20
    list.insertLast(25);   // Danh sách: 5 10 20 25

    // Thêm phần tử vào vị trí giữa
    list.insertMiddle(15, 3); // Danh sách: 5 10 15 20 25
    list.insertMiddle(30, 6); // Danh sách: 5 10 15 20 25 30

    // In danh sách từ đầu đến cuối
    std::cout << "Danh sách từ đầu: ";
    list.printFirst();
    std::cout << std::endl;

    // Xóa phần tử đầu tiên
    list.deleteFirst();  // Danh sách: 10 15 20 25 30
    std::cout << "Sau khi xóa phần tử đầu tiên: ";
    list.printFirst();
    std::cout << std::endl;

    // Xóa phần tử cuối cùng
    list.deleteLast();   // Danh sách: 10 15 20 25
    std::cout << "Sau khi xóa phần tử cuối cùng: ";
    list.printFirst();
    std::cout << std::endl;

    // Xóa phần tử ở vị trí giữa (vị trí 2)
    list.deleteMiddle(2);  // Danh sách: 10 20 25
    std::cout << "Sau khi xóa phần tử ở vị trí giữa: ";
    list.printFirst();
    std::cout << std::endl;

    return 0;
}