#include <cassert>
#include <string>
#include <iostream>
#include <limits>

#include "funciones/BFS.cpp"
#include "tads/Garph.h"
#include "tads/AdjacencyListImp.cpp"

using namespace std;

int main()
{
    int cantVertices;
    int cantAristas;
    cin >> cantVertices >> cantAristas;
    Graph* grafo = new AdjacencyList(cantVertices,false,false);
    for (int i = 1; i <= cantAristas; i++)
    {
        int verticeOrigen;
        int verticeDestino;
        cin >> verticeOrigen >> verticeDestino;
        grafo->anadirArista(verticeOrigen,verticeDestino);
    }
    
    bool retorno = BFS(grafo, 1);

    if(retorno){
        cout << "SI" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}