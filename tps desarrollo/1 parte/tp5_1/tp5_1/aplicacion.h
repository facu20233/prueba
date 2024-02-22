// aplicacion.h
#include <iostream>
#include "evento.h"
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

    // aqui estoy haciendo composicion
    // aqui esta mezclando los conceptos agregacion o composicion
    ~aplicacion()
    {
        // Liberar memoria de eventos y servicios contratados
        for (int i = 0; i < numEventos; i++)
        {
            delete[] eventos[i]->getServiciosContratados();
            delete eventos[i];
        }
        delete[] eventos;
    }

    // deberia pasar todos los atributos de evento
    // void registrarEvento(evento *_evento){
    evento *registrarEvento(int codigo, const string &descrip, const string &fecha, int cantPersonas, int cantServicios = 0, bool esPersonal = true, int personasExtra = 0, const string &nombre = "", bool beneficiario = false)
    {
        // Aumentar la capacidad de eventos
        evento **nuevosEventos = new evento *[numEventos + 1];

        for (int i = 0; i < numEventos; i++)
        {
            nuevosEventos[i] = eventos[i];
        }

        evento *nuevoEvento = nullptr; // Inicializa el puntero al nuevo evento

        // Crear un nuevo objeto evento (personal o corporativo) y asignarle los atributos proporcionados
        if (esPersonal)
        {
            nuevoEvento = new personal(codigo, descrip, fecha, cantPersonas, cantServicios, personasExtra);
        }
        else
        {
            nuevoEvento = new corporativo(codigo, descrip, fecha, cantPersonas, cantServicios, nombre, beneficiario);
        }

        nuevosEventos[numEventos] = nuevoEvento;

        delete[] eventos;
        eventos = nuevosEventos;
        numEventos++;

        return nuevoEvento; // Devuelve el puntero al evento creado
    }

    void generarResumenFacturacion(int mes)
    {
        double montoTotalRecaudado = 0.0;

        cout << "Resumen de facturacion para el mes " << mes << ":" << endl;

        for (int i = 0; i < numEventos; i++)
        {
            // Extraer el mes de la fecha del evento (esto depende del formato de la fecha)
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

    // get
    evento **getEventos()
    {
        return eventos;
    }
};
