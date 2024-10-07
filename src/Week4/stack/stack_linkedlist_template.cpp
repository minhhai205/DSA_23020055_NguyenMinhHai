#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node *next;

    Node(T new_data) {
        data = new_data;
        next = nullptr;
    }
};
template<typename T>
class Stack {
private:
    Node<T>* head;   
    int currSize;  

public:
    Stack();      
    void push(T val);  
    T pop();          
    T top();          
    bool isEmpty();      
    int size();        
};

template<typename T>
Stack<T>::Stack() {
    head = nullptr;
    currSize = 0;
}

template<typename T>
void Stack<T>::push(T val) {
    Node<T>* tmp = new Node<T>(val);
    tmp->next = head;  
    head = tmp;
    currSize++;
}

template<typename T>
T Stack<T>::pop() {
    if (head == nullptr) {
        cout << "Stack is empty!" << endl;
        return T(); 
    }

    T val = head->data;
    head = head->next;  
    currSize--;

    return val;
}

template<typename T>
T Stack<T>::top() {
    if (head == nullptr) {
        cout << "Stack underflow!" << endl;
        return T();  
    }
    return head->data;
}

template<typename T>
bool Stack<T>::isEmpty() {
    return head == nullptr;
}

template<typename T>
int Stack<T>::size() {
    return currSize;
}

int main() {
    Stack<int> myStack;  
    Stack<double> myDoubleStack;

    return 0;
}
