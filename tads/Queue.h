#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
public:
    // pre: -
    // post: Agrega el elemento al final de la cola.
    virtual void encolar(T element) = 0;

    // pre: La cola no es vacía.
    // post: Elimina y retorna el elemento al frente de la cola.
    virtual T desencolar() = 0;

    // pre: -
    // post: Retorna true si la cola está vacía, false en caso contrario.
    virtual bool esVacia() = 0;

    virtual ~Queue() {}
};

#endif