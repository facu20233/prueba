// programa.cpp
#include <iostream>
#include "Arreglo.h"
#include "IteradorPar.h"
using namespace std;

void EscribirPares(Arreglo& arreglo, int i);

int main(){
    Arreglo miArreglo(10,2);
    miArreglo.escribir();

    for (int i = 1; i <= 10; i++)
    {
        miArreglo[i] = i; // [1234]
    }
    miArreglo.escribir();

    IteradorPar iteradorPar(miArreglo, 1);

    while (!iteradorPar.Final())
    {
        cout << "Elemento actual" << iteradorPar.ValorActual() << endl;
        iteradorPar.Siguiente();
    }
    
    EscribirPares(miArreglo, 1);
    

    return 0;
}

void EscribirPares(Arreglo& arreglo, int i){
    IteradorPar iteradorPar (arreglo, i);
    while (!iteradorPar.Final())
    {
        cout << "Elemento actual" << iteradorPar.ValorActual() << endl;
        iteradorPar.Siguiente();
    }
}