// Programa.cpp
#include <iostream>
#include "Nodo.h"
#include "Pila.h"
#include "IteradorPila.h"
using namespace std;


int main() {
    // Crear una pila de enteros
    Pila<int> pilaEnteros;

    // Agregar elementos a la pila
    pilaEnteros.push(10);
    pilaEnteros.push(20);
    pilaEnteros.push(30);

    // Mostrar el contenido de la pila
    cout << "Pila de enteros:" << endl;
    pilaEnteros.escribir();

    // Crear un iterador para la pila
    IteradorPila<int> iterador(pilaEnteros);

    cout << "------ ITERADOR ------" << endl;

    // Iterar sobre la pila e imprimir los valores
    while (!iterador.Final()) {
        cout << "Elemento actual: " << iterador.ValorActual() << endl;
        iterador.Siguiente();
    }

    return 0;
}