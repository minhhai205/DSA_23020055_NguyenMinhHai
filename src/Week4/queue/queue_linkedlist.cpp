#include "queue_linkedlist.h"

void Queue::enqueue(int val){ linkedList.insertLast(val); }

int Queue::dequeue(){ int val = linkedList.getIndex(1); linkedList.deleteFirst(); return val; } 

int Queue::front(){ return linkedList.getIndex(1); } 

bool Queue::isEmpty(){ return linkedList.size() == 0; }

int Queue::size(){ return linkedList.size(); }

