#ifndef MAX_HEAP_IMP
#define MAX_HEAP_IMP

#include "MaxHeap.h"
#include <cassert>

template <class T>
class MaxHeapImp : public MaxHeap<T> {
private:
    T* arr;
    int size;
    int capacity;

    bool (*comp)(T, T); // función de comparación

    void swap(int i, int j) {
        T tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    void subir(int i) {
        while (i > 0) {
            int padre = (i - 1) / 2;
            if (comp(arr[i], arr[padre])) {
                swap(i, padre);
                i = padre;
            } else break;
        }
    }

    void bajar(int i) {
        while (true) {
            int izq = 2*i + 1;
            int der = 2*i + 2;
            int mejor = i;

            if (izq < size && comp(arr[izq], arr[mejor]))
                mejor = izq;

            if (der < size && comp(arr[der], arr[mejor]))
                mejor = der;

            if (mejor != i) {
                swap(i, mejor);
                i = mejor;
            } else break;
        }
    }

public:
    MaxHeapImp(int cap, bool (*_comp)(T, T)) {
        capacity = cap;
        size = 0;
        arr = new T[cap];
        comp = _comp;
    }

    void push(T elem) {
        assert(size < capacity);
        arr[size] = elem;
        subir(size);
        size++;
    }

    T pop() {
        assert(size > 0);
        T res = arr[0];
        arr[0] = arr[size-1];
        size--;
        bajar(0);
        return res;
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    ~MaxHeapImp() {
        delete[] arr;
    }
};

#endif