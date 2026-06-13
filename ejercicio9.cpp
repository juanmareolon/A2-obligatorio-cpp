#include <string>
#include <iostream>
#include <limits>

using namespace std;

struct Objeto{
    int peso;
    int volumen;
    int costo;
    int valor;
    int categoria; // 0 es Supervivencia y 1 es Comida
    
    Objeto(int _peso, int _volumen, int _costo, int _valor, int _categoria){
        peso = _peso;
        volumen = _volumen;
        costo = _costo;
        valor = _valor;
        categoria = _categoria;
    }
    
    Objeto(){}
};

struct nodoMatriz{
    int valor;
    int peso;
    int cantObjetos;
    
    nodoMatriz(){
        valor = 0;
        peso = 0;
        cantObjetos = 0;
    }
};

nodoMatriz mejorFN(nodoMatriz opcionUsar, nodoMatriz opcionNoUsar){
    if (opcionUsar.valor != opcionNoUsar.valor)
        return (opcionUsar.valor > opcionNoUsar.valor) ? opcionUsar : opcionNoUsar;

    if (opcionUsar.peso != opcionNoUsar.peso)
        return (opcionUsar.peso < opcionNoUsar.peso) ? opcionUsar : opcionNoUsar;

    return (opcionUsar.cantObjetos < opcionNoUsar.cantObjetos) ? opcionUsar : opcionNoUsar;
}

int main(){
    int n;
    int P;
    int V;
    int C;
    int S;
    int M;
    cin >> n >> P >> V >> C >> S >> M;

    Objeto* listaObj = new Objeto[n + 1];

    for (int i = 1; i <= n; i++)
    {
        int vPeso, vVolumen, vCosto, vValor, vCategoria;
        string categoria;
        cin >> vPeso >> vVolumen >> vCosto >> vValor >> categoria; 
        (categoria == "supervivencia") ? vCategoria = 0 : vCategoria = 1;
        
        Objeto objInsert(vPeso,vVolumen,vCosto,vValor,vCategoria);
        listaObj[i] = objInsert;
    }
    
    nodoMatriz****** tab = new nodoMatriz*****[n + 1]();
    for (int i = 0; i <= n; i++)
    {
        tab[i] = new nodoMatriz****[P + 1](); 
        for (int j = 0; j <= P; j++)
        {
            tab[i][j] = new nodoMatriz***[V + 1]();
            for (int k = 0; k <= V; k++)
            {
                tab[i][j][k] = new nodoMatriz**[C + 1]();
                for (int l = 0; l <= C; l++)
                {
                    tab[i][j][k][l] = new nodoMatriz*[S + 1]();
                    for (int m = 0; m <= S; m++)
                    {
                        tab[i][j][k][l][m] = new nodoMatriz[M + 1]();
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        Objeto objetoConsiderar = listaObj[i];

        int valorObj = objetoConsiderar.valor;
        int pesoObj = objetoConsiderar.peso;
        int volumenObj = objetoConsiderar.volumen;
        int costoObj = objetoConsiderar.costo;
        int categoriaObj = objetoConsiderar.categoria;
        for (int j = 0; j <= P; j++)
        {
            for (int k = 0; k <= V; k++)
            {
                for (int l = 0; l <= C; l++)
                {
                    for (int m = 0; m <= S; m++)
                    {
                        for (int o = 0; o <= M; o++)
                        {
                            nodoMatriz mejorCombinacion;
                            nodoMatriz anterior;
                            nodoMatriz usarObjeto;
                            nodoMatriz noUsarObjeto;                
                            noUsarObjeto = tab[i-1][j][k][l][m][o];

                            if(pesoObj > j || volumenObj > k || costoObj > l || (categoriaObj == 0 && m == 0) || (categoriaObj == 1 && o == 0)){
                                mejorCombinacion = noUsarObjeto;
                            }
                            else{
                                if(categoriaObj == 0){
                                    anterior = tab[i - 1][j - pesoObj][k - volumenObj][l - costoObj][m - 1][o]; 
                                }
                                else{
                                    anterior = tab[i - 1][j - pesoObj][k - volumenObj][l - costoObj][m][o - 1];
                                }
                                usarObjeto.valor = anterior.valor + valorObj;
                                usarObjeto.peso = anterior.peso + pesoObj;
                                usarObjeto.cantObjetos = anterior.cantObjetos + 1;
                                mejorCombinacion = mejorFN(usarObjeto, noUsarObjeto);
                            }
                            tab[i][j][k][l][m][o] = mejorCombinacion;
                        }
                    }   
                }
            }
        }
    }
    nodoMatriz mejor = tab[n][P][V][C][S][M];
    int valorMax = mejor.valor;
    int pesoMin = mejor.peso;
    int cantidadObjMin = mejor.cantObjetos;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= P; j++)
        {
            for (int k = 0; k <= V; k++)
            {
                for (int l = 0; l <= C; l++)
                {
                    for (int m = 0; m <= S; m++)
                    {
                        delete[] tab[i][j][k][l][m];
                    }
                    delete[] tab[i][j][k][l];
                }
                delete[] tab[i][j][k];
            }
            delete[] tab[i][j];
        }
        delete[] tab[i];
    }
    delete[] tab;
    cout << valorMax << " " << pesoMin << " " << cantidadObjMin << endl;
    return 0;
}