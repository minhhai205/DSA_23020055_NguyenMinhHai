#include <bits/stdc++.h>
using namespace std;
#define ll long long


void merge(int a[], int left, int mid, int right){

    int i = 0, j = 0, curr = left;
    int n1 = mid - left + 1; // luu size v1
    int n2 = right - mid; // luu size v2;

    vector<int> v1(a + left, a + mid + 1);
    vector<int> v2(a + mid + 1, a + right + 1);

    while(i < n1 || j < n2){
        if(i >= n1) a[curr++] = v2[j++];

        else if(j >= n2) a[curr++] = v1[i++];

        else if(v1[i] < v2[j]) a[curr++] = v1[i++];
        
        else a[curr++] = v2[j++];
    }

}


void mergesort(int a[], int left, int right){
    if(left >= right) return;

    int mid = (left + right) / 2;

    mergesort(a, left, mid);
    mergesort(a, mid + 1, right);

    merge(a, left, mid, right);
    
}

int main(){
    int a[10] = {4, 5, 3, 10, 2 ,7 , 6, 8, 1,9};
    mergesort(a, 0, 9);

    for(int x : a) cout << x << " ";
}

