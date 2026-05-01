#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST
#include <cassert>
#include "List.h"
#include "ListImp.cpp"
#include "Garph.h"

class AdjacencyList : public Graph
{
private:
    NodoLista<Arista> **listaNodos;
    int V;
    int A;
    bool esPonderado;
    bool esDirigido;

public:
    AdjacencyList(int _V, bool _esPonderado, bool _esDirigido)
    {
        V = _V;
        A = 0;
        esDirigido = _esDirigido;
        esPonderado = _esPonderado;
        listaNodos = new NodoLista <Arista>*[V + 1]();
        for (int i = 1; i <= V; i++)
        {
            listaNodos[i] = NULL;
        }
    }

    void anadirArista(int origen, int destino, int peso = 1)
    {
        assert(esPonderado || peso == 1);
        Arista a(origen, destino, peso);
        listaNodos[origen] = new NodoLista<Arista>(a, listaNodos[origen]);
        if (!esDirigido)
        {
            Arista a(destino, origen, peso);
            listaNodos[destino] = new NodoLista<Arista>(a, listaNodos[destino]);
        }
        A++;
    }
    int getV()
    {
        return V;
    }
    int getA()
    {
        return A;
    }

    NodoLista<Arista>* adyacentesA(int origen)
    {
        NodoLista <Arista>*ret = NULL;
        NodoLista <Arista>*aux = listaNodos[origen];
        while (aux != NULL)
        {
            ret = new NodoLista<Arista>(aux->elemento, ret);
            aux = aux->sig;
        }
        return ret;
    }
    
};
 
#endif