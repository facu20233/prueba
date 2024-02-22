#include <iostream>
#include "Fila.h"
#include "Nodo.h"



int main()
{
    Fila MiFila;
    MiFila.Enfila(1);
    MiFila.Enfila(2);
    MiFila.Enfila(2);
    MiFila.Enfila(3);
    MiFila.Enfila(4);

    // mostrar
    std::cout << "Elementos fila: ";
    MiFila.Mostrar();

    // pertenece
    int valor = 4;
    bool pertenece = MiFila.Pertenece(valor);
    std::cout << "¿El valor " << valor << " pertenece a la fila? " << (pertenece ? "Sí" : "No") << std::endl;


    return 0;
}