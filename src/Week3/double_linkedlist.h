#pragma 

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

typedef class Node* node;

class DoubleLinkedList{
private:
    node head;
    node tail;
    int currSize;
public:
    DoubleLinkedList();
    int size();
    int getIndex(int index);
    void addFirst(int val);
    void addMiddle(int val, int index);
    void addLast(int val);
    void deleteFirst();
    void deleteLast();
    void deleteMiddle(int index);
    void printFirst();
    void printLast();
};
