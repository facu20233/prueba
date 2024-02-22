#include <iostream>
#include "miVector.h"
#include "miProducto.h"

int main() {
    int capacidad;
    cout << "Ingrese la capacidad del vector: ";
    cin >> capacidad;

    // Crear un objeto de la clase miVector
    miVector miVect(capacidad);

    // Agregar productos al vector
    for (int i = 0; i < capacidad; ++i) {
        int codigo;
        string descripcion;
        float precioBase;

        cout << "Ingrese el código del producto: ";
        cin >> codigo;
        cout << "Ingrese la descripción del producto: ";
        cin.ignore();
        getline(cin, descripcion);
        cout << "Ingrese el precio base del producto: ";
        cin >> precioBase;

        miVect.agregarProducto(codigo, descripcion, precioBase);
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
