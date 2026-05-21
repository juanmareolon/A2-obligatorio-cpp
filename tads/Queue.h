#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
public:
    // pre: -
    // post: the element is inserted at the end of the list
    virtual void encolar(T element) = 0;

    // pre: the index is valid (0 <= index < size)
    // post: the element is inserted at the given index
    virtual T desencolar() = 0;

    // pre: -
    // post: returns if the list is empty
    virtual bool esVacia() = 0;

    virtual ~Queue() {}
};

#endif