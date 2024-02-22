#include <iostream>
#include "fila.h"

int main() {
    Fila fila;
    fila.Enfila(1);
    fila.Enfila(2);
    fila.Enfila(2);
    fila.Enfila(3);
    fila.Enfila(4);
    
    // mostrar
    std::cout << "Elementos fila: ";
    fila.Mostrar();

    // pertenece
    int valor = 4;
    bool pertenece = fila.Pertenece(valor);
    std::cout << "¿El valor " << valor << " pertenece a la fila? " << (pertenece ? "Sí" : "No") << std::endl;

    return 0;
}