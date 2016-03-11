// Counting sort
// g++ csort.cpp
// ./a.out < in
#include <iostream>
using namespace std;

void csort(int *arr, int n, int min, int max) {
    int len_counts = max-min+1;
    int *counts = new int[len_counts];

    // compute counts
    for (int i = 0; i < n; i++)
        counts[arr[i]-min]++;

    // prefix sums
    for (int i = 1; i < len_counts; i++)
        counts[i] += counts[i-1];

    int *tmp = new int[n];
    for (int i = 0; i < n; i++) {
        tmp[counts[arr[i]-min]-1] = arr[i];
        counts[arr[i]-min]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = tmp[i];

    delete[] tmp;
    delete[] counts;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int min = arr[0], max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    csort(arr, n, min, max);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}

/*
14
9 2 3 1 8 4 0 5 1 6 6 3 7 2
*/