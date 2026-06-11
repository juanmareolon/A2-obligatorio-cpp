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

    cin >> N >> M;

    HashTable<string, int>* tablaMapeo = new ClosedHashTableImp<string, int> (2*N, hash2, hash3);
    Graph* grafoPlanetas = new AdjacencyList(N, true, false);

    string planetaA, planetaB;
    int peso;

    int contador = 1;
    for (int i = 1; i <=M; i++)
    {
        cin >> planetaA >> planetaB >> peso;

        if(!tablaMapeo->exists(planetaA)){
            tablaMapeo->insert(planetaA, contador);
            contador++;
        }
        if(!tablaMapeo->exists(planetaB)){
            tablaMapeo->insert(planetaB, contador);
            contador++;
        }

        int posA = tablaMapeo->get(planetaA);
        int posB = tablaMapeo->get(planetaB);
        grafoPlanetas->anadirArista(posA, posB, peso);
    }

    string origen, destino;
    cin >> origen >> destino;

    if(!tablaMapeo->exists(origen)){
        tablaMapeo->insert(origen, contador++);
    }
    if(!tablaMapeo->exists(destino)){
        tablaMapeo->insert(destino, contador++);
    }

    int posO = tablaMapeo->get(origen);
    int posD = tablaMapeo->get(destino);

    int* costos = dijkstra(grafoPlanetas, posO);
    int res = costos[posD];

    if (res == INF) cout << -1 << endl;
    else cout << res << endl;
    
    return 0;
}