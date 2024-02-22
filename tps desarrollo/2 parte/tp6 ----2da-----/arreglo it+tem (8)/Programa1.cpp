#include <iostream>
#include "Arreglo.h"
#include "IteradorPar.h"
#include "pelicula.h"

template <typename T>
int ContarXiterador(const Arreglo<T> &arreglo, const T &X);

int main()
{
    //          ----- arreglo string ---------
    
    Arreglo<string> arregloStrings(10, "a");
    arregloStrings.escribir();

    arregloStrings[1] = "h";
    arregloStrings[2] = "o";
    arregloStrings[3] = "l";
    arregloStrings[4] = "a";

    arregloStrings.escribir();

    IteradorPar<string> iteradorPar(arregloStrings, 1);

    while (!iteradorPar.Final())
    {
        cout << "Elemento actual: " << iteradorPar.ValorActual() << endl;
        iteradorPar.Siguiente();
    }

    //          ----- arreglo pelicula ---------

    pelicula pelicula1(101, "11111", "0000", true, 15.99, "Drama");
    pelicula pelicula2(102, "El Padrino", "Francis Ford Coppola", true, 15.99, "Drama");
    pelicula pelicula3(103, "El Padrino2", "Francis Ford Coppola2", true, 15.99, "accion");

    Arreglo<pelicula> arregloPeliculas(3, pelicula1);
    arregloPeliculas.escribir();

    arregloPeliculas[1] = pelicula2;
    arregloPeliculas[2] = pelicula3;
    arregloPeliculas[3] = pelicula2;

    // arregloPeliculas.escribir(); //este estaba dando errror

    IteradorPar<pelicula> iteradorPelicula(arregloPeliculas, 1);

    while (!iteradorPelicula.Final())
    {
        iteradorPelicula.ValorActual().listarInformacion();
        iteradorPelicula.Siguiente();
    }   

    // ***
    int cantidad = ContarXiterador(arregloPeliculas, pelicula2);

    // Imprimir el resultado
    std::cout << "ContarXiterador " << pelicula2 << ": " << cantidad << std::endl;

    // ***
    int cantidad2 = arregloPeliculas.ContarX(pelicula2);

    return 0;
}

template <typename T>
int ContarXiterador(const Arreglo<T> &arreglo, const T &X)
{
    IteradorPar<T> iterador(arreglo, 1);  // Crea un objeto IteradorPar
    int contador = 0;

    while (!iterador.Final())
    {
        T elemento = iterador.ValorActual();
        
        if (elemento == X)
        {
            contador++;
        }

        iterador.Siguiente();
    }
     
    

    return contador;
}
