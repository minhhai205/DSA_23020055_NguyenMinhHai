#include "stack_list.h"
#include <iostream>
#include <climits>

Stack::Stack(int n) { list = List(n); }

void Stack::push(int val) { list.addLast(val); }

void Stack::pop() { list.deleteLast(); }

int Stack::top() { return list.getIndex(list.length() - 1); }

bool Stack::isEmpty() { return list.length() == 0; }

int Stack::size() { return list.length(); }

