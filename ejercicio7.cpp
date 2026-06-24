#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "mergeSort.h"

using namespace std;

struct Competidor {
    long long tiempoTotal;
    int indice;
};

bool compararCompetidores(const Competidor& a, const Competidor& b)
{
    return a.tiempoTotal <= b.tiempoTotal;
}

int main() {
    int L;
    cin >> L;
    Competidor* competidores = new Competidor[L];
    for(int i = 0; i <L; i++){
        competidores[i].indice = i + 1;
        competidores[i].tiempoTotal = 0;
    }
    // Natación
    for (int i = 0; i < L; i++) {
        int tiempoN;
        cin >> tiempoN;
        competidores[i].tiempoTotal += tiempoN;
    }
    // Ciclismo
    for (int i = 0; i < L; i++) {
        int tiempoCi;
        cin >> tiempoCi;
        competidores[i].tiempoTotal += tiempoCi;

    }
    // Carrera
    for (int i = 0; i < L; i++) {
        int tiempoCa;
        cin >> tiempoCa;
        competidores[i].tiempoTotal += tiempoCa;
    }
    mergeSort(competidores, 0, L - 1, compararCompetidores);
    for (int i = 0; i < L; i++) {
        cout << competidores[i].indice << endl;
    }
    delete[] competidores;
    return 0;
}