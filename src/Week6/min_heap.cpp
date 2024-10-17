#include "min_heap.h"
#include <climits>
#include <iostream>
#include <utility>

MinHeap::MinHeap(int size){
    harr = new int[size];
    currSize = 0;
    heapSize = size;
}

void MinHeap::topDownHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    // swap giá trị của nút i và giá trị của nút < giá trị của i trong các nút con và có giá trị nhó nhất
    if(l < currSize && harr[l] < harr[smallest]) smallest = l;
    if(r < currSize && harr[r] < harr[smallest]) smallest = r;
    if(smallest != i) {
        std::swap(harr[smallest], harr[i]);
        topDownHeapify(smallest);
    }
}

void MinHeap::bottomUpHeapify(int i){
    while(i > 0 && harr[parent(i)] > harr[i]){
        std::swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin(){
    if(currSize <= 0) return INT_MAX;
    
    int root = harr[0];
    harr[0] = harr[currSize-1];
    --currSize;
    topDownHeapify(0);

    return root;
}

void MinHeap::insertKey(int k){
    if(currSize == heapSize) return;

    // Đầu tiên chèn khóa mới vào cuối
    int i = currSize;
    harr[currSize++] = k;

    // xấy dụng lại minheap từ dưới lên
    bottomUpHeapify(i);
}

void MinHeap::deleteKey(int i){
    if (i >= currSize) return;
    
    // gán giá trị tại nút i là INT_MIN rồi xấy dụng lại min heap từ dưới lên để 
    // đưa nút lên đầu min heap và tiền hành extractMin()
    harr[i] = INT_MIN;
    bottomUpHeapify(i);
    extractMin(); 
}




