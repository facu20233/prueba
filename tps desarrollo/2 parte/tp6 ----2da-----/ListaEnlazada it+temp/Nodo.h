/*
 * Nodo.h
 *
 *  Created on: 12/12/2014
 *      Author: Graciela
 */

#ifndef NODO_H_
#define NODO_H_

#include <iostream>

template <typename T>
class Nodo {
    T dato;
    Nodo<T> *sig;

public:
    Nodo(T d, Nodo<T>* s = nullptr) : dato(d), sig(s) {}

    T getDato() const { return dato; }

    Nodo<T>* getSiguiente() const { return sig; }

    void setDato(T d) { dato = d; }

    void setSiguiente(Nodo<T>* s) { sig = s; }

    virtual ~Nodo() {}
};

#endif /* NODO_H_ */
