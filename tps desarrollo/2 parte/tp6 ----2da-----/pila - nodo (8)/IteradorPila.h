// IteradorPila.h
#ifndef ITERADORPILA_H
#define ITERADORPILA_H
#include <iostream>
#include "Pila.h"
using namespace std;



template <typename T>
class IteradorPila {
private:
    const Pila<T>& pila;
    Nodo<T>* nodoActual;

public:
    IteradorPila(const Pila<T>& p) : pila(p), nodoActual(p.obtenerTope()) {}

    // ¿Se llegó al final?
    bool Final() const
    {
        return nodoActual == nullptr;
    }

    // Mover el iterador al siguiente elemento
    void Siguiente()
    {
        if (!Final())
        {
            nodoActual = nodoActual->siguiente;
        }
    }

    // Obtener el valor del elemento actual
    T ValorActual() const
    {
        if (!Final())
        {
            return nodoActual->valor;
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
