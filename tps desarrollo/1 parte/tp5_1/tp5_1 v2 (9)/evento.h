// evento.h
#include <iostream>
#ifndef EVENTO_H
#define EVENTO_H
#include "servicio.h"
using namespace std;

//relacion de agregacion con servicio
class evento
{
private:
    int codigo;
    string descrip;
    string fecha;
    int cantPersonas;
    int cantServicios;
    // 
    servicio** serviciosContratados; //lista servicios

public:
    evento(int codigo, const string& descrip, const string& fecha, int cantPersonas, int cantServicios = 0)
        : codigo(codigo), 
        descrip(descrip), 
        fecha(fecha), 
        cantPersonas(cantPersonas) {
            serviciosContratados = NULL;
            this->cantServicios = cantServicios; // =0
        }


    ~evento()
    {
        for (int i = 0; i < cantServicios; i++)
        {
            delete serviciosContratados[i];
        }
        delete[] serviciosContratados;
    }

    virtual double calcularMontoAPagar() {
        double montoTotal = 0.0;
        for (int i = 0; i < cantServicios; i++) {
            montoTotal += serviciosContratados[i]->getMontoBase();
        }
        return montoTotal * 1.1; // Aplica el incremento del 10% empresa
    }

    virtual void mostrarInformacion() {
        cout << "Codigo del evento: " << codigo << endl;
        cout << "Descripcion: " << descrip << endl;
        cout << "Fecha: " << fecha << endl;
        cout << "Asistentes: " << cantPersonas << endl;
        cout << "Servicios contratados:" << endl;
        for (int i = 0; i < cantServicios; i++) {
            cout << "  - " << serviciosContratados[i]->getDescrip() << " ($" << serviciosContratados[i]->getMontoBase() << " por persona)" << endl;
        }
        cout << "Monto a pagar: $" << calcularMontoAPagar() << endl;
    }

    // agregacion porque le estoy pasando un servicio
    void agregarServicio(servicio* _servicio) {
        // Aumenta la capacidad de servicios contratados
        servicio** nuevosServicios = new servicio*[cantServicios + 1]; //memoria
        for (int i = 0; i < cantServicios; i++) {
            nuevosServicios[i] = serviciosContratados[i];
        }
        nuevosServicios[cantServicios] = _servicio;
        delete[] serviciosContratados;
        serviciosContratados = nuevosServicios;
        cantServicios++;
    }

    // vector tp5_2
    // void agregarPelicula(pelicula *pelicula)
    // {
    //     if (peliculas.size() < 5) {
    //         peliculas.push_back(pelicula);
    //     }
    // }

    // get - set
    servicio** getServiciosContratados() {
        return serviciosContratados;
    }

    string getFecha(){
        return fecha;
    }
    
};

#endif //EVENTO_H
