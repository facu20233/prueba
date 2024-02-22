// personal.h
#include <iostream>
#include "evento.h"
using namespace std;

class personal : public evento
{
private:
    int personas_extra;

public:
    personal(int codigo, string descripcion, string fecha, int cantPersonas, int personas_extra): 
    evento(codigo, descripcion, fecha, cantPersonas), 
    personas_extra(personas_extra) {}

    ~personal(){
        // 
    }

    double calcularMontoAPagar() override {
        double montoTotal = evento::calcularMontoAPagar(); // Llama al método de la clase base
        return montoTotal + (personas_extra * getServiciosContratados()[0]->getMontoBase() * 0.6); // 60% de descuento para personas adicionales
    }

    void mostrarInformacion() override {
        evento::mostrarInformacion(); // Llama al método de la clase base
        cout << "Personas adicionales: " << personas_extra << endl;
    }
};


