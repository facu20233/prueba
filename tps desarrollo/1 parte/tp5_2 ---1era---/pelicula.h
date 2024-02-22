// pelicula.h

#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
using namespace std;

class pelicula
{
protected:
    string nombre;
    string fechaEstreno; //09-12-23
    float precioBase;

public:
    pelicula(std::string nombre, string fechaEstreno, float precioBase):nombre(nombre),fechaEstreno(fechaEstreno),precioBase(precioBase) {}

    ~pelicula()
    {
        //
    }

    virtual float costoAlquiler()
    {
        return precioBase;
    } 

    int anioPelicula(){
        string cadena = fechaEstreno.substr(7,3);
        int anio = stoi(cadena);
        return anio;
    }

};

#endif //PELICULA_H