#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

template <class T>
class PriorityQueue
{
public:

    // pre: there is enough space in the heap to insert a new element
    // post: the element elem is inserted into the heap, preserving the max-heap property
    virtual void insertar(T elem) = 0;

    // pre: the heap is not empty
    // post: removes and returns the element with highest priority (root of the heap), preserving the max-heap property
    virtual T pop() = 0;

    // pre: the heap is not empty
    // post: returns the element with highest priority (root of the heap) without removing it
    virtual T tope() = 0;

    // pre: -
    // post: returns true if the heap has reached its maximum capacity, false otherwise
    virtual bool estaLleno() = 0;

    // pre: 0 <= pos < number of elements in the heap
    // post: restores the heap property by moving the element at position pos downwards if necessary
    virtual void hundir(int pos) = 0;

    // pre: 0 <= pos < number of elements in the heap
    // post: restores the heap property by moving the element at position pos upwards if necessary
    virtual void flotar(int pos) = 0;

    // pre: -
    // post: returns true if the heap is empty, false otherwise
    virtual bool estaVacio() = 0;

    // pre: -
    // post: returns the number of elements currently stored in the heap
    virtual int obtenerTamano() = 0;

    virtual ~PriorityQueue() {}
};

#endif