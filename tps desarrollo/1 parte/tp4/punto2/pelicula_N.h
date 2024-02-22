// pelicula_N.h
#include <iostream>
#include "pelicula.h"

class PeliculaNacional : public pelicula {
private:
    // 

public:
    PeliculaNacional(std::string titulo, std::string director, bool estreno, float precioBase):
    pelicula(titulo, director, estreno, precioBase, "N") {}

    virtual float calcularCosto() {
        float costo = getPrecioBase();
        if (!getEstreno()) {
            costo *= 0.8;
        }
        return costo;
    }
};
