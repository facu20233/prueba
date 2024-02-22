
#include <iostream>
#include "Fila.h"
#include "Nodo.h"
#include "IteradorDeFila.h"
#include "pelicula.h"
using namespace std;

template <typename T>
int ContarXIterador(Fila<T> &fila, T X);

int main() {
    // ---------FILA(ENTERO)2
    Fila<int> filaDeEnteros;
    filaDeEnteros.Enfila(1);
    filaDeEnteros.Enfila(2);
    filaDeEnteros.Enfila(2);
    filaDeEnteros.Enfila(2);
    filaDeEnteros.Enfila(3);

    // Mostrar la fila de enteros
    std::cout << "Fila de enteros: ";
    filaDeEnteros.Mostrar();

    Fila<int> filacopia = filaDeEnteros;

    // Contar cuántos 2 hay en la fila de enteros
    int cantidadDeDos = filaDeEnteros.ContarX(2);
    std::cout << "Cantidad de 2s en la fila: " << cantidadDeDos << std::endl;

    // iterador
    int cantidad2 = ContarXIterador(filacopia, 2);
    std::cout << "Cantidad de 2 en la fila: " << cantidad2 << std::endl;
    
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

    // ---------FILA(pelicula)
    pelicula pelicula1;  // Utilizará el constructor por defecto
    pelicula pelicula2(101, "El Padrino", "Francis Ford Coppola", true, 15.99, "Drama");
    pelicula pelicula3(pelicula2);  // Utilizará el constructor de copia

    Fila<pelicula> filaDePeliculas;
    filaDePeliculas.Enfila(pelicula1);
    filaDePeliculas.Enfila(pelicula2);
    filaDePeliculas.Enfila(pelicula3);

    // Mostrar la fila de películas
    std::cout << "\nFila de Películas:\n";
    IteradorDeFila<pelicula> iterador(filaDePeliculas);
    while (!iterador.Final()) {
        iterador.ValorActual().listarInformacion();
        iterador.Siguiente();
        std::cout << std::endl;
    }

    int cantidadDePeliculas = filaDePeliculas.ContarX(pelicula1);
    std::cout << "Cantidad de 'Mundo' en la fila: " << cantidadDePeliculas << std::endl;
    return 0;
    
}

template <typename T>
int ContarXIterador(Fila<T> &fila, T X) {
    int contador = 0;
    IteradorDeFila<T> iterador(fila);

    while (!iterador.Final()) {
        T elemento = iterador.ValorActual();
        if (elemento == X) {
            contador++;
        }
        iterador.Siguiente();
    }

    return contador;
}


