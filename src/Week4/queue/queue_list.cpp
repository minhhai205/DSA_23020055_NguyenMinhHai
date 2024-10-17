#include "queue_list.h"

Queue::Queue(int n){ list = List(n); }

void Queue::enqueue(int val){ list.addLast(val); }

int Queue::dequeue(){  int val = list.getIndex(0); list.deleteFirst(); return val; }

int Queue::front(){ return list.getIndex(0); } 

bool Queue::isEmpty(){ return list.length() == 0; }

int Queue::size(){ return list.length(); }

