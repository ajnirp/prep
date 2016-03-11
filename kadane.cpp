// Maximum sum contiguous subarray
// g++ kadane.cpp
// ./a.out < in

#include <iostream>
using namespace std;

int kadane(int *arr, int n) {
    int max_so_far = 0;
    int max_ending_here = 0;
    for (int i = 0; i < n; i++) {
        max_ending_here += arr[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res = kadane(arr, n);
    cout << res << endl;
    return 0;
}

/*
8
-2 -3 4 -1 -2 1 5 -3
*/

/* Notes
 * To handle cases when all numbers are negative:

for (int i = 0; i < n; i++) {
    max_ending_here += arr[i];
    if (max_ending_here < 0)
        max_ending_here = arr[i]; <--- don't reset to 0
    if (max_so_far < max_ending_here)
        max_so_far = max_ending_here;
}

*/