// iteradorDeFila.h
#ifndef ITERADORDEFILA_H
#define ITERADORDEFILA_H
#include <iostream>
#include "Fila.h"
using namespace std;

template <typename T> class Fila;

template <typename T>
class IteradorDeFila
{
private:
    Nodo<T> *actual; // Puntero al nodo actual
    
public:
    IteradorDeFila(Fila<T> &fila)
    {
        actual = fila.frente; // Inicializar prim elemento
    }

    // si llego al final?
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
    
    // int ContarXIterador(Fila &fila, int X)
    // {
    //     int contador = 0;

    //     IteradorDeFila iterador(fila);

    //     while (!iterador.Final())
    //     {
    //         int elemento = iterador.ValorActual();
    //         if (elemento == X)
    //         {
    //             contador++;
    //         }
    //         iterador.Siguiente();
    //     }

    //     return contador;
    // }

};

#endif