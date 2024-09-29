#include<bits/stdc++.h>
using namespace std;

void deleted(int a[], int &n, int k){
    if(k < 0 || k >= n){
        cout << "invalid\n";
    } else {
        for(int i=k; i<n; i++){
            a[i] = a[i + 1];
        }
        --n;
    }
}

void insert(int a[], int &n, int y, int m){
    if(m < 0 || m >= n){
        cout << "invalid\n";
    } else {
        for(int i=m+1; i<=n; i++){
            a[i] = a[i - 1];
        }
        a[m] = y; ++n;
    }
}
int main(){
    int a[100];
    int n; cin >> n;

    for(int i=0; i<n; i++) cin >> a[i];

    int k; cin >> k;
    deleted(a, n, k);
    for(int i=0; i<n; i++) cout << a[i] << " ";

    cout << endl;
    int y, m; cin >> y >> m;
    insert(a, n, y, m);
    for(int i=0; i<n; i++) cout << a[i] << " ";
}