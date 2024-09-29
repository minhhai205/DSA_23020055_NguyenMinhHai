#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

void rutgon(int &a, int &b){
    int ucln = gcd(abs(a), abs(b));
    a /= ucln; b /= ucln;

    if (a < 0) {
        a *= -1;
        b *= -1;
    }
}

int main(){
    int a, b;
    cin >> a >> b;
 
    rutgon(a, b);
    cout << a << " " << b;
}