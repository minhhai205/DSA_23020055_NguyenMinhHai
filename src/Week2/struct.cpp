#include<bits/stdc++.h>

using namespace std;

struct SinhVien{
    string ten, lop, msv;

    SinhVien(string ten_, string lop_, string msv_){
        ten = ten_;
        lop = lop_;
        msv = msv_;
    }

    void in(){
        cout << ten << " " << lop << " " << msv << endl;
    }
};

int main(){
    SinhVien y("Hai", "k68-it1", "23020055");
    y.in();
}