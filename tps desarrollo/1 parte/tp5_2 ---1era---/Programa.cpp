// main.cpp

#include <iostream>
#include <vector>

#include "sistema.h"
#include "cuenta.h"
#include "alquiler.h"
#include "pelicula.h"
#include "peliculaInternacional.h"
#include "peliculaNacional.h"
using namespace std;

int main() {
    // Crear un sistema de alquiler
    Sistema sistema;

    // Crear cuentas de usuario y agregarlas al sistema
    sistema.agregarCuenta("usuario1@correo.com", "1234-5678-9012-3456");
    sistema.agregarCuenta("usuario2@correo.com", "9876-5432-1098-7654");

    // Realizar alquileres para los usuarios
    // esto se creo en sistema, asig var
    Cuenta *cuenta1 = sistema.getCuentas()[0];
    Cuenta *cuenta2 = sistema.getCuentas()[1];

    alquiler alquiler1("09-11-18");
    alquiler alquiler2("05-11-18");

    peliculaInternacional pelicula1("Pelicula Internacional 1", "09-11-20", 10.0, "País A");
    peliculaInternacional pelicula2("Pelicula Internacional 2", "09-11-21", 12.0, "País B");
    peliculaNacional pelicula3("Pelicula Nacional 1", "09-12-22", 8.0);

    alquiler1.agregarPelicula(&pelicula1);
    alquiler1.agregarPelicula(&pelicula2);

    alquiler2.agregarPelicula(&pelicula3);

    cuenta1->agregarAlquiler(&alquiler1);
    cuenta2->agregarAlquiler(&alquiler2);

    // Facturar a los usuarios al final del mes (mes actual)
    sistema.facturarUsuarios(11);

    return 0;
}
