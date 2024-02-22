#include <iostream>
#include "Arreglo.h"
#include "IteradorPar.h"

void EscribirPares(Arreglo &arreglo, int i);

int main() {
    // Crear un objeto de la clase Arreglo
    Arreglo miArreglo(10, -1);
    miArreglo.escribir();

    // Llenar el arreglo con algunos valores
    for (int i = 1; i <= 10; i++) {
        miArreglo[i] = i;  
    }

    miArreglo.escribir();

    EscribirPares(miArreglo, 1);

    return 0;
}

void EscribirPares(Arreglo &arreglo, int i){
    // Crear un iterador de pares
    IteradorPar iterador(arreglo, 1);

    // Usar el iterador para imprimir los valores del arreglo
    while (!iterador.Final()) {
        std::cout << "Valor actual: " << iterador.ValorActual() << std::endl;
        iterador.Siguiente();
    }
}