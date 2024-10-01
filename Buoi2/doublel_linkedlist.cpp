#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

typedef class Node* node;

class DoubleLinkedList{
private:
    node head;
    node tail;

public:
    DoubleLinkedList();
    int size();
    int getIndex(int index);
    void addFirst(int val);
    void addMiddle(int val, int index);
    void addLast(int val);
    void deleteFirst();
    void deleteLast();
    void deleteMiddle(int index);
    void printFirst();
    void printLast();
};

DoubleLinkedList::DoubleLinkedList(){
    head = NULL;
    tail = NULL;
}

int DoubleLinkedList::size(){
    int count = 0;
    node temp = head;
    while(temp != NULL){
        ++count;
        temp = temp->next;
    }
    return count;
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
        return;
    }

    tmp->next = head;
    head->prev = tmp;
    head = tmp;
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
}

void DoubleLinkedList::addLast(int val){
    node tmp = new Node(val);

    if(head == NULL){
        head = tmp; 
        tail = tmp;
        return;
    }

    tmp->prev = tail;
    tail->next = tmp;
    tail = tmp;
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
}

void DoubleLinkedList::deleteMiddle(int index){
    if(index <= 0 || index > size()) return;
    
    if(head == tail){
        delete head;
        head = NULL; 
        tail = NULL; 
        return;
    }
    
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
}

void DoubleLinkedList::printFirst(){
    node tmp = head;
    while(tmp != NULL){
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
}

void DoubleLinkedList::printLast(){
    node tmp = tail;
    while(tmp != NULL){
        cout << tmp->data << " ";
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
    cout << "Danh sách từ đầu: ";
    dll.printFirst();
    cout << endl;

    // In danh sách từ cuối về đầu
    cout << "Danh sách từ cuối: ";
    dll.printLast();
    cout << endl;

    // Xóa phần tử đầu tiên
    dll.deleteFirst();  // Danh sách: 10 15 20 25 30
    cout << "Sau khi xóa phần tử đầu tiên: ";
    dll.printFirst();
    cout << endl;

    // Xóa phần tử cuối cùng
    dll.deleteLast();   // Danh sách: 10 15 20 25
    cout << "Sau khi xóa phần tử cuối cùng: ";
    dll.printFirst();
    cout << endl;

    // Xóa phần tử ở vị trí giữa (vị trí 2)
    dll.deleteMiddle(2);  // Danh sách: 10 20 25
    cout << "Sau khi xóa phần tử ở vị trí giữa: ";
    dll.printFirst();
    cout << endl;
    return 0;
}
