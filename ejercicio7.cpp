#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "mergeSort.h"

using namespace std;

struct Competidor
{
    int indice;
    int T;
    Competidor(){
        indice=0;
        T=0;
    };
};

bool compararCompetidores(Competidor a, Competidor b)
{
    return a.T <= b.T;
}

int main() {
    int L;
    cin >> L;

    Competidor* competidores = new Competidor[L+1];
    for(int i = 1; i<=L; i++)
    {
        Competidor competidor = Competidor();
        competidor.indice = i;
        competidores[i] = competidor;
    }

    // Natación
    for (int i = 1; i <= L; i++)
    {
        int N;
        cin >> N;
        competidores[i].T += N; 
    }

    // Ciclismo
    for (int i = 1; i <= L; i++)
    {
        int B;
        cin >> B;
        competidores[i].T += B; 
    }

    // Carrera
    for (int i = 1; i <= L; i++)
    {
        int C;
        cin >> C;
        competidores[i].T += C; 
    }

    mergeSort(competidores, 1, L, compararCompetidores);
    for (int i = 1; i <= L; i++) {
        cout << competidores[i].indice << endl;
    }
    delete[] competidores;

    return 0;
}