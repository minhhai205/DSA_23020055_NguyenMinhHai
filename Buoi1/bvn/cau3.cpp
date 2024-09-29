#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int kq = 1;
    for(int i=1; i<=n; i++){
        kq *= i;
    }
    cout << kq << endl;
}