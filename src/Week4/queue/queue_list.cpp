#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
    Queue(int n);
    void enqueue(int val);  
    int dequeue();          
    int front();           
    bool isEmpty();      
    int size();
private:
    int *a;
    int maxSize;
    int currSize;
};

Queue::Queue(int n){
    a = new int[n];
    maxSize = n;
    currSize = 0;
}

void Queue::enqueue(int val){
    if(currSize >= maxSize){
        cout << "Queue overflow!\n";
        return;
    }

    a[currSize++] = val;
}

int Queue::dequeue(){
    if (currSize == 0) {
        cout << "Queue underflow!" << endl;
        return INT_MIN;
    }

    int val = a[0];
    for(int i=0; i < currSize - 1; i++){
        a[i] = a[i + 1];
    }
    --currSize;

    return val;
}

int Queue::front(){
    if (currSize == 0) {
        cout << "Queue underflow!" << endl;
        return INT_MIN;
    }
    return a[0];
} 
bool Queue::isEmpty(){
    return currSize == 0;
}

int Queue::size(){
    return currSize;
}

int main(){

}