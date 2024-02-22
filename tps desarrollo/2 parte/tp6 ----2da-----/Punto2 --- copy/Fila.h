// fila.h
#ifndef FILA_H
#define FILA_H
#include <iostream>
#include "Nodo.h"

template <typename T>
class Fila
{
private:
    Nodo<T> *frente;
    Nodo<T> *final;

    // friend class IteradorDeFila;

public:
    // Constructor defecto crea fila vacía, (clase atributos)
    Fila()
    {
        frente = NULL;
        final = NULL;
    }

    // Constructor de copia
    Fila(const Fila &otraFila)
    {
        frente = nullptr;
        final = nullptr;

        Nodo<T> *actual = otraFila.frente;
        while (actual != nullptr)
        {
            Enfila(actual->valor);
            actual = actual->siguiente;
        }
    }

    // Destructor - libera la memoria.
    ~Fila()
    {
        while (!EsFilaVacia())
        {
            Defila();
        }
    }

    bool EsFilaVacia()
    {
        return frente == NULL;
    }

    // -> 1 2 3
    void Defila()
    {
        if (!EsFilaVacia())
        {
            Nodo<T> *temp = frente;
            frente = frente->siguiente;
            delete temp;
        }
    }

    void Enfila(T valor)
    {
        Nodo<T> *nuevoNodo = new Nodo<T>(valor);
        if (EsFilaVacia())
        {
            frente = final = nuevoNodo;
        }
        else
        {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
    }


    int Frente()
    {
        if (!EsFilaVacia())
        {
            return frente->valor;
        }
        // caso de error.
        throw std::runtime_error("fila vacia.");
    }

    int Longitud()
    {
        Nodo<T> *actual = frente;
        int length = 0;
        while (actual != nullptr)
        {
            length++;
            actual = actual->siguiente;
        }
        return length;
    }

    bool Pertenece(T valor)
    {
        Nodo<T> *actual = frente;
        while (actual != nullptr)
        {
            if (actual->valor == valor)
            {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    void Mostrar()
    {
        Nodo<T> *actual = frente;
        while (actual != NULL)
        {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    // contar ocurrencias
    // como usuario
    int ContarX(T X)
    {
        int contador = 0;
        Fila<T> copia(*this);

        while (!copia.EsFilaVacia())
        {
            T elemento = copia.Frente();
            copia.Defila();

            if (elemento == X)
            {
                contador++;
            }
        }

        return contador;
    }

    template <typename U>
    int ContarX(U X)
    {
        int contador = 0;
        Nodo<T> *actual = frente;

        while (actual != nullptr)
        {
            if (actual->valor == X)
            {
                contador++;
            }
            actual = actual->siguiente;
        }

        return contador;
    }

};

#endif // FILA_H