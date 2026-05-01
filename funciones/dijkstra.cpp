#include "../tads/Garph.h"
#include "../tads/PriorityQueue.h"
#include "../tads/MaxHeapImp.cpp"
#include <limits>
using namespace std;

struct nodoHeap
{
    int vertice;
    int costo;
    nodoHeap(){}
    nodoHeap(int _vertice, int _costo){
        vertice = _vertice;
        costo = _costo; 
    }
};


int const INF = std::numeric_limits<int>::max();
bool compararFunction(nodoHeap origen, nodoHeap destino){
    return origen.costo > destino.costo;
}

int* dijkstra (Graph* g, int origen){
    int V = g->getV();
    int* costos = new int[V+1]();
    bool* visitados = new bool[V+1]();
    int* vengo = new int [V+1]();

    for (int v = 0; v <= V; v++)
    {
        costos[v] = INF;
        visitados[v] = false;
        vengo[v] = -1;
    }
    costos[origen] = 0;
    PriorityQueue<nodoHeap>* heapNodos = new MaxHeapImp<nodoHeap>(V,compararFunction);
    nodoHeap nodoInsertar = nodoHeap(origen,0);
    heapNodos->insertar(nodoInsertar);

    while(!heapNodos->estaVacio()){
        nodoHeap aux = heapNodos->pop();
        int vertice = aux.vertice;
        if(visitados[vertice]) continue;
        visitados[aux.vertice] = true;
        NodoLista<Arista>* listaAdy = g->adyacentesA(vertice);
        while (listaAdy != NULL)
        {
            int destino = listaAdy->elemento.destino;
            int peso = listaAdy->elemento.peso;
            if(costos[destino] > costos[vertice] + peso){
                costos[destino] = costos[vertice] + peso;
                vengo[destino] = vertice;
                nodoHeap nuevo(destino, costos[destino]);
                heapNodos->insertar(nuevo);
            }
            listaAdy = listaAdy->sig;
        }
    }
    return costos;
}