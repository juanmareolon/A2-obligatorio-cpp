#include <limits>
#include <cmath>

#include "../tads/AdjacencyListImp.cpp"
#include "../tads/HeapImp.cpp"

using namespace std;

struct NodoHeap {
    int vertice;
    int costo;
};

int const INF = std::numeric_limits<int>::max();

// Función comparadora para hacerlo un Min Heap
bool compMin(NodoHeap a, NodoHeap b) {
    return a.costo < b.costo;
}

int* dijkstra(Graph* g, int origen) {
    
    int V = g->getV();
    int* costos = new int[V + 1];
    bool* visitados = new bool[V + 1];
    int* vengo = new int[V + 1];

    for (int i = 1; i <= V; i++) {
        costos[i] = INF;
        visitados[i] = false;
        vengo[i] = -1;
    }

    HeapImp<NodoHeap> heap(std::pow(V, 2), compMin); //V^2 para el caso de denso

    costos[origen] = 0;
    heap.insertar({origen, 0});

    while (!heap.estaVacio()) {
        NodoHeap actual = heap.pop();
        int u = actual.vertice;

        if (visitados[u]) continue;
        visitados[u] = true;

        NodoLista<Arista>* ady = g->adyacentesA(u);

        while (ady != NULL) {
            int v = ady->elemento.destino;
            int peso = ady->elemento.peso;
            
            if (!visitados[v] && costos[u] + peso < costos[v]) {
                costos[v] = costos[u] + peso;
                vengo[v] = u;
                heap.insertar({v, costos[v]});
            }

            ady = ady->sig;
        }
    }

    delete[] visitados;
    delete[] vengo;

    return costos;
}