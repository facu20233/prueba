// programa.cpp
#include <iostream>
#include "VectorDinamico.h"
using namespace std;

int main(){
    // Ejemplo de uso
    VectorDinamico<int> miVector(5);
    miVector.imprimirVector();
    // Construir un vector como copia de otro
    VectorDinamico<int> otroVector(miVector);

    // Seleccionar la capacidad del vector
    miVector.seleccionarCapacidad(8);

    // Insertar elementos
    miVector.insertarAlFinal(42);
    miVector.insertarAlPrincipio(99);
    miVector.insertarEnPosicion(2, 777);

    // Imprimir el contenido del vector
    miVector.imprimirVector();

    // cout << "Vector: ";
    otroVector.imprimirVector();

    // ---------------------------

    VectorDinamico<string> miVectorString(2);
    miVectorString.imprimirVector();
    miVectorString.seleccionarCapacidad(10);
    miVectorString.insertarAlPrincipio("hola");
    miVectorString.insertarAlPrincipio("hola1");
    miVectorString.insertarAlPrincipio("hola2");
    miVectorString.insertarAlPrincipio("hola3");
    miVectorString.imprimirVector();

    // ---------------------------------

    // Verificar si un elemento pertenece al vector
    int elementoBuscado = 42;
    if (miVector.pertenece(miVector, elementoBuscado)) {
        cout << "El elemento " << elementoBuscado << " pertenece al vector." << endl;
    } else {
        cout << "El elemento " << elementoBuscado << " no pertenece al vector." << endl;
    }

    // Encontrar el máximo elemento en el vector
    try {
        int maximo = miVector.max(miVector);
        cout << "El máximo elemento en el vector es: " << maximo << endl;
    } catch (const std::out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}

