// Pila.h
#ifndef ITERADORPILA_H
#define ITERADORPILA_H
#include <iostream>
#include "Pila.h"
using namespace std;

template <typename T> class Pila; 

template <typename T>
class IteradorPila {
private:
    const Pila<T>& pila;
    int indice;

public:
    IteradorPila(const Pila<T>& p, int i) : pila(p), indice(i) {}

    // ¿Se llegó al final?
    bool Final() const
    {
        return indice < 0;
    }

    // Mover el iterador al siguiente elemento
    void Siguiente()
    {
        --indice;
    }

    // Obtener el valor del elemento actual
    T ValorActual() const
    {
        if (!Final())
        {
            return pila.arreglo[indice];
        }
        else
        {
            // Manejar un valor por defecto si se intenta acceder más allá del final
            cout << "Error: Índice fuera de rango." << endl;
            return T();
        }
    }
};

#endif
