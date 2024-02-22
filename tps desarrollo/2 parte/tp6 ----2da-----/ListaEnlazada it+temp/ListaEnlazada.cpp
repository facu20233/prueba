//============================================================================
// Name        : ListaEnlazada.cpp
// Author      : CW
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Lista.h"
#include "Iterador.h"

#define MAX 5
using namespace std;

template <typename T>
bool pertenece(Lista<T> &l, T x);

int main() {

    Lista<int> l1; // Especifica el tipo de dato para la lista
    int i;
    for (i = 1; i <= MAX; i++) {
        l1.insertar(i);
    }

    l1.escribir();

    if (l1.esVacia())
        cout << "Lista vacia" << endl;
    else
        cout << "Lista con elementos" << endl;

    cout << endl << "Escribo la lista desde el main con ITERADOR" << endl;
    Iterador<int> it(l1); // Especifica el tipo de dato para el iterador
    for (; it.hayMasElementos(); it.avanzar()) {
        cout << it.elementoActual() << " - ";
    }
    cout << endl;

    if (l1.esVacia())
        cout << "Lista vacia" << endl;
    else
        cout << "Lista con elementos" << endl;

    if (pertenece(l1, 4))
        cout << "Pertenece" << endl;
    else
        cout << "NO Pertenece" << endl;

    return 0;
}

template <typename T>
bool pertenece(Lista<T> &l, T x)
{
    Iterador<T> it(l);
    bool resultado = false;
    while (!resultado && it.hayMasElementos()) {
        resultado = it.elementoActual() == x;
        it.avanzar();
    }
    return resultado;
}
