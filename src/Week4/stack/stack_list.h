#include "list.h"

class Stack {
public:
    Stack(int n);
    void push(int val);  
    int pop();          
    int top();           
    bool isEmpty();      
    int size();          
private:
    List list;
};