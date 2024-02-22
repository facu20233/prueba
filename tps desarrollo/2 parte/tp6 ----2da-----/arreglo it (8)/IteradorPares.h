// IteradorPares.h
#ifndef ITERADORPARES_H
#define ITERADORPARES_H

#include <iostream>
#include "Arreglo.h"
using namespace std;

class IteradorPares {
private:
    const Arreglo& arreglo;
    int indice;

public:
    IteradorPares(const Arreglo& a): 
        arreglo(a), indice(2) {}

    // ¿Se llegó al final?
    bool Final() const
    {
       return indice >= arreglo.MAX;
    }

    // Mover el iterador al siguiente elemento
    void Siguiente()
    {
       indice += 2;
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
