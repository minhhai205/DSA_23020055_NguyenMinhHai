#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;

	Node(int new_data) {
        data = new_data;
        next = nullptr; 
    }
};
typedef struct Node* node;

class LinkedList{
public:
    node head;
public:
    LinkedList();
    int size();
    int getIndex(int index);
    void insertFirst(int val);
    void insertLast(int val);
    void insertMiddle(int val, int index);
    void deleteFirst();
    void deleteLast();
    void deleteMiddle(int index);
    void printFirst();
    void printLast();
};

LinkedList::LinkedList(){
    head = NULL;
}

int LinkedList::size(){
    int cnt = 0;
    node tmp = head;
    while(tmp != NULL){
        ++cnt;
        tmp = tmp->next;
    }
    return cnt;
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
}


void LinkedList::deleteFirst(){
    if(head == NULL) return;
    else head = head->next;
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
}


void LinkedList::deleteMiddle(int index){
    if(index <= 0 || index > size()) return;
	if(index == 1) {
		head = head->next;
		return;
	}
    node p = head;
    for(int i=1; i<index-1; i++){
        p = p->next;
    }
    p->next = p->next->next;
}

void LinkedList::printFirst(){
    node tmp = head;
	while(tmp != NULL){
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
}

void printLastHelper(node tmp) {
    if (tmp == NULL) return;
    printLastHelper(tmp->next);  
    cout << tmp->data << " ";    
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
    cout << "Danh sách từ đầu: ";
    list.printFirst();
    cout << endl;

    // Xóa phần tử đầu tiên
    list.deleteFirst();  // Danh sách: 10 15 20 25 30
    cout << "Sau khi xóa phần tử đầu tiên: ";
    list.printFirst();
    cout << endl;

    // Xóa phần tử cuối cùng
    list.deleteLast();   // Danh sách: 10 15 20 25
    cout << "Sau khi xóa phần tử cuối cùng: ";
    list.printFirst();
    cout << endl;

    // Xóa phần tử ở vị trí giữa (vị trí 2)
    list.deleteMiddle(2);  // Danh sách: 10 20 25
    cout << "Sau khi xóa phần tử ở vị trí giữa: ";
    list.printFirst();
    cout << endl;

    return 0;
}