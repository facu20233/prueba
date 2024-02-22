// pelicula.cpp
#include <iostream>
#include <string>
#include "pelicula.h"
#include "pelicula_I.h"
#include "pelicula_N.h"

// Inicialización atributo autonumerico
int pelicula::autonumerico = 1;

int main() {
    // Crear una película internacional
    PeliculaInternacional peliculaInt("Pelicula Internacional", "Director Internacional", true, 10.0);

    // Crear una película nacional
    PeliculaNacional peliculaNac("Pelicula Nacional", "Director Nacional", false, 15.0);

    // Mostrar información de las películas
    std::cout << "Información Película Internacional:" << std::endl;
    peliculaInt.listarInformacion();
    std::cout << "Costo: $" << peliculaInt.calcularCosto() << std::endl;

    std::cout << "\nInformación Película Nacional:" << std::endl;
    peliculaNac.listarInformacion();
    std::cout << "Costo: $" << peliculaNac.calcularCosto() << std::endl;

    return 0;
}