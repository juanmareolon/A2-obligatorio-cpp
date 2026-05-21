#include "../tads/AdjacencyListImp.cpp"
#include "../tads/Queue.h"
#include "../tads/QueueImp.cpp"


using namespace std;

bool BFS(Graph* grafo, int origen){
    int cantVertices = grafo->getV();
    bool* encolado = new bool[cantVertices + 1]();
    int* color = new int[cantVertices + 1]();
    Queue<int>* cola = new QueueImp<int>();

    for (int i = 0; i <= cantVertices; i++)
    {
        color[i] = -1;
    }    
    cola->encolar(origen);
    encolado[origen] = true;
    color[origen] = 0;

    while(!cola -> esVacia()){
        int vertice = cola->desencolar();

        NodoLista<Arista>* ady = grafo->adyacentesA(vertice);
        while(ady != NULL){
            int verticeDestino = ady->elemento.destino;
            if(color[verticeDestino] == -1){
                color[verticeDestino] = 1 - color[vertice];
            }
            else if(color[verticeDestino] == color[vertice]){
                return false;
            }
            if(!encolado[verticeDestino]){
                cola->encolar(verticeDestino);
                encolado[verticeDestino] = true;
            }
            ady = ady->sig;
        }
    }
    delete cola;
    delete[] encolado;
    delete[] color;
    return true;
}