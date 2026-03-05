// Compilation: g++ -std=c++17 -Wall -Wextra problem3.cpp -o problem3
#include <iostream>

using namespace std;

int linearSearch(int* arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int binarySearch(int* arr, int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int* generateSortedArray(int n) {
    int* arr = new int[n];
    for (int i = 0; i < n; i++) arr[i] = i * 2;
    return arr;
}

void test(int n) {
    int* arr = generateSortedArray(n);
    int midVal = arr[n/2];
    
    cout << "Array Size: " << n << endl;
    cout << "Search Existing (" << midVal << "): L=" << linearSearch(arr, n, midVal) 
         << " B=" << binarySearch(arr, n, midVal) << endl;
    cout << "Search Non-Existing (-1): L=" << linearSearch(arr, n, -1) 
         << " B=" << binarySearch(arr, n, -1) << endl;
    cout << "---------------------------" << endl;
    
    delete[] arr;
}

int main() {
    int sizes[] = {10, 100, 1000};
    for (int n : sizes) test(n);
    return 0;
}