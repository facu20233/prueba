// Pila.h
#ifndef PILA_H
#define PILA_H
#include <iostream>
#include "IteradorPila.h"
#include "Nodo.h"
using namespace std;

template <typename T> class IteradorPila;

template <typename T>
class Pila
{
private:
    Nodo<T> *tope;
    friend class IteradorPila<T>;

public:
    Pila() : tope(nullptr) {}

    ~Pila()
    {
        while (!esPilaVacia())
        {
            pop();
        }
    }

    void push(T val)
    {
        Nodo<T> *nuevoNodo = new Nodo<T>(val);
        nuevoNodo->siguiente = tope;
        tope = nuevoNodo;
    }

    void pop()
    {
        if (!esPilaVacia())
        {
            Nodo<T> *temp = tope;
            tope = tope->siguiente;
            delete temp;
        }
    }

    T top() const
    {
        if (!esPilaVacia())
        {
            return tope->valor;
        }
        // Manejar el caso en el que la pila esté vacía según tus necesidades
        // Por ejemplo, podrías lanzar una excepción o devolver un valor predeterminado.
    }

    bool esPilaVacia() const
    {
        return tope == nullptr;
    }

    void escribir()
    {
        Nodo<T> *temp = tope;
        while (temp != nullptr)
        {
            cout << temp->valor << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }

    Nodo<T>* obtenerTope() const {
        return tope;
    }
};

#endif