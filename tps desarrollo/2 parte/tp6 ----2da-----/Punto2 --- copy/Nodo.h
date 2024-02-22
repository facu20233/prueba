// Nodo.h
#ifndef NODO_H
#define NODO_H
#include <iostream>

template <typename T> class Fila; //importante

template <typename T>
class Nodo {
private:
    T valor;
    Nodo<T>* siguiente;
    friend class Fila<T>;
    // friend class IteradorDeFila<T>;

public:
    Nodo(T val) {
        valor = val;
        siguiente = nullptr;
    }
};

#endif