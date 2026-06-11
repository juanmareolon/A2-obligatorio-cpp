#include <string>
#include <iostream>
#include <limits>

int maxFN (int a, int b){
    return (a > b) ? a : b;
}

using namespace std;

// Cada objeto tiene un peso, un volumen, un valor y una categoria (supervivencia o comida) 5 restricciones 

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



int main(){
    int n;
    int P;
    int V;
    int C;
    int S;
    int M;
    int cantidadObjSup = 0;
    int cantidadObjCom = 0;
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
    

    int****** tab = new int*****[n + 1]();
    for (int i = 0; i <= n; i++)
    {
        tab[i] = new int****[P + 1](); 
        for (int j = 0; j <= P; j++)
        {
            tab[i][j] = new int***[V + 1]();
            for (int k = 0; k <= V; k++)
            {
                tab[i][j][k] = new int**[C + 1]();
                for (int l = 0; l <= C; l++)
                {
                    tab[i][j][k][l] = new int*[S + 1];
                    for (int m = 0; m <= S; m++)
                    {
                        tab[i][j][k][l][m] = new int[M + 1]();
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
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
                            Objeto objetoConsiderar = listaObj[i];
                            
                            int categoriaConsiderar; 
                            int cantidadTipoObjeto;
                            
                            int valorObj = objetoConsiderar.valor;
                            int pesoObj = objetoConsiderar.peso;
                            int volumenObj = objetoConsiderar.volumen;
                            int costoObj = objetoConsiderar.costo;
                            int categoriaObj = objetoConsiderar.categoria;
                            
                            int valorMochila;
                            
                            if(categoriaObj == 0){
                                categoriaConsiderar = S;
                                cantidadTipoObjeto = cantidadObjSup;
                            }
                            else{
                                categoriaConsiderar = M;
                                cantidadTipoObjeto = cantidadObjCom;
                            }
                            
                            if(pesoObj > P || volumenObj > V || costoObj > C || cantidadTipoObjeto > categoriaConsiderar){
                                valorMochila = tab[i - 1][j][k][l][m][o];
                            }
                            else{
                                int usarObjeto;
                                if(categoriaObj == 0){
                                    usarObjeto = valorObj + tab[i - 1][j - pesoObj][k - volumenObj][l - costoObj][m - 1][o]; 
                                }
                                else{
                                    usarObjeto = valorObj + tab[i - 1][j - pesoObj][k - volumenObj][l - costoObj][m][o - 1];
                                }

                                int noUsarObjeto = tab[i -1][j][k][l][m][o];
                                valorMochila = maxFN(usarObjeto,noUsarObjeto);
                                if(valorMochila == usarObjeto && categoriaObj == 0){
                                    cantidadObjSup++;
                                }
                                else if(valorMochila == usarObjeto && categoriaObj == 1){
                                    cantidadObjCom++;
                                }
                            }
                            tab[i][j][k][l][m][o] = valorMochila;
                        }
                    }   
                }
            }
        }
    }
    
    int valorMax = tab[n][P][V][C][S][M];
    return 0;
}