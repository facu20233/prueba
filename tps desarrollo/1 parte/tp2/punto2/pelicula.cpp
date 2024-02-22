// pelicula.cpp
#include <iostream>
#include <string>
#include "pelicula.h"

// Inicialización atributo autonumerico
int pelicula::autonumerico = 1;

int main() {

    pelicula pelicula1;  // Constructor defecto
    pelicula1.listarInformacion();
    std::cout << "Costo: " << pelicula1.calcularCosto() << std::endl;

    pelicula pelicula2(100, "Matrix", "Wachowski", true, 10.0, "I");  // Constructor parámetros
    pelicula2.listarInformacion();
    std::cout << "Costo: " << pelicula2.calcularCosto() << std::endl;

    pelicula pelicula3 = pelicula2;  // Constructor copia
    pelicula3.listarInformacion();
    std::cout << "Costo: " << pelicula3.calcularCosto() << std::endl;
    return 0;
}