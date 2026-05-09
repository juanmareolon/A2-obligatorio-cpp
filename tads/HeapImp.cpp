// Lo llamamos así para dejarlo como implementación genérica de un Heap, ya que 
// necesitamos a lo largo del código usarlo tanto como Max Heap y Min Heap
#ifndef HEAP_IMP
#define HEAP_IMP

#include "PriorityQueue.h"

#include <cassert>

template <class T>
class HeapImp : public PriorityQueue<T> 
{
private:
    T* arr;
    int sigLibre;
    int capacidad;
    bool (*comp)(T, T);

    int padre(int pos){
        return (pos-1)/2;
    }

    int hijoIzq(int pos){
        return  (2*pos)+1;
    }

    int hijoDer(int pos){
        return (2*pos)+2;
    }

    void intercambiar(int pos1, int pos2) {
        T aux = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = aux;
    }


public:
    HeapImp(int cap, bool (*_comp)(T, T)) {
        assert(cap > 0);
        capacidad = cap;
        sigLibre = 0;
        arr = new T[cap];
        comp = _comp;
    }

    void flotar(int pos){
        if (pos > 0) { 
            int posPadre = padre (pos);
            if (comp(arr[pos], arr[posPadre])){
                intercambiar (pos, posPadre); 
                flotar(posPadre);
            }
        }
    }

    void hundir(int pos){
        int posHijoIzq= hijoIzq(pos) ;
        int posHijoDer = hijoDer(pos);
        if (posHijoIzq < sigLibre){
            int posMenorHijo = posHijoIzq;
            if((posHijoDer< sigLibre) && comp(arr[posHijoDer], arr[posMenorHijo])){
                posMenorHijo = posHijoDer;
            }
            if(comp(arr[posMenorHijo], arr[pos])){
                intercambiar (pos, posMenorHijo);
                hundir (posMenorHijo);
            }
        }
    }

    void insertar(T elem) {
        assert(!estaLleno());
        arr[sigLibre] = elem;
        flotar(sigLibre);
        sigLibre++;
    }

    T pop() {
        assert(!estaVacio());
        T res = arr[0];
        arr[0] = arr[sigLibre-1];
        sigLibre--;
        hundir(0);
        return res;
    }

    T tope() {
        assert(!estaVacio());
        return arr[0];
        
    }

    bool estaLleno() {
        return sigLibre == capacidad;
    }

    bool estaVacio(){
        return sigLibre == 0;
    }

    int obtenerTamano() {
        return sigLibre;
    }

    ~HeapImp() {
        delete[] arr;
    }
};

#endif