// Pila.h
#ifndef ITERADORPAR_H
#define ITERADORPAR_H
#include <iostream>
#include "Arreglo.h"
using namespace std;

template<typename T>
class IteradorPar {
private:
    const Arreglo<T>& arreglo;
    int indice;

public:
    IteradorPar(const Arreglo<T>& a, int i): 
        arreglo(a), indice(i) {}

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
    T ValorActual() const
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
