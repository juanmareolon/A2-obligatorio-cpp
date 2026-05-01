#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "funciones/hashFn.cpp"
#include "funciones/dijkstra.cpp"
#include "tads/HashTable.h"
#include "tads/ClosedHashTableImp.cpp"
#include "tads/Garph.h"
#include "tads/AdjacencyListImp.cpp"
using namespace std;
int main()
{
    int N; //Cantidad de planetas (Vertices)
    int M; //Cantidad de portales (Aristas)
    cin >> N;
    cin >> M;
    HashTable<string, int>* tablaMapeo = new ClosedHashTableImp<string,int>(2*N,hash2,hash3);
    Graph* grafoPlanetas = new AdjacencyList(N, true, false);
    string planetaA;
    string planetaB;
    int peso;
    int contador = 1;
    for (int i = 1; i <=M; i++)
    {
        cin >> planetaA >> planetaB >> peso;

        if(!tablaMapeo->exists(planetaA)){
            tablaMapeo->insert(planetaA,contador);
            contador++;
        }
        if(!tablaMapeo->exists(planetaB)){
            tablaMapeo->insert(planetaB,contador);
            contador++;
        }
        grafoPlanetas->anadirArista(tablaMapeo->get(planetaA),tablaMapeo->get(planetaB),peso);
    }
    string origen;
    string destino;
    cin >> origen >> destino;
    int* costos = dijkstra(grafoPlanetas, tablaMapeo->get(origen));
    int res = costos[tablaMapeo->get(destino)];
    if (res == INF) cout << -1 << endl;
    else cout << res << endl;
    
    return 0;
}