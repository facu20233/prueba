// aplicacion.h
#include <iostream>
#include "evento.h"
#include "personal.h"
#include "corporativo.h"

using namespace std;

// relacion de composicion con evento
class aplicacion
{
private:
    evento **eventos;
    int numEventos;

public:
    aplicacion()
    {
        eventos = NULL;
        numEventos = 0;
    }

     ~aplicacion()
    {
        // Liberar memoria de eventos y servicios contratados
        for (int i = 0; i < numEventos; i++)
        {
            delete eventos[i];
        }
        delete[] eventos;
    }

    evento* registrarEvento(int codigo, const string &descrip, const string &fecha, int cantPersonas, int cantServicios = 0, bool esPersonal = true, int personasExtra = 0, const string &nombre = "", bool beneficiario = false)
    {
        // Aumentar la capacidad de eventos
        evento **nuevosEventos = new evento *[numEventos + 1];

        for (int i = 0; i < numEventos; i++)
        {
            nuevosEventos[i] = eventos[i];
        }

        evento *nuevoEvento = nullptr;

        if (esPersonal)
        {
            nuevoEvento = new personal(codigo, descrip, fecha, cantPersonas, personasExtra);
        }
        else
        {
            nuevoEvento = new corporativo(codigo, descrip, fecha, cantPersonas, nombre, beneficiario);
        }

        nuevosEventos[numEventos] = nuevoEvento;

        delete[] eventos;
        eventos = nuevosEventos;
        numEventos++;

        return nuevoEvento;
    }

    void generarResumenFacturacion(int mes)
    {
        double montoTotalRecaudado = 0.0;

        cout << "Resumen de facturación para el mes " << mes << ":" << endl;

        for (int i = 0; i < numEventos; i++)
        {
            int eventoMes = obtenerMesDesdeFecha(eventos[i]->getFecha());

            if (eventoMes == mes)
            {
                eventos[i]->mostrarInformacion();
                cout << "--------------------------" << endl;
                montoTotalRecaudado += eventos[i]->calcularMontoAPagar();
            }
        }

        cout << "Monto total recaudado en el mes " << mes << ": $" << montoTotalRecaudado << endl;
    }

    int obtenerMesDesdeFecha(const string &fecha)
    {
        // Supongamos que la fecha está en el formato "YYYY-MM-DD"
        if (fecha.length() < 7)
        {
            return -1; // Valor de error, fecha inválida
        }

        // Extraer los caracteres del mes (posiciones 5 y 6)
        string mesStr = fecha.substr(5, 2);

        // Convertir el mes a un número entero
        int mes = stoi(mesStr);

        return mes;
    }

};
