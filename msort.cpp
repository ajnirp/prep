// In-place mergesort with O(n) space allocation
// g++ msort.cpp
// ./a.out < in

#include <iostream>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void merge(int *arr, int l, int mid, int r) {
    int *tmp = new int[r-l+1];
    int i = l, j = mid, k = 0;
    while (i <= mid-1 and j <= r) {
        if (arr[i] < arr[j]) {
            tmp[k] = arr[i];
            i++; k++;
        } else if (arr[i] > arr[j]) {
            tmp[k] = arr[j];
            j++; k++;
        } else {
            tmp[k] = arr[i];
            i++; j++; k++;
        }
    }
    while (i <= mid-1) {
        tmp[k] = arr[i];
        i++; k++;
    }
    while (j <= r) {
        tmp[k] = arr[j];
        j++; k++;
    }
    for (int k = 0; k < r-l+1; k++) {
        arr[l+k] = tmp[k];
    }
    delete[] tmp;
}

void msort(int *arr, int l, int r) {
    if (r == l)
        return;
    if (r == l+1) {
        if (arr[l] > arr[r])
            swap(arr[l], arr[r]);
        return;
    }
    int mid = l + (r-l)/2;
    msort(arr, l, mid-1);
    msort(arr, mid, r);
    merge(arr, l, mid, r);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    msort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

/*
8
9 2 3 1 8 4 0 5
*/