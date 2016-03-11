// Partial <vector> implementation
// g++ vec.cpp -Wall -O3 -o vec
#include <iostream>
#include <stdlib.h>

#define INITIAL_SIZE 10

typedef unsigned int uint;

using namespace std;

template<typename T>
struct vec {
    T* arr;
    uint size;
    uint capacity;

    vec() {
        size = 0;
        capacity = INITIAL_SIZE;
        arr = new T[INITIAL_SIZE];
    }

    void push(T val) {
        if (size < capacity) {
            arr[size] = val;
            size++;
            return;
        }

        T *new_arr = new T[2*capacity];
        for (uint i = 0; i < capacity; i++)
            new_arr[i] = arr[i];
        new_arr[capacity] = val;
        delete[] arr;
        arr = new_arr;
        capacity *= 2;
        size++;
    }

    T &operator[](uint idx) {
        if (idx < size)
            return arr[idx];
        else {
            cerr << "error: vec index " << idx << " out of range" << endl;
            exit(1);
        }
    }

    void pop() {
        if (size == 0)
            return;

        size--;
    }
};

int main() {
    vec<int> v;
    for (uint i = 0; i < 10; i++)
        v.push(i);
    for (uint i = 0; i < 10; i++)
        cout << v[i] << " ";
    cout << endl;
    cout << v[18];
    return 0;
}