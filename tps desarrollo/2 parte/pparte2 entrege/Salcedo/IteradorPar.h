// Pila.h
#ifndef ITERADORPAR_H
#define ITERADORPAR_H
#include <iostream>
#include "Arreglo.h"
using namespace std;

class IteradorPar {
private:
    const Arreglo& arreglo;
    int indice;

public:
    IteradorPar(const Arreglo& a, int i) : arreglo(a), indice(i) {}

    // ¿Se llegó al final?
    bool Final() const
    {
        return indice < 0;
    }

    // Mover el iterador al siguiente elemento
    void Siguiente()
    {
        indice = indice - 2;
    }

    // Obtener el valor del elemento actual
    int ValorActual() const
    {
        if (!Final())
        {
            return indice;
        }
        else
        {
            // Manejar un valor por defecto si se intenta acceder más allá del final
            cout << "Error: Índice fuera de rango." << endl;
        }
    }
};

#endif
