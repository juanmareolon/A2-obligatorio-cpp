#include <string>
#include <iostream>
#include <limits>

using namespace std;

bool esSolucion(double* arrayCartas, int largoArray, double valorObjetivo){
    if(largoArray == 1 && arrayCartas[0] == valorObjetivo) return true;
    return false;
}

void hacerCalculo(double primerNro, double segundoNro, double& resultadoOperacion, char operador){
    switch (operador)
    {
    case '+':
        resultadoOperacion = primerNro + segundoNro;
        break;
    case '-':
        resultadoOperacion = primerNro - segundoNro; 
        break;
    case '*':
        resultadoOperacion = primerNro * segundoNro; 
        break;
    case '/':
        resultadoOperacion = primerNro / segundoNro;
    }
}

bool puedoAplicarMovimiento(int i, int j, double* arrayCartas, int largoArray, char operador){
    double primerNro = arrayCartas[i];
    double segundoNro = arrayCartas[j];
    double resultadoOperacion;
    hacerCalculo(primerNro, segundoNro, resultadoOperacion, operador);
    if(resultadoOperacion < 0)return false;
    else return resultadoOperacion == (int)resultadoOperacion;
}

double* copiarArray(double* arrayCartas, double* nuevoArray, int posI, int posJ, double resultadoOperacion, int largoArray){
    int k = 0;
    for (int p = 0; p < largoArray; p++)
    {
        if (p == posI)
        {
            nuevoArray[k++] = resultadoOperacion;
        }
        else if (p != posJ)
        {
            nuevoArray[k++] = arrayCartas[p];
        }
    }
    return nuevoArray;
}

void aplicarMovimiento(int i, int j, double*& arrayCartas, int& largoArray, char operador){
    double primerNro = arrayCartas[i];
    double segundoNro = arrayCartas[j];
    double* nuevoArray = new double[largoArray - 1];
    double resultadoOperacion;
    hacerCalculo(primerNro, segundoNro, resultadoOperacion, operador);
    nuevoArray = copiarArray(arrayCartas, nuevoArray, i, j, resultadoOperacion, largoArray);
    arrayCartas = nuevoArray;
    largoArray--;
}

void deshacerMovimiento(double* arrayAnterior, int largoAnterior, double*& arrayCartas, int& largoArray){
    delete[] arrayCartas;
    arrayCartas = arrayAnterior;
    largoArray = largoAnterior;
}

void BT_Decision(double *arrayCartas, int largoArray, bool &exito, double valorObjetivo)
{
    if (!exito)
    {
        if (esSolucion(arrayCartas, largoArray, valorObjetivo))
        {
            cout << 1 << endl;
            exito = true;
        }
        else
        {
            for (int i = 0; i < largoArray; i++)
            {
                for (int j = i + 1; j < largoArray; j++)
                {
                    for (int operacion = 0; operacion < 6; operacion++)
                    {
                        double* arrayAnterior = arrayCartas;
                        int largoAnterior = largoArray;
                        switch (operacion)
                        {
                        case 0:
                            if(puedoAplicarMovimiento(i, j, arrayCartas, largoArray,'+')){
                                aplicarMovimiento(i, j, arrayCartas, largoArray, '+');
                                BT_Decision(arrayCartas, largoArray, exito, valorObjetivo);
                                deshacerMovimiento(arrayAnterior, largoAnterior, arrayCartas, largoArray);

                            }
                            break;
                        case 1:
                            if(puedoAplicarMovimiento(i, j, arrayCartas, largoArray, '-')){
                                aplicarMovimiento(i, j, arrayCartas, largoArray, '-');
                                BT_Decision(arrayCartas, largoArray, exito, valorObjetivo);
                                deshacerMovimiento(arrayAnterior, largoAnterior, arrayCartas, largoArray);

                            }
                            break;
                        case 2:
                            if(puedoAplicarMovimiento(i, j, arrayCartas, largoArray, '*')){
                                aplicarMovimiento(i, j, arrayCartas, largoArray, '*');
                                BT_Decision(arrayCartas, largoArray, exito, valorObjetivo);
                                deshacerMovimiento(arrayAnterior, largoAnterior, arrayCartas, largoArray);

                            }
                            break;
                        case 3:
                            if(puedoAplicarMovimiento(i, j, arrayCartas, largoArray, '/')){
                                aplicarMovimiento(i, j, arrayCartas, largoArray, '/');
                                BT_Decision(arrayCartas, largoArray, exito, valorObjetivo);
                                deshacerMovimiento(arrayAnterior, largoAnterior, arrayCartas, largoArray);

                            }
                            break;
                        case 4:
                            if(puedoAplicarMovimiento(j, i, arrayCartas, largoArray, '/')){
                                aplicarMovimiento(j, i, arrayCartas, largoArray, '/');
                                BT_Decision(arrayCartas, largoArray, exito, valorObjetivo);
                                deshacerMovimiento(arrayAnterior, largoAnterior, arrayCartas, largoArray);

                            }
                            break;
                        case 5:
                            if(puedoAplicarMovimiento(j, i, arrayCartas, largoArray, '-')){
                                aplicarMovimiento(j, i, arrayCartas, largoArray, '-');
                                BT_Decision(arrayCartas, largoArray, exito, valorObjetivo);
                                deshacerMovimiento(arrayAnterior, largoAnterior, arrayCartas, largoArray);
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int n; // cantidadCartas
    cin >> n;
    double *valoresCartas = new double[n];
    double valorObjetivo;
    for (int i = 0; i < n; i++)
    {
        double dato;
        cin >> dato;
        valoresCartas[i] = dato;
    }
    cin >> valorObjetivo;
    bool exito = false;
    BT_Decision(valoresCartas, n, exito, valorObjetivo);
    if (!exito) cout<< 0 << endl;
    return 0;
}