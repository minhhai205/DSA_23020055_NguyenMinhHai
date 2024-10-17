#include "min_heap.h"
#include <bits/stdc++.h>
using namespace std;

void heapsort(int a[], int n){
    MinHeap heap(n);
    for(int i=0; i<n; i++){
        heap.insertKey(a[i]);
    }
    for(int i=0; i<n; i++){
        a[i] = heap.extractMin();
    }
}

int main(){
    int a[8] = {3, 5, 2, 7, 1, 8, 3, 2};
    heapsort(a, 8);
    for(int i=0; i<8; i++) cout << a[i] << " ";
}