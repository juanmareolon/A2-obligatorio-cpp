#ifndef MAX_HEAP_H
#define MAX_HEAP_H

template <class T>
class MaxHeap 
{
public:
    // pre: there is enough space in the heap to insert a new element
    // post: the element elem is inserted into the heap, preserving the max-heap property
    virtual void push(T elem) = 0;

    // pre: the heap is not empty
    // post: removes and returns the element with highest priority (root of the heap), preserving the max-heap property
    virtual T pop() = 0;

    // pre: -
    // post: returns true if the heap is empty, false otherwise
    virtual bool isEmpty() = 0;

    // pre: -
    // post: returns the number of elements currently stored in the heap
    virtual int getSize() = 0;

    virtual ~MaxHeap() {}
};

#endif