#include "stack_linkedlist.h"
#include <iostream>

void Stack::push(int val) { linkedList.insertFirst(val); }

void Stack::pop() { linkedList.deleteFirst(); }

int Stack::top() { return linkedList.getIndex(1); }

bool Stack::isEmpty() { return linkedList.size() == 0; }

int Stack::size() { return linkedList.size(); }
