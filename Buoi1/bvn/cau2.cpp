#include <bits/stdc++.h>

using namespace std;

void sort(int a[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]) swap(a[i], a[j]);
        }
        
    }
}

int main(){
    int a[100], n; cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];

    sort(a, n);
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}