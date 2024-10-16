#pragma 

class List{
public:
    List(int n);
    int length();
    int getIndex(int index);
    void addFirst(int val);
    void addMiddle(int val, int index);
    void addLast(int val);
    void deleteFirst();
    void deleteLast();
    void deleteMiddle(int index);
    void printFirst();
    void printLast();

private:
    int *a;
    int size;
    int currSize;
};