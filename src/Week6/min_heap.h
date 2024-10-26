#pragma once
/*
Một Binary Heap là một cây nhị phân hoàn chỉnh. Mỗi nút (node) trên cây đều chứa một nhãn nhỏ hơn
hoặc bằng các con của nó (nếu có) và lớn hơn hoặc bằng nút cha (trừ nút gốc là và nó là nút nhỏ nhất).
Một binary heap thường được biểu diễn dưới dạng một mảng.

Phần tử gốc sẽ ở Arr[0].

Bảng dưới đây hiển thị chỉ số của các nút khác cho nút thứ i , tức là Arr[i]:
    Arr[(i-1)/2]	Trả về nút cha
    Arr[(2*i)+1]	Trả về nút con bên trái
    Arr[(2*i)+2]	Trả về nút con bên phải
*/

class MinHeap{
private:
    int *harr; // con trỏ trỏ đến các phần tử trong heap
    int heapSize; // lưu size tối đa của heap
    int currSize; // lưu size hiện tại của heap
public:
    MinHeap(int size); 
    MinHeap() {}

    int size(){ return currSize; }

    // heapify từ trên xuống
    void topDownHeapify(int i); 

    // heapify từ dưới lên
    void bottomUpHeapify(int i);

    // lấy chỉ số con trái của nút i
    int left(int i) { return (2 * i + 1);}

    // lấy chỉ số con phải của nút i
    int right(int i) { return (2 * i + 2); }

    // lấy chi số nút cha của i
    int parent(int i) { return (i - 1) / 2; }

    // trả về khóa tối thiểu của cây (giá trị của root)
    int getMin() { return harr[0]; }

    // trả về và loại bỏ phần tử nhỏ nhất (hay root) của heap
    int extractMin(); 

    // chèn giá trị mới vào cây
    void insertKey(int k);

    // xóa giá trị ở vị trí i
    void deleteKey(int i);

};
