 
#include<bits/stdc++.h>
using namespace std;

// tim kiem nhi phan: binary search; O(log(n));

// tim xem x co cuat hien trong mang hay khong
bool search(int a[], int n, int x){
	int left = 0, right = n - 1;
	while(left <= right){
		int mid = (left + right) / 2;
		if(a[mid] == x) return true;
		else if(a[mid] < x){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	return false;
}

int main(){
	
	int n, x; cin >> n >> x;
	int a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	 
	if(search(a, n, x)) cout << "yes\n";
	else cout << "no\n";

}
























