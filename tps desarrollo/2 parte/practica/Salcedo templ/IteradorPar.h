// Pila.h
#ifndef ITERADORPAR_H
#define ITERADORPAR_H
#include <iostream>
#include "Arreglo.h"
using namespace std;


template <typename T>
class IteradorPar
{
private:
    const Arreglo<T> &arreglo;
    int indice;

public:
    IteradorPar(const Arreglo<T> &a) : arreglo(a) {
        indice = 1;
    }

    // ¿Se llegó al final?
    bool Final() const
    {
        if (indice < arreglo.MAX)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    // Mover el iterador al siguiente elemento
    void Siguiente()
    {
        if (!Final())
        {
            indice = indice+2;
        }
    }

    // Obtener el valor del elemento actual
    T ValorActual() const
    {
        if (!Final())
        {
            return arreglo.arreglo[indice];
        }
        else
        {
            // Manejar el caso cuando el iterador está fuera de rango
            cerr << "Error: Iterador fuera de rango." << endl;
            return arreglo.indefinido;
        }
    }
};

#endif
