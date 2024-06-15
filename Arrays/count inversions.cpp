#include <bits/stdc++.h> 
using namespace std;

void merge(long long arr[], int l, int m, int r, long long &inv) {
    int x = l;
    int y = m + 1;
    
    vector<long long> temp(r - l + 1);  // This line caused a compilation error
    
    int k = 0;
    while (x <= m && y <= r) {
        if (arr[x] <= arr[y]) {
            temp[k] = arr[x];
            x++;
        } else {
            temp[k] = arr[y];
            y++;
            inv += (m - x + 1);  // Counting inversions
        }
        k++;
    }
    
    while (x <= m) {
        temp[k] = arr[x];
        k++;
        x++;
    }
    
    while (y <= r) {
        temp[k] = arr[y];
        k++;
        y++;
    }
    
    // Copy sorted elements from temp back to arr
    for (int i = 0; i < temp.size(); i++) {
        arr[l] = temp[i];
        l++;
    }
}

void mergeSort(long long arr[], int l, int r, long long &inv) {
    if (l >= r) return;
    
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid, inv);
    mergeSort(arr, mid + 1, r, inv);
    merge(arr, l, mid, r, inv);
}

long long getInversions(long long arr[], int n) {
    long long inv = 0;
    mergeSort(arr, 0, n - 1, inv);
    return inv;
}

