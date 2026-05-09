#ifndef LIST_NODE_IMP
#define LIST_NODE_IMP

template <class T>
struct NodoLista{
    T elemento;
    NodoLista * sig;
    NodoLista(T _el) {
        elemento = _el;
        sig = NULL;
    }
    NodoLista(T _el, NodoLista* _sig) {
        elemento = _el;
        sig = _sig;
    }
};

#endif