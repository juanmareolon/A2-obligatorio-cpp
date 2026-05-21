#ifndef QUEUE_IMP
#define QUEUE_IMP

#include "Queue.h"
#include <stdexcept>

template <class T>
struct Nodo {
    T dato;
    Nodo<T>* sig;

    Nodo(T d) {
        dato = d;
        sig = NULL;
    }
};

template <class T>
class QueueImp : public Queue<T> {

private:
    Nodo<T>* lista;

public:

    QueueImp() {
        lista = NULL;
    }

    void encolar(T element) {
        Nodo<T>* nuevo = new Nodo<T>(element);

        if (lista == NULL) {
            lista = nuevo;
        } else {
            Nodo<T>* aux = lista;

            while (aux->sig != NULL) {
                aux = aux->sig;
            }

            aux->sig = nuevo;
        }
    }

    T desencolar() {
        if (lista == NULL) throw std::runtime_error("La cola esta vacia");
        Nodo<T>* borrar = lista;
        T dato = borrar->dato;
        lista = lista->sig;
        delete borrar;
        return dato;
    }

    bool esVacia(){
        return lista == NULL;
    }

    ~QueueImp() {
        while (!esVacia()) {
            desencolar();
        }
    }
};

#endif