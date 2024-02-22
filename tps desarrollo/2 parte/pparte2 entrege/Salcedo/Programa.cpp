// Programa.cpp
#include <iostream>
#include "Arreglo.h"
#include "IteradorPar.h"
using namespace std;

void EscribirPositivos(Arreglo &arreglo, int i);

int main()
{
    Arreglo arregloEntero(5,2);
    arregloEntero.capacidad();
    arregloEntero.escribir();
    arregloEntero.escribirPos();

    IteradorPar iteradorPar(arregloEntero, arregloEntero.Primer());

    while (!iteradorPar.Final())
    {
        cout << "Elemento actual: " << iteradorPar.ValorActual() << endl;
        iteradorPar.Siguiente();
    }

    return 0;
}

void EscribirPositivos(Arreglo &arreglo, int i){
    IteradorPar iteradorPar(arreglo, i);
    while (!iteradorPar.Final()) {
        int elemento = iteradorPar.ValorActual();
         cout << "Elemento actual: " << iteradorPar.ValorActual() << endl;
        iteradorPar.Siguiente();
    }
}