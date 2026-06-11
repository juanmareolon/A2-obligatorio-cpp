#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>

#include "tads/HashTable.h"
#include "tads/ClosedHashTableImp.cpp"

#include "funciones/hashFn.cpp"

using namespace std;

struct Alumno {
    string nombre;
    int puntos;
    Alumno() {} // necesario para el array
    Alumno(string nombre, int puntos) : nombre(nombre), puntos(puntos) {}

    bool operator==(Alumno a) {
        return nombre == a.nombre && puntos == a.puntos;
    }
};

int main()
{
    int cantidad;
    cin >> cantidad;

    // Array en lugar de lista → O(1) acceso
    Alumno* alumnos = new Alumno[cantidad];

    HashTable<string, int>* tablaPuntajes =
        new ClosedHashTableImp<string, int>(cantidad, hash3, hash2);

    // Lectura + acumulación total
    for (int i = 0; i < cantidad; i++)
    {
        string nombre;
        int puntos;
        cin >> nombre >> puntos;

        alumnos[i] = Alumno(nombre, puntos);

        if (tablaPuntajes->exists(nombre)) {
            int puntajeActual = tablaPuntajes->get(nombre);
            tablaPuntajes->insert(nombre, puntajeActual + puntos);
        } else {
            tablaPuntajes->insert(nombre, puntos);
        }
    }

    // Buscar puntaje máximo final
    int maxFinal = numeric_limits<int>::min();

    for (int i = 0; i < cantidad; i++) {
        int total = tablaPuntajes->get(alumnos[i].nombre);
        if (total > maxFinal) {
            maxFinal = total;
        }
    }

    // Segunda pasada: ver quién llega primero al maxFinal
    HashTable<string, int>* tablaAcumulados =
        new ClosedHashTableImp<string, int>(cantidad, hash3, hash2);

    string ganador = "";

    for (int i = 0; i < cantidad; i++)
    {
        Alumno unAlumno = alumnos[i];

        int puntajeAcumulado;
        if (tablaAcumulados->exists(unAlumno.nombre)) {
            puntajeAcumulado = tablaAcumulados->get(unAlumno.nombre) + unAlumno.puntos;
        } else {
            puntajeAcumulado = unAlumno.puntos;
        }

        tablaAcumulados->insert(unAlumno.nombre, puntajeAcumulado);

        if (puntajeAcumulado == maxFinal &&
            tablaPuntajes->get(unAlumno.nombre) == maxFinal) {
            ganador = unAlumno.nombre;
            break;
        }
    }

    cout << ganador << endl;

    delete[] alumnos;
    delete tablaPuntajes;
    delete tablaAcumulados;

    return 0;
}