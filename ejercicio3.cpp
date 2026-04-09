#include "tads/MaxHeap.h"
#include "tads/MaxHeapImp.cpp"
#include <iostream>
using namespace std;
#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;

struct Paciente {
    int id;
    int hora;
    int urgencia;
    int orden;
};

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

    MaxHeap<Paciente>* heap = new MaxHeapImp<Paciente>(N, comp);

    for (int i = 0; i < N; i++) {
        int id, urgencia;
        string horaStr;
        cin >> id >> horaStr >> urgencia;

        Paciente p;
        p.id = id;
        p.hora = stoi(horaStr);
        p.urgencia = urgencia;
        p.orden = i;

        heap->push(p);
    }

    while (!heap->isEmpty()) {
        cout << heap->pop().id << "\n";
    }

    delete heap;
}