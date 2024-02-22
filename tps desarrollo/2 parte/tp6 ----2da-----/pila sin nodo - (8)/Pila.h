// Pila.h
#ifndef PILA_H
#define PILA_H
#include <iostream>
#include "IteradorPila.h"
// #include "Nodo.h" no usa nodo
using namespace std;

template <typename T> class IteradorPila;

template <typename T>
class Pila
{
private:
    static const int MAX = 100;
    T arreglo[MAX];
    int tope;
    friend class IteradorPila<T>;
public:
    Pila() : tope(-1) {}

    ~Pila()
    {
        // No es necesario liberar memoria en este caso, ya que no hay nodos dinámicos.
    }

    Pila(const Pila<T> &otra)
    {
        // Copiar elementos desde la otra pila
        tope = otra.tope;
        for (int i = 0; i <= tope; ++i)
        {
            arreglo[i] = otra.arreglo[i];
        }
    }

    void push(T val)
    {
        if (tope < MAX - 1)
        {
            arreglo[++tope] = val;
        }
        else
        {
            cout << "Error: La pila está llena." << endl;
        }
    }

    void pop()
    {
        if (tope >= 0)
        {
            --tope;
        }
        else
        {
            cout << "Error: La pila está vacía." << endl;
        }
    }

    T top() const
    {
        if (tope >= 0)
        {
            return arreglo[tope];
        }
        else
        {
            cout << "Error: La pila está vacía." << endl;
            // Devolver un valor por defecto en este caso
            return T();
        }
    }

    bool esPilaVacia()
    {
        return tope == -1;
    }

    void escribir()
    {
        if (esPilaVacia())
        {
            cout << "La pila está vacía." << endl;
        }
        else
        {
            cout << "Contenido de la pila:" << endl;
            for (int i = 0; i <= tope; ++i)
            {
                cout << arreglo[i] << " ";
            }
            cout << endl;
        }
    }
};

#endif