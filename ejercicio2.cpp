#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include "tads/HashTable.h"
#include "tads/List.h"
#include "tads/ClosedHashTableImp.cpp"
#include "tads/ListImp.cpp"
using namespace std;

struct Alumno {
    string nombre;
    int puntos;
    Alumno(string nombre, int puntos) : nombre(nombre), puntos(puntos) {}

    bool operator==(Alumno a) {
        return nombre == a.nombre && puntos == a.puntos;
    }
};

int hash2(string key) {
    int h = 0;
    for (int i = 0; i < key.length(); i++) {
        h = (h * 131) + key[i];
    }
    return (h << 1) | 1; // asegura que sea impar (clave para doble hashing)
}

int hash3(string key) { //Funcion hash para strings, es la misma utilizada en clase.
  int h = 0;
  for (int i = 0; i < key.length(); i++)
    h = 31 * h + int(key[i]);
  return h;
}

int main()
{
    int cantidad;
    cin >> cantidad;
    List<Alumno>* listaAlumnos = new ListImp<Alumno>();
    HashTable<string, int>* tablaPuntajes = new ClosedHashTableImp<string, int>(cantidad, hash3, hash2);

    for (int i = 0; i < cantidad; i++)
    {
        string nombre;
        int puntos;
        cin >> nombre >> puntos;
        listaAlumnos->insert(Alumno(nombre, puntos));

        if (tablaPuntajes->exists(nombre)) {
            int puntajeActual = tablaPuntajes->get(nombre);
            tablaPuntajes->insert(nombre, puntajeActual + puntos);
        } else {
            tablaPuntajes->insert(nombre, puntos);
        }
    }

    int maxFinal = numeric_limits<int>::min(); // Funciona como en java Integer.MIN_VALUE
    for (int i = 0; i < listaAlumnos->getSize(); i++) {
        Alumno unAlumno = listaAlumnos->get(i);
        int total = tablaPuntajes->get(unAlumno.nombre);
        if (total > maxFinal) {
            maxFinal = total;
        }
    }

    // Aca necesitamos acumular los puntos de cada alumno en orden, para ver quien fue el primero en llegar a maxFinal
    HashTable<string, int>* tablaAcumulados = new ClosedHashTableImp<string, int>(cantidad, hash3, hash2);
    string ganador = "";
    for (int i = 0; i < listaAlumnos->getSize(); i++)
    {
        Alumno unAlumno = listaAlumnos->get(i);
        int puntajeAcumulado;
        if (tablaAcumulados->exists(unAlumno.nombre)) {
            puntajeAcumulado = tablaAcumulados->get(unAlumno.nombre) + unAlumno.puntos;
        } else {
            puntajeAcumulado = unAlumno.puntos;
        }
        tablaAcumulados->insert(unAlumno.nombre, puntajeAcumulado);

        if (puntajeAcumulado == maxFinal && tablaPuntajes->get(unAlumno.nombre) == maxFinal) { // Verifico que el maxFinal sea el mismo que el total final del alumno
            ganador = unAlumno.nombre;
            break;
        }
    }
    cout << ganador << endl;
    delete listaAlumnos;
    delete tablaPuntajes;
    delete tablaAcumulados;
    return 0;
}

