// sistema.h
#include <iostream>
#include "venta.h"
using namespace std;

// relacion de composicion entre venta y sistema
class sistema
{
private:
    // add
    venta** ventasRealizadas;
    int numVentas;

public:
    sistema(): 
    ventasRealizadas(NULL), 
    numVentas(0) {}

    ~sistema() {
        for (int i = 0; i < numVentas; i++) {
            delete ventasRealizadas[i];
        }
        delete[] ventasRealizadas;
    }   

    // add
    void registrarVenta(venta* nuevaVenta) {
        // 
        venta** temp = new venta*[numVentas + 1];
        for (int i = 0; i < numVentas; i++) {
            temp[i] = ventasRealizadas[i];
        }
        temp[numVentas] = nuevaVenta;
        delete[] ventasRealizadas;
        ventasRealizadas = temp;
        numVentas++;
    }

    // add
    void listarVentasEnFecha(const string& fecha) const {
        cout << "Ventas realizadas en la fecha " << fecha << ":" << endl;
        for (int i = 0; i < numVentas; i++) {
            if (ventasRealizadas[i]->getFechaVenta() == fecha) {
                ventasRealizadas[i]->listarInformacion();
                cout << "Monto de la venta: " << ventasRealizadas[i]->calcularMontoVenta() << endl;
            }
        }
    }

    float calcularMontoTotalEnMes(int mes){
        float montoTotal = 0.0;
        for (int i = 0; i < numVentas; i++) {
            int ventaMes = stoi(ventasRealizadas[i]->getFechaVenta().substr(5, 2));
            if (ventaMes == mes) {
                montoTotal += ventasRealizadas[i]->calcularMontoVenta();
            }
        }
        return montoTotal;
    }

};


