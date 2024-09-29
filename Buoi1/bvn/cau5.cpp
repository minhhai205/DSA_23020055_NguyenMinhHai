#include<bits/stdc++.h>

using namespace std;

int main(){
    double a[100];
    int n; cin >> n;

    double sum = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i]; sum += a[i];
    }

    double tb = sum / n;
    for(int i=0; i<n; i++){
        if(a[i] >= tb) cout << a[i] << " ";
    }
}