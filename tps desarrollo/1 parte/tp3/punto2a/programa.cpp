// programa.cpp
#include <iostream>
#include <string>
#include "persona.h"
#include "pelicula.h"

int pelicula::autonumerico=1;

int main() {
    // instanc Persona directores
    // const def
    Persona director1("nomDirec1", "Biografia del Director ...", 40);
    Persona director2("nomDirec2", "Biografia del Director ...", 50);

    // instanc Pelicula con directores
    // constr param o def?
    pelicula pelicula1(1, "nomPelic1", director1, true, 100.0, "I");
    pelicula pelicula2(2, "nomPelic2", director2, false, 50.0, "N");

    // mostrar
    std::cout << "Biografia del Director de la Pelicula 1: " << pelicula1.getBiografiaDirector() << std::endl;

    std::cout << "Biografia del Director de la Pelicula 2: " << pelicula2.getBiografiaDirector() << std::endl;

    return 0;
}