// IteradorTradicional.h
#ifndef ITERADORTRADICIONAL_H
#define ITERADORTRADICIONAL_H

#include <iostream>
#include "Arreglo.h"
using namespace std;

class IteradorTradicional {
private:
    const Arreglo& arreglo;
    int indice;

public:
    IteradorTradicional(const Arreglo& a): 
        arreglo(a), indice(1) {}

    // ¿Se llegó al final?
    bool Final() const
    {
       return indice >= arreglo.MAX;
    }

    // Mover el iterador al siguiente elemento
    void Siguiente()
    {
       indice++;
    }

    // Obtener el valor del elemento actual
    int ValorActual() const
    {
        if (!Final()) {
            return arreglo.arreglo[indice];
        } else {
            // Manejar el caso cuando el iterador está fuera de rango
            cerr << "Error: Iterador fuera de rango." << endl;
            return arreglo.indefinido;
        }
    }
};

#endif
