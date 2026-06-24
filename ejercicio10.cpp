#include <string>
#include <iostream>
#include <limits>

using namespace std;


// todas las cartas deben ser utilizadas exactamente una vez.

bool esSolucion(int valorActual, int valorObjetivo){
    return valorActual == valorObjetivo; 
}

bool puedoAplicarMovimiento(double valorActual, int pos, int largoArray, char operador, double* arrayCartas){
    if(pos >= largoArray) return false;
    double resultadoOperacion;
    switch (operador)
    {
    case '+':
        resultadoOperacion = valorActual + arrayCartas[pos];
        break;
    case '-':
        resultadoOperacion = valorActual - arrayCartas[pos]; 
        break;
    case '*':
        resultadoOperacion = valorActual * arrayCartas[pos]; 
        break;
    case '/':
        resultadoOperacion = valorActual / arrayCartas[pos];
    }

    if(resultadoOperacion < 0)return false;
    else return resultadoOperacion == (int)resultadoOperacion;
}

void aplicarMovimiento(double &valorActual, int pos, double* arrayCartas, char operacion){
    switch (operador)
    {
    case '+':
        valorActual += arrayCartas[pos];
        break;
    case '-':
        valorActual -= arrayCartas[pos]; 
        break;
    case '*':
        valorActual *= arrayCartas[pos]; 
        break;
    case '/':
        valorActual /= arrayCartas[pos];
    }
}


void deshacerMovimiento(double &valorActual, int pos, double* arrayCartas, char operacion){
    switch (operador)
    {
    case '+':
        valorActual -= arrayCartas[pos];
        break;
    case '-':
        valorActual += arrayCartas[pos]; 
        break;
    case '*':
        valorActual /= arrayCartas[pos]; 
        break;
    case '/':
        valorActual *= arrayCartas[pos];
    }
}


void BT_Decision(double* arrayCartas, int largoArray, int pos, double valorActual, bool &exito, double valorObjetivo){
    if(!exito){
        if(esSolucion(valorActual, valorObjetivo)){
            cout << 1;
            exito = true;
        }
        else{
            for (int i = 0; i < 4; i++)
            {
                switch (i)
                {
                case 0:
                    if (puedoAplicarMovimiento(valorActual, pos + 1, largoArray,'+', arrayCartas)){
                    aplicarMovimiento(valorActual, pos + 1, arrayCartas, '+');
                    BT_Decision(arrayCartas, largoArray, pos + 1, valorActual, exito, valorObjetivo);
                    deshacerMovimiento(valorActual, pos + 1, arrayCartas, '+');
                    }
                    break;
                
                case 1:
                    /* code */
                    break;

                case 2:
                    /* code */
                    break;

                case 3:
                    /* code */
                    break;
                }
            }
        }
    }
}



int main(){ 
    int n; // cantidadCartas
    double* valoresCartas = new double[n];
    double valorObjetivo;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        double dato;
        cin >> dato;
        valoresCartas[i] = dato;
    }
    cin >> valorObjetivo;
    bool exito = false;
    BT_Decision(valoresCartas, n, 0, 0,exito,valorObjetivo)
        
    if(!exito) cout << 0;
    return 0;
}