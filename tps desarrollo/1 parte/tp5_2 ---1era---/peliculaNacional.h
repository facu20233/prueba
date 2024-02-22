// peliculaNacional.h
#include <iostream>
#include "pelicula.h"
using namespace std;

class peliculaNacional : public pelicula
{
private:
    // no tiene
public:
    peliculaNacional(std::string nombre, string fechaEstreno, float precioBase):
    pelicula(nombre, fechaEstreno, precioBase) {}

    ~peliculaNacional(){
        // 
    }

    virtual float costoAlquiler() {
        // Asumimos que el parámetro anioEstreno representa el año de estreno de la película.
        // Obtén el año actual (por ejemplo, 2023).
        int anioActual = 2023;

        // Verifica si han pasado más de 10 años desde el estreno.
        if (anioActual - anioPelicula() >= 10) {
            // Aplicar un descuento del 20%
            return precioBase * 0.8;
        } else {
            return precioBase;
        }
    }
};


