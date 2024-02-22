// programa.cpp
#include <iostream>
#include "miVector.h"
#include "miProducto.h"

int main() {
    int capacidad;
    cout << "Ingrese la capacidad del vector: ";
    cin >> capacidad;

    // Crear un objeto de la clase miVectorcuand
    miVector miVect(capacidad);

    // Reservar memoria para productos
    for (int i = 0; i < capacidad; ++i) {
        miVect.reservaMemoria();
    }

    // Mostrar la información de los productos
    for (int i = 0; i < capacidad; ++i) {
        miProducto* producto = miVect[i];
        if (producto != NULL) {
            cout << "-----Producto " << i + 1 << ":" << endl;
            producto->listarInformacion();
            cout << "Precio de venta: " << producto->calcularPrecioVenta() << endl;
            cout << "--------------------------" << endl;
        }
    }

    return 0;
}


