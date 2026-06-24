#include <string>
#include <iostream>
#include <limits>
#include <cmath>

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

void merge(Punto *puntos, int inicio, int medio, int fin, bool porY)
{
    int tamano = fin - inicio + 1;
    Punto *aux = new Punto[tamano];
    int i = inicio;
    int j = medio + 1;
    int k = 0;
    while (i <= medio && j <= fin)
    {
        if (porY)
        {
            if (puntos[i].y <= puntos[j].y)
            {
                aux[k] = puntos[i];
                i++;
            }
            else
            {
                aux[k] = puntos[j];
                j++;
            }
        }
        else
        {
            if (puntos[i].x <= puntos[j].x)
            {
                aux[k] = puntos[i];
                i++;
            }
            else
            {
                aux[k] = puntos[j];
                j++;
            }
        }
        k++;
    }
    while (i <= medio)
    {
        aux[k] = puntos[i];
        i++;
        k++;
    }
    while (j <= fin)
    {
        aux[k] = puntos[j];
        j++;
        k++;
    }
    for (int x = 0; x < tamano; x++)
    {
        puntos[inicio + x] = aux[x];
    }
    delete[] aux;
}

void mergeSortPuntos(Punto *puntos, int inicio, int fin, bool porY)
{
    if (inicio >= fin) return;
    int medio = (inicio + fin) / 2;
    mergeSortPuntos(puntos, inicio, medio, porY);
    mergeSortPuntos(puntos, medio + 1, fin, porY);
    merge(puntos, inicio, medio, fin, porY);
}

float min(float a, float b)
{
    return (a < b) ? a : b;
}

float minimoFranja(Punto *conjuntoPuntos, int inicio, int fin, float d)
{
    int N = fin - inicio + 1;
    mergeSortPuntos(conjuntoPuntos, 0, N - 1, true);

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

    mergeSortPuntos(conjuntoPuntos, 0, N - 1, false);
    float minimaDist = DAC_p(conjuntoPuntos, 0, N - 1);
    delete[] conjuntoPuntos;
    cout << ((minimaDist <= D) ? "true" : "false") << endl;
    return 0;
}