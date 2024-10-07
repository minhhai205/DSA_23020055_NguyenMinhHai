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

class Queue {
private:
    node head;  
    node tail; 
    int currSize;  

public:
    Queue();
    void enqueue(int val);  
    int dequeue();          
    int front();           
    bool isEmpty();      
    int size();  
};

Queue::Queue(){
    head = NULL;
    tail = NULL;
    currSize = 0;
}

/*
chèn cuối xóa đầu
*/
void Queue::enqueue(int val){
    node tmp = new Node(val);
    if(head == NULL){
        head = tmp; tail = tmp;
    }
    else{
        tail->next = tmp;
        tail = tail->next;
    }
    ++currSize;
}

int Queue::dequeue(){
    if (currSize == 0) {
        cout << "Queue underflow!" << endl;
        return INT_MIN;
    }

    int val = head->data;

    if(currSize == 1){
        head = NULL; tail = NULL;
    }
    else{
        head = head->next;
    }
    --currSize;

    return val;
} 

int Queue::front(){
    if (currSize == 0) {
        cout << "Queue underflow!" << endl;
        return INT_MIN;
    }
    return head->data;
} 

bool Queue::isEmpty(){
    return currSize == 0;
}

int Queue::size(){
    return currSize;
}

int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;  // Output: 10

    q.dequeue();
    cout << "Front element after dequeue: " << q.front() << endl;  // Output: 20

    q.dequeue();
    q.dequeue();

    if (q.isEmpty()) {
        cout << "Queue is empty!" << endl;  // Output: Queue is empty!
    }

    return 0;
}