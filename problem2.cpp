// Compilation: g++ -std=c++17 -Wall -Wextra -g -fsanitize=address problem2.cpp -o problem2
#include <iostream>

using namespace std;

struct DynArray {
    int* data;
    int size;
    int capacity;
};

// O(1)
void initArray(DynArray& a) {
    a.capacity = 2;
    a.size = 0;
    a.data = new int[a.capacity];
}

// O(1)
void freeArray(DynArray& a) {
    delete[] a.data;
    a.data = nullptr;
    a.size = 0;
    a.capacity = 0;
}

// O(1) amortized, O(n) worst case
void pushBack(DynArray& a, int value) {
    if (a.size == a.capacity) {
        a.capacity *= 2;
        int* newData = new int[a.capacity];
        for (int i = 0; i < a.size; i++) {
            newData[i] = a.data[i];
        }
        delete[] a.data;
        a.data = newData;
    }
    a.data[a.size++] = value;
}

// O(n)
void insertAt(DynArray& a, int index, int value) {
    if (a.size == a.capacity) {
        a.capacity *= 2;
        int* newData = new int[a.capacity];
        for (int i = 0; i < a.size; i++) newData[i] = a.data[i];
        delete[] a.data;
        a.data = newData;
    }
    for (int i = a.size; i > index; i--) {
        a.data[i] = a.data[i-1];
    }
    a.data[index] = value;
    a.size++;
}

// O(n)
void removeAt(DynArray& a, int index) {
    for (int i = index; i < a.size - 1; i++) {
        a.data[i] = a.data[i+1];
    }
    a.size--;
}

// O(1)
int getAt(const DynArray& a, int index) {
    return a.data[index];
}

// O(1)
void setAt(DynArray& a, int index, int value) {
    a.data[index] = value;
}

// O(n)
void printDynArr(const DynArray& a) {
    cout << "[";
    for (int i = 0; i < a.size; i++) {
        cout << a.data[i] << (i == a.size - 1 ? "" : ", ");
    }
    cout << "] (size=" << a.size << ", cap=" << a.capacity << ")" << endl;
}

int main() {
    DynArray arr;
    initArray(arr);

    for (int i = 1; i <= 5; i++) pushBack(arr, i * 10);
    printDynArr(arr);

    insertAt(arr, 2, 25);
    printDynArr(arr);

    removeAt(arr, 0);
    printDynArr(arr);

    cout << "Element at index 2: " << getAt(arr, 2) << "\n";
    setAt(arr, 2, 99);
    printDynArr(arr);

    freeArray(arr);
    return 0;
}