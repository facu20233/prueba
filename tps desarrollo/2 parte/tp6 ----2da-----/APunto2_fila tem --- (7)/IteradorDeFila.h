// iteradorDeFila.h
#ifndef ITERADORDEFILA_H
#define ITERADORDEFILA_H
#include <iostream>
#include "Fila.h"
#include "Nodo.h"
using namespace std;

template <typename T> class Fila;

template <typename T>
class IteradorDeFila
{
private:
    Nodo<T> *actual; // Puntero al nodo actual
    const Fila<T> &fila;
    
public:
    IteradorDeFila(Fila<T> &fila) : fila(fila)
    {
        actual = fila.frente; // Inicializar primer elemento
    }

    // ¿Se llegó al final?
    bool Final()
    {
        return actual == nullptr;
    }

    // Mover el iterador al siguiente elemento
    void Siguiente()
    {
        if (!Final())
        {
            actual = actual->siguiente;
        }
    }

    // Obtener el valor del elemento actual
    T ValorActual()
    {
        if (!Final())
        {
            return actual->valor;
        }
        throw runtime_error("Iterador llegó al final de la fila.");
    }
};

#endif