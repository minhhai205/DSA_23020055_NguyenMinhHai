#include<bits/stdc++.h>

using namespace std;


class List{
public:
    List(int n);
    int getIndex(int index);
    void addFirst(int val);
    void addMiddle(int val, int index);
    void addLast(int val);
    void deleteFirst();
    void deleteLast();
    void deleteMiddle(int index);

private:
    int *a;
    int size;
    int currSize;
};

List::List(int n){
    a = new int[n];
    size = n;
    currSize = 0;
}

int List::getIndex(int index){
    return *(a + index);
}

void List::addFirst(int val){
    if(currSize < size){
        for(int i=0; i<currSize; i++){
            *(a + i + 1) = *(a + i);
        }
        *a = val;
        currSize++;
    }
    else {
        cout << "List đã đầy";
    }
}

int main(){
    List a(100);
    a.addFirst(0);
    cout << a.getIndex(0);
}