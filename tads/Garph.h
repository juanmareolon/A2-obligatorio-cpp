#ifndef GRAPH_H
#define GRAPH_H

#include <cstddef>

#include "ListNodeImp.cpp"

struct Arista
{
    int origen;
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

    //pre: The vertices origen and destino must exist in the graph.
    //post: Adds an edge from origen to destino with the given weight.
    virtual void anadirArista(int origen, int destino, int peso = 1) = 0;

    //pre: The vertex origen must exist in the graph.
    //post: Returns a list containing all adjacent edges of origen.
    virtual NodoLista <Arista>* adyacentesA(int origen) = 0;

    //pre: -
    //post: Returns the number of vertices in the graph.
    virtual int getV() = 0;

    //pre: -
    //post: Returns the number of edges in the graph.
    virtual int getA() = 0;

    virtual ~Graph() {} 
};

#endif