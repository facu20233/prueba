#include <iostream>
#include "Fila.h"
#include "Nodo.h"
#include "IteradorDeFila.h"
#include "pelicula.h"

int ContarXIterador(Fila &fila, int X);

int main()
{

    Fila MiFila;
    MiFila.Enfila(1);
    MiFila.Enfila(2);
    MiFila.Enfila(2);
    MiFila.Enfila(3);
    MiFila.Enfila(4);
    MiFila.Enfila(3);

    // mostrar
    std::cout << "Elementos fila: ";
    MiFila.Mostrar();

    // pertenece
    int valor = 4;
    bool pertenece = MiFila.Pertenece(valor);
    cout << "¿El valor " << valor << " pertenece a la fila? " << (pertenece ? "Sí" : "No") << std::endl;

    Fila FilaCopia = MiFila;


    // contarX
    int x = 3;
    int cantidadX = MiFila.ContarX(FilaCopia, x);
    std::cout << "Cantidad de elementos iguales a " << x << ": " << cantidadX << std::endl;

    // -------------tp6-----------------

    Fila FilaCopia2 = MiFila;

    cout << "------ tp6 -------" << endl;
    
    IteradorDeFila iterador(MiFila);

    while (!iterador.Final()) {
        std::cout << iterador.ValorActual() << " ";
        iterador.Siguiente();
    }
    std::cout << std::endl;

    // contarXIterador
    int cantidadX2 = ContarXIterador(FilaCopia2, x);
    std::cout << "Cantidad de " << x << " en la fila: " << cantidadX2 << std::endl;

    return 0;

}

int ContarXIterador(Fila &fila, int X) {
    int contador = 0;
    IteradorDeFila iterador(fila);

    while (!iterador.Final()) {
        int elemento = iterador.ValorActual();
        if (elemento == X) {
            contador++;
        }
        iterador.Siguiente();
    }

    return contador;
}
