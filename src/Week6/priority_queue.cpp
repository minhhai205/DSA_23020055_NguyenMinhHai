#include "priority_queue.h"
#include <iostream>

PriorityQueue::PriorityQueue(int n) { heap = MinHeap(n); }

void PriorityQueue::push(int val) { heap.insertKey(val); }

void PriorityQueue::pop() { heap.deleteKey(heap.size() - 1); }

int PriorityQueue::top() { return heap.getMin(); }

int PriorityQueue::size() { return heap.size(); }

bool PriorityQueue::isEmpty() {  return heap.size() == 0; }