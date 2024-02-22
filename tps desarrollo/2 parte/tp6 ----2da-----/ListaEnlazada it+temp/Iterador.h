/*
 * Iterador.h
 *
 *  Created on: 12/12/2014
 *      Author: Graciela
 */

#ifndef ITERADOR_H_
#define ITERADOR_H_

#include "Lista.h"

template <typename T>
class Iterador
{
    const Lista<T> &listaEnlazada;
    Nodo<T> *actual;

public:
    Iterador(const Lista<T> &l) : listaEnlazada(l), actual(l.lista) {}

    bool hayMasElementos()
    {
        return actual != nullptr;
    }

    T elementoActual()
    {
        return actual->getDato();
    }

    void avanzar()
    {
        actual = actual->getSiguiente();
    }
};

#endif /* ITERADOR_H_ */
