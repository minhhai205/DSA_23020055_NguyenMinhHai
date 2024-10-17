#include "list.h"
#include<iostream>

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
    for(int i=0; i < currSize - 1; i++){
        *(a + i) = *(a + i + 1);
    }
    --currSize;
}

void List::deleteLast(){
    --currSize;
}

void List::deleteMiddle(int index){
    for(int i=index; i<currSize-1; i++){
        *(a + i) = *(a + i + 1);
    }
    --currSize;
}

void List::printFirst(){
    for(int i=0; i<currSize; i++){
        std::cout << *(a + i) << " ";
    } 
}

void List::printLast(){
    for(int i = currSize - 1; i>=0; i--){
        std::cout << *(a + i) << " ";
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
    std::cout << "Danh sách từ đầu: ";
    myList.printFirst();
    std::cout << std::endl;

    // In danh sách từ cuối lên đầu
    std::cout << "Danh sách từ cuối: ";
    myList.printLast();
    std::cout << std::endl;

    // Xóa phần tử đầu tiên
    myList.deleteFirst();     // Danh sách: 7 10
    std::cout << "Sau khi xóa phần tử đầu tiên: ";
    myList.printFirst();
    std::cout << std::endl;

    // Xóa phần tử cuối cùng
    myList.deleteLast();      // Danh sách: 7
    std::cout << "Sau khi xóa phần tử cuối cùng: ";
    myList.printFirst();
    std::cout << std::endl;

    // Xóa phần tử ở giữa (index = 0)
    myList.deleteMiddle(0);   // Danh sách rỗng
    std::cout << "Sau khi xóa phần tử ở giữa: ";
    myList.printFirst();
    std::cout << std::endl;

    return 0;
}
