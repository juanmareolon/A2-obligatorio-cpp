#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include "mergeSort.h"

using namespace std;
float INF = numeric_limits<float>::max();

struct Punto
{
    int x;
    int y;

    Punto() {}

    Punto(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

float distancia(Punto primerPunto, Punto segundoPunto)
{
    int x1 = primerPunto.x;
    int x2 = segundoPunto.x;
    int y1 = primerPunto.y;
    int y2 = segundoPunto.y;
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

float minEntreTres(Punto a, Punto b, Punto c)
{
    float d1 = distancia(a, b);
    float d2 = distancia(a, c);
    float d3 = distancia(b, c);
    if (d1 <= d2 && d1 <= d3)
        return d1;
    if (d2 <= d3)
        return d2;
    return d3;
}

bool compararPorX(const Punto& a, const Punto& b)
{
    return a.x <= b.x;
}

bool compararPorY(const Punto& a, const Punto& b)
{
    return a.y <= b.y;
}

float min(float a, float b)
{
    return (a < b) ? a : b;
}

float minimoFranja(Punto *conjuntoPuntos, int inicio, int fin, float d)
{
    int N = fin - inicio + 1;
    mergeSort(conjuntoPuntos, 0, N - 1, compararPorY);

    for (int i = 0 ; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            float distanciaEntrePuntos = distancia(conjuntoPuntos[i], conjuntoPuntos[j]);
            if (distanciaEntrePuntos >= d) break;
                d = distanciaEntrePuntos;
        }
    }
    return d;
}

int getInicioFranja(Punto *puntos, int inicio, int medio, float d)
{
    int i = medio;
    while (i >= inicio && puntos[medio].x - puntos[i].x < d)
        i--;
    return i + 1;
}

int getFinalFranja(Punto *puntos, int medio, int final, float d)
{
    int i = medio + 1;
    while (i <= final && puntos[i].x - puntos[medio].x < d)
        i++;
    return i - 1;
}

float DAC_p(Punto *conjuntoPuntos, int inicio, int final)
{
    if(inicio == final){
        return INF;
    }
    else if (final - inicio == 1)
    {
        return distancia(conjuntoPuntos[inicio], conjuntoPuntos[final]);
    }
    else if (final - inicio == 2)
    {
        return minEntreTres(conjuntoPuntos[inicio], conjuntoPuntos[inicio + 1], conjuntoPuntos[final]);
    }

    int medio = (inicio + final) / 2;
    float distanciaIzq = DAC_p(conjuntoPuntos, inicio, medio);
    float distanciaDer = DAC_p(conjuntoPuntos, medio + 1, final);
    float d = min(distanciaIzq, distanciaDer);

    int inicioFranja = getInicioFranja(conjuntoPuntos, inicio, medio, d);
    int finalFranja = getFinalFranja(conjuntoPuntos, medio, final, d);

    float dFranja = minimoFranja(conjuntoPuntos, inicioFranja, finalFranja, d);
    return min(d, dFranja);
}

int main()
{
    int N;
    int D;
    cin >> N >> D;
    Punto *conjuntoPuntos = new Punto[N];

    for (int i = 0; i < N; i++)
    {
        int xInsert;
        int yInsert;
        cin >> xInsert >> yInsert;
        Punto pn(xInsert, yInsert);
        conjuntoPuntos[i] = pn;
    }

    mergeSort(conjuntoPuntos, 0, N - 1, compararPorX);
    float minimaDist = DAC_p(conjuntoPuntos, 0, N - 1);
    delete[] conjuntoPuntos;
    cout << ((minimaDist <= D) ? "true" : "false") << endl;
    return 0;
}