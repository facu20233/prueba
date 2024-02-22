/*
 * Lista.h
 *
 *  Created on: 12/12/2014
 *      Author: Graciela
 */

#ifndef LISTA_H_
#define LISTA_H_

#include "Nodo.h"
#include <iostream>

template <typename T>
class Iterador;

template <typename T>
class Lista {
    Nodo<T>* lista;
    int longitud;

public:
    Lista() : lista(nullptr), longitud(0) {}

    void insertar(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato, lista);
        lista = nuevo;
        longitud++;
    }

    void borrar() {
        if (!esVacia()) {
            Nodo<T>* aux = lista;
            lista = lista->getSiguiente();
            delete aux;
            longitud--;
        }
    }

    T elemento() {
        if (!esVacia())
            return lista->getDato();
        else
            return T();  // Devolver un valor predeterminado para el tipo T (posiblemente, se podría lanzar una excepción aquí)
    }

    int cantidad() const { return longitud; }

    bool esVacia() const { return longitud == 0; }

    virtual ~Lista() {
        for (int i = 0; i < longitud; i++)
            borrar();
    }

    void escribir() const {
        std::cout << "Lista: ";
        for (Nodo<T>* aux = lista; aux != nullptr; aux = aux->getSiguiente()) {
            std::cout << aux->getDato() << " ";
        }
        std::cout << std::endl;
    }

    friend class Iterador<T>;
};

#endif /* LISTA_H_ */
