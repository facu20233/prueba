// Programa.cpp
#include <iostream>
#include "Pila.h"
#include "IteradorPila.h"
using namespace std;


int main()
{
    // Crear una pila de enteros
    Pila<int> pilaEnteros;

    // Push: Agregar elementos a la pila
    pilaEnteros.push(10);
    pilaEnteros.push(20);
    pilaEnteros.push(30);

    // Mostrar el contenido de la pila
    cout << "Pila de enteros:" << endl;
    pilaEnteros.escribir();

    // Top: Obtener el elemento superior de la pila
    cout << "Elemento superior de la pila de enteros: " << pilaEnteros.top() << endl;

    // Pop: Eliminar el elemento superior de la pila
    pilaEnteros.pop();

    // Mostrar el contenido de la pila después de pop
    cout << "Pila después de pop:" << endl;
    pilaEnteros.escribir();

    // Verificar si la pila está vacía
    if (pilaEnteros.esPilaVacia())
    {
        cout << "La pila de enteros está vacía." << endl;
    }
    else
    {
        cout << "La pila de enteros no está vacía." << endl;
    }

    cout << "------ ITERADOR ------" << endl;

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
    IteradorPila<int> iterador(pilaEnteros, pilaEnteros.top() - 1);

    // Iterar sobre la pila e imprimir los valores
    while (!iterador.Final()) {
        cout << "Elemento actual: " << iterador.ValorActual() << endl;
        iterador.Siguiente();
    }

    return 0;
}