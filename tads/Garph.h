#ifndef GRAPH_H
#define GRAPH_H
#include <cstddef>
#include "ListNodeImp.cpp"
struct Arista
{
    int origen; //PRESINDIR
    int destino;
    int peso;
    Arista() {}
    Arista(int origen, int destino, int peso) : origen(origen), destino(destino), peso(peso) {} 
    Arista(int origen, int destino) : origen(origen), destino(destino), peso (1) {}
    ~Arista () {}
};

class Graph
{
public:
    virtual void anadirArista(int origen, int destino, int peso = 1) = 0;
    virtual NodoLista <Arista>* adyacentesA(int origen) = 0;
    virtual int getV()=0;
    virtual int getA() = 0;
};

#endif