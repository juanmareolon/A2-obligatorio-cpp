#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

struct Competidor {
    long long tiempoTotal;
    int indice;
};

void merge(Competidor competidores[], int inicio, int medio, int fin) {
    int tamano = fin - inicio + 1;
    Competidor* aux = new Competidor[tamano];
    int i = inicio;
    int j = medio + 1;
    int k = 0;
    while (i <= medio && j <= fin) {
        // Mantiene el orden original en caso de empate
        if (competidores[i].tiempoTotal <= competidores[j].tiempoTotal) {
            aux[k] = competidores[i];
            i++;
        } else {
            aux[k] = competidores[j];
            j++;
        }
        k++;
    }
    while (i <= medio) {
        aux[k] = competidores[i];
        i++;
        k++;
    }
    while (j <= fin) {
        aux[k] = competidores[j];
        j++;
        k++;
    }
    for (int x = 0; x < tamano; x++) {
        competidores[inicio + x] = aux[x];
    }
    delete[] aux;
}

void mergeSort(Competidor competidores[], int inicio, int fin) {
    if (inicio >= fin) {
        return;
    }
    int medio = (inicio + fin) / 2;
    mergeSort(competidores, inicio, medio);
    mergeSort(competidores, medio + 1, fin);
    merge(competidores, inicio, medio, fin);
}

int main() {
    int L;
    cin >> L;
    Competidor* competidores = new Competidor[L];
    for(int i = 1; i <=L; i++){
        competidores[i].indice = i;
        competidores[i].tiempoTotal = 0;
    }
    // Natación
    for (int i = 1; i <= L; i++) {
        int tiempoN;
        cin >> tiempoN;
        competidores[i].tiempoTotal += tiempoN;
    }
    // Ciclismo
    for (int i = 1; i <= L; i++) {
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
    mergeSort(competidores, 0, L - 1);
    for (int i = 0; i < L; i++) {
        cout << competidores[i].indice << endl;
    }
    delete[] competidores;
    return 0;
}