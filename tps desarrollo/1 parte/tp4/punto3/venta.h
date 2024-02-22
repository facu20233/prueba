// venta.h
#ifndef VENTA_H
#define VENTA_H
#include <iostream>
#include "publicacion.h"
using namespace std;

// relacion de agregacion entre venta y publicacion
class venta
{
private:
    int codigoVenta;
    string fechaVenta;
    publicacion** articulosVenidos;
    // add
    int numArticulos;    
public:
    venta(int _codigoVenta, const string& _fechaVenta): codigoVenta(_codigoVenta), 
    fechaVenta(_fechaVenta){}
    
    ~venta() {
        for (int i = 0; i < numArticulos; i++) {
            delete articulosVenidos[i];
        }
        delete[] articulosVenidos;
    }

    void agregarArticulo(publicacion* articulo) {
        // 
        publicacion** temp = new publicacion*[numArticulos + 1];
        for (int i = 0; i < numArticulos; i++) {
            temp[i] = articulosVenidos[i];
        }
        temp[numArticulos] = articulo;
        delete[] articulosVenidos;
        articulosVenidos = temp;
        numArticulos++;
    }
    

    void listarInformacion() const {
        cout << "Código de Venta: " << codigoVenta << endl;
        cout << "Fecha de Venta: " << fechaVenta << endl;
        cout << "Artículos vendidos:" << endl;
        for (int i = 0; i < numArticulos; i++) {
            articulosVenidos[i]->listarInformacion();
            cout << "Precio de venta: " << articulosVenidos[i]->calcularPrecio() << endl;
        }
    }

    float calcularMontoVenta() const {
        float montoTotal = 0.0;
        for (int i = 0; i < numArticulos; i++) {
            montoTotal += articulosVenidos[i]->calcularPrecio();
        }
        return montoTotal;
    }

    // add
    string getFechaVenta(){
        return fechaVenta;
    }
};

#endif //VENTA_H
