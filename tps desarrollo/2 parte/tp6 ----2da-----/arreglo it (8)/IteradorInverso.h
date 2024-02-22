// IteradorInverso.h
#ifndef ITERADORINVERSO_H
#define ITERADORINVERSO_H

#include <iostream>
#include "Arreglo.h"
using namespace std;

class IteradorInverso {
private:
    const Arreglo& arreglo;
    int indice;

public:
    IteradorInverso(const Arreglo& a): 
        arreglo(a), indice(a.MAX - 1) {}

    // ¿Se llegó al final?
    bool Final() const
    {
       return indice < 1;
    }

    // Mover el iterador al siguiente elemento
    void Siguiente()
    {
       indice--;
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
