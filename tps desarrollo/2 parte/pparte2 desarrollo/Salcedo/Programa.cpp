#include <iostream>
#include "Arreglo.h"
#include "IteradorPar.h"

void EscribirPares(Arreglo &arreglo);

int main() {
    Arreglo miArreglo(7, 1);
    miArreglo.escribir();

    miArreglo[1] = -2;
    miArreglo[2] = -1;
    miArreglo[3] = 0;
    miArreglo[4] = 1;
    miArreglo[5] = 2;
    miArreglo[6] = 3;
    miArreglo[7] = 4;

    miArreglo.escribir();

    EscribirPares(miArreglo);

    return 0;
}

void EscribirPares(Arreglo &arreglo){
    
    IteradorPar iterador(arreglo);

    while (!iterador.Final()) {
        if (iterador.ValorActual() <= 0)
        {
            iterador.Siguiente();
        }else
        {
            cout << "Valor actual: " << iterador.ValorActual() << std::endl;
            iterador.Siguiente();
        }
    }
}