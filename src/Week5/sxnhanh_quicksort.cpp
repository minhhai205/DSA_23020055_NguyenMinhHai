#include<bits/stdc++.h>
using namespace std;


// Phân hoạch lomuto
// duy trì 2 chỉ số i, j. j để so sánh giá trị với pivot còn i để swap 
// và đảm bảo các phần từ bên trái i đã duyệt luôn <= pivot
// void quicksort(int a[], int left, int right){
//     if(left >= right) return;

//     int pivot = a[right];
//     int i = left - 1;

//     for(int j=left; j<right; j++){
//         if(a[j] <= pivot) swap(a[++i], a[j]);
//     }

//     swap(a[++i], a[right]);

//     quicksort(a, left, i - 1);
//     quicksort(a, i + 1, right);
// }

// phân hoạch hoare
// tìm 1 cặp nghịch thế giữa pivot để đổi chỗ, sau 1 vòng sẽ chia mảng thành 2 phần <= chốt và >= chốt,
// gọi phân hoạch tiếp đến 2 mảng con
void quicksort(int a[], int left, int right) {
    if (left >= right) return;

    int i = left, j = right;
    int pivot = a[left];  // Chọn pivot là phần tử đầu tiên

    while (true) {
        while (a[i] < pivot) ++i;  // Tìm phần tử bên trái lớn hơn hoặc bằng pivot
        while (a[j] > pivot) --j;  // Tìm phần tử bên phải nhỏ hơn hoặc bằng pivot

        if (i >= j) break;  // Khi i vượt qua j thì dừng lại

        swap(a[i], a[j]);   // Đổi chỗ phần tử sai vị trí
        ++i; --j;
    }

    quicksort(a, left, j);     // Đệ quy với phần bên trái của pivot
    quicksort(a, j + 1, right);  // Đệ quy với phần bên phải của pivot
}


int main(){
    
    int a[7] = {5, 4, 2, 8, 6, 4, 9};
    quicksort(a, 0, 6);
    for(int x : a) cout << x << " ";
}