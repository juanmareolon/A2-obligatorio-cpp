#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

int posLetrasMin(char c) {
    return (int)(c - 'a');
}
int verificarM(int* cantLetras){
    int res = 0;
    for(int i = 0; i<=25; i++){
        if (cantLetras[i]> res) res = cantLetras[i];
    }
    return res;
}

int main()
{
    string letras;
    cin >> letras;

    int R = letras.length();
    int N = letras.length();

    int* cantLetras = new int [26]();

    for (int i = 0; i < R; i++){
        int pos = posLetrasMin(letras[i]);
        cantLetras[pos]++;
    }

    int M = verificarM(cantLetras);

    string res = "";

    for (int i = 0; i < N; i++)
    {
        if(2*M > R+1) 
        {
            res = "Imposible";
            break;
        }
        for (int j = 25; j >= 0 ; j--)
        {
            if(cantLetras[j]>0 && (i == 0 || res[i-1] != (char)j+97)){
                cantLetras[j]--;
                R--;
                M = verificarM(cantLetras);
                if(2*M <= R+1){
                    res+=(char)(j+'a');
                    break;
                } 
                else{
                    cantLetras[j]++;
                    R++;
                    M = verificarM(cantLetras);
                }
            } 
        } 
    }

    cout << res << endl;

    delete[] cantLetras;
    
    return 0;
}