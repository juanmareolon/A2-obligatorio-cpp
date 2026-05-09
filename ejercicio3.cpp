#include <iostream>
#include <cassert>
#include <string>
#include <limits>

#include "tads/PriorityQueue.h"
#include "tads/HeapImp.cpp"

using namespace std;

struct Paciente {
    int id;
    int hora;
    int urgencia;
    int orden;
};

// Función comparadora para hacerlo un Max Heap
bool comp(Paciente a, Paciente b) {
    if (a.urgencia != b.urgencia)
        return a.urgencia > b.urgencia;

    if (a.hora != b.hora)
        return a.hora < b.hora;

    return a.orden < b.orden;
}

int main()
{
    int N;
    cin >> N;

    PriorityQueue<Paciente>* heap = new HeapImp<Paciente>(N, comp);

    for (int i = 0; i < N; i++) {
        int id; 
        int urgencia;
        string horaStr;
        cin >> id >> horaStr >> urgencia;

        Paciente p;
        p.id = id;
        p.hora = stoi(horaStr);
        p.urgencia = urgencia;
        p.orden = i;

        heap->insertar(p);
    }

    while (!heap->estaVacio()) {
        cout << heap->pop().id << "\n";
    }

    delete heap;
}