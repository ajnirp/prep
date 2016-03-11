// Dutch national flag algorithm
// g++ dnf.cpp
// ./a.out < in

#include <iostream>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

/* 0 to i-1: all less than mid
   m+1 to n-1: all greater than mid
    j scans the current element
   The algo stops when j > m */
void dnf(int *arr, int n, int mid) {
    int i = 0, j = 0, m = n-1;
    while (j <= m) {
        if (arr[j] < mid) {
            swap(arr[i], arr[j]);
            i++; j++;
        } else if (arr[j] > mid) {
            swap(arr[j], arr[m]);
            m--;
        } else {
            j++;
        }
    }
}

int main() {
    int n, mid; cin >> n >> mid;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // swap(arr[0], arr[1]);
    dnf(arr, n, mid);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    delete[] arr;
}

/*
8 4
9 2 3 1 8 4 0 5
*/