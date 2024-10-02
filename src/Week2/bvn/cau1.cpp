#include <bits/stdc++.h>

using namespace std;

int solve(){
    int n, a[100], sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    
    return sum;
}

int main(){
    cout << solve();
}