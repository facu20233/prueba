// alquiler.h

#ifndef ALQUILER_H
#define ALQUILER_H

#include <iostream>
#include <vector>
#include "pelicula.h"
using namespace std;

class alquiler
{
private:
    // peliculasAlquiladas
    vector<pelicula *> peliculas; //max 5, falto esto
    string fechaProduccion; // 09-10-18

public:
    alquiler(std::string fechaProduccion) : 
    fechaProduccion(fechaProduccion) {}

    ~alquiler(){
        // 
    }

    int ObtenerMesAlquiler()
    {
        // cadena mes
        string cadena_mes = fechaProduccion.substr(3, 2);
        // Convierte el mes a un entero.
        int mes = stoi(cadena_mes);
        return mes;
    }

    void agregarPelicula(pelicula *pelicula)
    {
        if (peliculas.size() < 5) {
            peliculas.push_back(pelicula);
        }
    }

    vector<pelicula*> getPeliculas()
    {
        return peliculas;
    }
    
};

#endif //ALQUILER_H