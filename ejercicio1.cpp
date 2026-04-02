#include <cassert>
#include <string>
#include <iostream>
#include <limits>
using namespace std;


 int hashLetrasMin(char c) {
        return (int)(c - 'a');
    }

 int hashLetrasMay(char c){
        return (int)(c - 'A');
 }
int main()
{
    int* cantLlaves = new int[26]();
    int cantSalas = 0;
    int llavesNecesarias = 0;
    string salasLlaves = "";
    cin >> cantSalas;
    cin >> salasLlaves;


    for (int i = 0; i < 2*(cantSalas-1); i+= 2){
        cantLlaves[hashLetrasMin(salasLlaves[i])]++;

        int tipoSala = hashLetrasMay(salasLlaves[i+1]);
        if(cantLlaves[tipoSala] > 0) {
            cantLlaves[tipoSala]--;
        } else {
            llavesNecesarias++;
        }
    }
    
    
    delete[] cantLlaves;
    cout << llavesNecesarias << endl;
    return 0;
}