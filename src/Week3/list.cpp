#include<bits/stdc++.h>

using namespace std;


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

List::length(){
    return currSize;
}

List::List(int n){
    a = new int[n];
    size = n;
    currSize = 0;
}

int List::getIndex(int index){
    return *(a + index);
}

void List::addFirst(int val){
    if(currSize >= size) return;
    for(int i=0; i<currSize; i++){
        *(a + i + 1) = *(a + i);
    }
    *a = val;
    currSize++;
}

void List::addLast(int val){
    if(currSize >= size) return;
    *(a + currSize) = val;
    currSize++;
}

void List::addMiddle(int val, int index){
    if(currSize >= size) return;
    for(int i=index; i<currSize; i++){
        *(a + i + 1) = *(a + i);
    }
    *(a + index) = val;
    ++currSize;
}

void List::deleteFirst(){
    for(int i=0; i< currSize; i++){
        *(a + i) = *(a + i + 1);
    }
    --currSize;
}

void List::deleteLast(){
    --currSize;
}

void List::deleteMiddle(int index){
    for(int i=index; i<currSize; i++){
        *(a + i) = *(a + i + 1);
    }
    --currSize;
}

void List::printFirst(){
    for(int i=0; i<currSize; i++){
        cout << *(a + i) << " ";
    } 
}

void List::printLast(){
    for(int i = currSize - 1; i>=0; i--){
        cout << *(a + i) << " ";
    }
}

int main() {
    // Tạo danh sách với kích thước tối đa là 10
    List myList(10);

    // Thêm phần tử vào đầu, cuối và giữa danh sách
    myList.addFirst(5);       // Danh sách: 5
    myList.addLast(10);       // Danh sách: 5 10
    myList.addMiddle(7, 1);   // Danh sách: 5 7 10

    // In danh sách từ đầu đến cuối
    cout << "Danh sách từ đầu: ";
    myList.printFirst();
    cout << endl;

    // In danh sách từ cuối lên đầu
    cout << "Danh sách từ cuối: ";
    myList.printLast();
    cout << endl;

    // Xóa phần tử đầu tiên
    myList.deleteFirst();     // Danh sách: 7 10
    cout << "Sau khi xóa phần tử đầu tiên: ";
    myList.printFirst();
    cout << endl;

    // Xóa phần tử cuối cùng
    myList.deleteLast();      // Danh sách: 7
    cout << "Sau khi xóa phần tử cuối cùng: ";
    myList.printFirst();
    cout << endl;

    // Xóa phần tử ở giữa (index = 0)
    myList.deleteMiddle(0);   // Danh sách rỗng
    cout << "Sau khi xóa phần tử ở giữa: ";
    myList.printFirst();
    cout << endl;

    return 0;
}