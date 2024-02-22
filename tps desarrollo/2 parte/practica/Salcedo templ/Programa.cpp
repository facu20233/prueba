#include <iostream>
#include "Arreglo.h"
#include "IteradorPar.h"
#include "pelicula.h"

template <typename T>
void EscribirPares(Arreglo<T> &arreglo);

int main()
{

    // ----- string -------

    Arreglo<string> miArregloString(7, "a");
    miArregloString.escribir();

    miArregloString[1] = "a";
    miArregloString[2] = "b";
    miArregloString[3] = "c";
    miArregloString[4] = "d";
    miArregloString[5] = "e";
    miArregloString[6] = "f";
    miArregloString[7] = "g";

    miArregloString.escribir();

    EscribirPares(miArregloString);

    // ----- string -------

    pelicula pelicula1(1, "titulo", "director", true, 1000, "nacional");

    Arreglo<pelicula> miArregloPeliculas(7, pelicula1);
    miArregloPeliculas.escribir();

    EscribirPares(miArregloPeliculas);

    return 0;
}

template <typename T>
void EscribirPares(Arreglo<T> &arreglo)
{

    IteradorPar<T> iterador(arreglo);

    while (!iterador.Final())
    {
        cout << "Valor actual: " << iterador.ValorActual() << std::endl;
        iterador.Siguiente();
    }
}