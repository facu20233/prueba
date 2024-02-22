// pelicula_I.h
#include <iostream>
#include "pelicula.h"

class PeliculaInternacional : public pelicula {

private:
    // 

public:
    PeliculaInternacional(std::string titulo, std::string director, bool estreno, float precioBase):
    pelicula(titulo, director, estreno, precioBase, "I") {}

    virtual float calcularCosto() {
        return getPrecioBase() * 1.3;
    }
};
