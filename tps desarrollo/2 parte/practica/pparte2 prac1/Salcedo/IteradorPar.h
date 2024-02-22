// iteradorPar.h
#ifndef ITERADORPAR_H
#define ITERADORPAR_H
#include <iostream>
#include "Arreglo.h"
using namespace std;

class Arreglo;

class IteradorPar
{
private:
    const Arreglo& arre;
    int indice; // Puntero al nodo actual

public:
    IteradorPar(const Arreglo& a, int i) : arre(a), indice(i) {}

    bool Final() const
    {
        return indice >= arre.MAX;
    }

    void Siguiente()
    {
        indice += 2;
    }

    // Obtener el valor del elemento actual
    int ValorActual() const
    {
        if (!Final())
        {
            return arre.arreglo[indice];
        }
        else
        {
            // Manejar un valor por defecto si se intenta acceder más allá del final
            cout << "Error: Índice fuera de rango." << endl;
            return -1;
        }
    }
};

#endif