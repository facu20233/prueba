#include <iostream>
#include "Fila.h"
#include "Nodo.h"
// #include "IteradorDeFila.h"

// #include "IteradorDeFila.h"
using namespace std;

// template <typename T, typename U>
// int ContarXIterador(Fila<T> &fila, U X);

int main() {
    // ---------FILA(ENTERO)
    Fila<int> filaDeEnteros;
    filaDeEnteros.Enfila(1);
    filaDeEnteros.Enfila(2);
    filaDeEnteros.Enfila(2);
    filaDeEnteros.Enfila(2);
    filaDeEnteros.Enfila(3);

    // Mostrar la fila de enteros
    std::cout << "Fila de enteros: ";
    filaDeEnteros.Mostrar();

    // Contar cuántos 2 hay en la fila de enteros
    int cantidadDeDos = filaDeEnteros.ContarX(2);
    std::cout << "Cantidad de 2s en la fila: " << cantidadDeDos << std::endl;

    // int cantidad2 = ContarXIterador<int, int>(filaDeEnteros, 2);
    // std::cout << "Cantidad de 2 en la fila: " << cantidad2 << std::endl;

    // ---------FILA(STRING)
    Fila<string> filaDeCadenas;
    filaDeCadenas.Enfila("Hola");
    filaDeCadenas.Enfila("Mundo");
    filaDeCadenas.Enfila("!");

    // Mostrar la fila de cadenas
    std::cout << "Fila de cadenas: ";
    filaDeCadenas.Mostrar();

    // Contar cuántas veces aparece "Mundo" en la fila de cadenas
    int cantidadDeMundo = filaDeCadenas.ContarX("Mundo");
    std::cout << "Cantidad de 'Mundo' en la fila: " << cantidadDeMundo << std::endl;

    return 0;
}

// template <typename T, typename U>
// int ContarXIterador(Fila<T> &fila, U X) {
//     int contador = 0;
//     IteradorDeFila<T> iterador(fila);

//     while (!iterador.Final()) {
//         T elemento = iterador.ValorActual();
//         if (elemento == X) {
//             contador++;
//         }
//         iterador.Siguiente();
//     }

//     return contador;
// }

