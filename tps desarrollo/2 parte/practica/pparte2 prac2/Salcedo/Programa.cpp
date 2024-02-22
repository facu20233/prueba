// Programa.cpp
#include <iostream>
#include "Arreglo.h"
#include "IteradorPar.h"
using namespace std;

int IteradorParMostrar(Arreglo &arre, int i);

int main()
{
    Arreglo MiArreglo(5, 1);
    MiArreglo.escribir();

    MiArreglo[1] = 1;
    MiArreglo[2] = 2;
    MiArreglo[3] = 3;
    MiArreglo[4] = 4;
    MiArreglo[5] = 5;
    MiArreglo.escribir();

    cout << "---- iterador ----" << endl;
    IteradorPar MiIteradorPar(MiArreglo, 1);

    while (!MiIteradorPar.Final())
    {
        cout << MiIteradorPar.ValorActual() << " " << endl;
        MiIteradorPar.Siguiente();
    }
    cout << " " << endl;

    IteradorParMostrar(MiArreglo, 1);


    return 0;
}

int IteradorParMostrar(Arreglo &arre, int i)
{

    IteradorPar MiIteradorPar(arre, i);

    cout << "---- IteradorParMostrar ----" << endl;
    while (!MiIteradorPar.Final())
    {
        cout << MiIteradorPar.ValorActual() << " " << endl;
        MiIteradorPar.Siguiente();
    }
    cout << " " << endl;
}