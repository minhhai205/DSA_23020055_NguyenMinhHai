#include<bits/stdc++.h>
using namespace std;

class Stack {
public:
    Stack(int n);
    void push(int val);  
    void pop();          
    int top();           
    bool isEmpty();      
    int size();          
private:
    int *a;
    int maxSize;
    int currSize;
};


Stack::Stack(int n) {
    a = new int[n];
    maxSize = n;
    currSize = 0;
}

void Stack::push(int val) {
    if (currSize >= maxSize) {
        cout << "Stack overflow!" << endl;
        return;
    }
    a[currSize] = val;
    currSize++;
}

void Stack::pop() {
    if (currSize == 0) {
        cout << "Stack underflow!" << endl;
        return;
    }
    currSize--;
}

int Stack::top() {
    if (currSize == 0) {
        cout << "Stack is empty!" << endl;
        return INT_MIN;
    }
    return a[currSize - 1];
}

bool Stack::isEmpty() {
    return currSize == 0;
}

int Stack::size() {
    return currSize;
}

int main(){
    
}
