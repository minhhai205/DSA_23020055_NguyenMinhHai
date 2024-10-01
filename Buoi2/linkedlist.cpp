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


// lay do dai dslk
int size(node a){
    int cnt = 0;
    while(a != NULL){
        ++cnt;
        a = a->next;
    }
    return cnt;
}

// them mot phan tu vao dau dslk
void insertFirst(node &a, int x){
    node tmp = new Node(x);
	tmp->next = a;
	a = tmp;
}

// them mot phan tu vao cuoi dslk
void insertLast(node &a, int x){
    node tmp = new Node(x);
    if(a == NULL) a = tmp;
    else{
        node p = a;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
}

//them mot phan tu vao giua
void insertMiddle(node &a, int x, int pos){
	int n = size(a);
	if(pos <= 0 || pos > n + 1) return;
	if(pos == 1){
		insertFirst(a, x); return;
	}
	node p = a;
	for(int i = 1; i < pos - 1; i++){
		p = p->next;
	}
	
	node tmp = new Node(x);
	tmp->next = p->next;
	p->next = tmp;
}

//xoa phan tu o dau
void deleteFirst(node &a){
    if(a == NULL) return;
    else a = a->next;
}

//xoa phan tu o cuoi
void deleteLast(node &a){
    if(a == NULL) return;
    else if(a->next == NULL) a = NULL;
    else{
        node p = a;
        while(p->next->next != NULL){
            p = p->next;
        }
        p->next = NULL;
    }
}

// xoa phan tu o giua
void deleteMiddle(node &a, int pos){
    if(pos <= 0 || pos > size(a)) return;
	if(pos == 1) {
		a = a->next;
		return;
	}
    node p = a;
    for(int i=1; i<pos-1; i++){
        p = p->next;
    }
    p->next = p->next->next;
}

void printFirst(node a){
	while(a != NULL){
		cout << a->data << " ";
		a = a->next;
	}
}

void printLast(node a){
	if( a == NULL) return;
	printLast(a->next);
	cout << a->data << " ";
}

int main() {
    node a = nullptr; // Khởi tạo danh sách liên kết rỗng

    // Thêm phần tử vào đầu danh sách
    insertFirst(a, 10);   // Danh sách: 10
    insertFirst(a, 5);    // Danh sách: 5 10

    // Thêm phần tử vào cuối danh sách
    insertLast(a, 20);    // Danh sách: 5 10 20
    insertLast(a, 25);    // Danh sách: 5 10 20 25

    // Thêm phần tử vào vị trí giữa
    insertMiddle(a, 15, 3);  // Danh sách: 5 10 15 20 25
    insertMiddle(a, 30, 6);  // Danh sách: 5 10 15 20 25 30

    // In danh sách từ đầu đến cuối
    cout << "Danh sách từ đầu: ";
    printFirst(a);
    cout << endl;

    // In danh sách từ cuối lên đầu
    cout << "Danh sách từ cuối: ";
    printLast(a);
    cout << endl;

    // Xóa phần tử đầu tiên
    deleteFirst(a);  // Danh sách: 10 15 20 25 30
    cout << "Sau khi xóa phần tử đầu tiên: ";
    printFirst(a);
    cout << endl;

    // Xóa phần tử cuối cùng
    deleteLast(a);   // Danh sách: 10 15 20 25
    cout << "Sau khi xóa phần tử cuối cùng: ";
    printFirst(a);
    cout << endl;

    // Xóa phần tử ở vị trí giữa (vị trí 2)
    deleteMiddle(a, 2);  // Danh sách: 10 20 25
    cout << "Sau khi xóa phần tử ở vị trí giữa: ";
    printFirst(a);
    cout << endl;

    return 0;
}
