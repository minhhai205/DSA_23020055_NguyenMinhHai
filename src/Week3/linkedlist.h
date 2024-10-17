#pragma 

struct Node{
    int data;
    Node *next;

	Node(int new_data) {
        data = new_data;
        next = nullptr; 
    }
};
typedef struct Node* node;

class LinkedList{
private:
    node head, tail; // tail de luu node cuoi cung de insertLast voi O(1)
    int currSize;
public:
    LinkedList();
    int size();
    int getIndex(int index);
    void insertFirst(int val);
    void insertLast(int val);
    void insertMiddle(int val, int index);
    void deleteFirst();
    void deleteLast();
    void deleteMiddle(int index);
    void printFirst();
    void printLast();
};