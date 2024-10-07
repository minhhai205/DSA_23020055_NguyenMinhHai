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

class Stack {
private:
    node head;   
    int currSize;  

public:
    Stack();      
    void push(int val);  
    void pop();          
    int top();          
    bool isEmpty();      
    int size();        
};

Stack::Stack() {
    head = nullptr;
    currSize = 0;
}

void Stack::push(int val) {
    node tmp = new Node(val);
    tmp->next = head;  
    head = tmp;
    currSize++;
}

int Stack::pop() {
    if (head == nullptr) {
        cout << "Stack is empty!" << endl;
        return INT_MIN;
    }

    int val = head->data;
    head = head->next;  
    currSize--;

    return val;
}

int Stack::top() {
    if (head == nullptr) {
        cout << "Stack underflow!" << endl;
        return INT_MIN;
    }
    return head->data;
}

bool Stack::isEmpty() {
    return head == nullptr;
}

int Stack::size() {
    return currSize;
}

int main() {
    Stack myStack;

    // Thêm phần tử vào stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    cout << "Top của stack: " << myStack.top() << endl;  // Top: 30

    // Xóa phần tử ở đỉnh stack
    myStack.pop();
    cout << "Top của stack sau khi pop: " << myStack.top() << endl;  // Top: 20

    // Kiểm tra stack có rỗng không
    if (myStack.isEmpty()) {
        cout << "Stack rỗng!" << endl;
    } else {
        cout << "Stack không rỗng!" << endl;
    }

    // In kích thước hiện tại của stack
    cout << "Kích thước của stack: " << myStack.size() << endl;  // Kích thước: 2

    // Xóa phần tử còn lại và kiểm tra
    myStack.pop();
    myStack.pop();
    cout << "Kích thước của stack sau khi pop: " << myStack.size() << endl;  // Kích thước: 0

    return 0;
}
