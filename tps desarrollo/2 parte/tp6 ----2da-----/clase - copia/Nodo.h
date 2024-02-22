#ifndef NODO_H
#define NODO_H
#include <iostream>

// ADT FILA(entero)
class Nodo {
private: //probar private
    int valor;
    Nodo* siguiente; 
    friend class Fila; 

public:
    // constructor parametro
    Nodo(int val){
        valor = val;
        siguiente = NULL;
    }

};

#endif