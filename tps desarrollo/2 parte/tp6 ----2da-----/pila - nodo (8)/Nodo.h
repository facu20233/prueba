// Nodo.h
#ifndef NODO_H
#define NODO_H
#include <iostream>

template <typename T> class Pila; //importante
template <typename T> class IteradorPila;

template <typename T>
class Nodo {
private:
    T valor;
    Nodo<T>* siguiente;
    friend class Pila<T>;
    friend class IteradorPila<T>;

public:
    Nodo(T val) {
        valor = val;
        siguiente = nullptr;
    }
};

#endif