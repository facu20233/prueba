// peliculaInternacional.h
#include <iostream>
#include "pelicula.h"
using namespace std;

class peliculaInternacional : public pelicula
{
private:
    string pais;

public:
    peliculaInternacional(std::string nombre, string fechaEstreno, float precioBase, std::string pais):
    pelicula(nombre, fechaEstreno, precioBase), pais(pais) {}

    ~peliculaInternacional()
    {
        //
    }

    virtual float costoAlquiler() {
        return precioBase * 1.3; // Incremento del 30%
    }
};
