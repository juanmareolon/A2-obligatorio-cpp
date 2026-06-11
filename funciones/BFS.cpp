#include "../tads/AdjacencyListImp.cpp"
#include "../tads/Queue.h"
#include "../tads/QueueImp.cpp"

using namespace std;

bool BFS(Graph* grafo, int origen, int* color)
{
    Queue<int>* cola = new QueueImp<int>();
    cola->encolar(origen);
    color[origen] = 0;
    while (!cola->esVacia())
    {
        int vertice = cola->desencolar();
        NodoLista<Arista>* ady = grafo->adyacentesA(vertice);
        while (ady != NULL){
            int vecino = ady->elemento.destino;
            // No visitado
            if (color[vecino] == -1){
                color[vecino] = 1 - color[vertice];
                cola->encolar(vecino);
            }
            // Conflicto
            else if (color[vecino] == color[vertice]){
                delete cola;
                return false;
            }
            ady = ady->sig;
        }
    }

    delete cola;
    return true;
}