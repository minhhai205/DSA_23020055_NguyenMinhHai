#include <bits/stdc++.h>
using namespace std;

// sap xep chon O(n^2)
// dua phan tu nho nhat ve dau day
void selectionsort(){
    for(int i=0; i<n-1; i++){
        int pos = i;
        for(int j=i+1; j<n; j++){
            if(a[i] < a[pos]) pos = j;
        }
        swap(a[i], a[pos]);
    }
}

// sap xep noi bot O(n^2)
// dua phan tu lon hon ve cuoi day
void bubblesort(int a[], int n){
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<=i; j++){
            if(a[j] > a[j + 1]) swap(a[j], a[j+1]);
        }
    }
}

// sap xep chen O(n^2)
void insertionsort(int a[], int n){
    for(int i=1; i<n; i++){
        int x = a[i], pos = i - 1;
        while(pos >= 0 && x < a[pos]){
            a[pos + 1] = a[pos];
            --pos;
        }
        a[pos+1]=x;
    }
}

int main(){
    int a[10];
    for(auto &x : a) cin>>x;
    bubblesort(a, 10);
    for(auto x : a) cout<<x<<" ";
}
