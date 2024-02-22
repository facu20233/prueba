// cuenta.h
#ifndef CUENTA_H
#define CUENTA_H

#include <iostream>
#include "alquiler.h"
using namespace std;

class Cuenta
{
private:
    string correo;
    string tarjeta;
    // monto fijo ?
    vector<alquiler *> alquileres;

public:
    Cuenta(const std::string &correo, const std::string &tarjeta)
        : correo(correo), tarjeta(tarjeta) {}

    ~Cuenta()
    {
        for (alquiler *alquiler : alquileres)
        {
            delete alquiler;
        }
    }

    float montoPagarPorMes(int mesActual)
    {
        float MontoFijo = 50.0; // Monto fijo del servicio de streaming
        float montoTotal = 0.0;

        for (alquiler *_alquiler : alquileres)
        {
            int mesAlquiler = _alquiler->ObtenerMesAlquiler();

            if (mesAlquiler == mesActual)
            {
                for (pelicula *pelicula : _alquiler->getPeliculas())
                {
                    montoTotal += pelicula->costoAlquiler();
                }
            }
        }

        montoTotal += MontoFijo;

        return montoTotal;
    }

    void agregarAlquiler(alquiler *nuevoAlquiler)
    {
        alquileres.push_back(nuevoAlquiler);
    }
};

#endif // CUENTA_H