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
    int V, A;
    cin >> V >> A;
    Graph* grafo = new AdjacencyList(V, false, false);
    for (int i = 0; i < A; i++){
        int u, v;
        cin >> u >> v;
        grafo->anadirArista(u, v);
    }
    int* color = new int[V + 1];
    for (int i = 1; i <= V; i++){
        color[i] = -1;
    }
    bool bipartito = true;
    for (int i = 1; i <= V; i++){
        if (color[i] == -1){
            if (!BFS(grafo, i, color)){
                bipartito = false;
            }
        }
    }
    if (bipartito) cout << "SI" << endl;
    else cout << "NO" << endl;

    delete[] color;

    return 0;
}