// vector.h
#include <iostream>
#include "miProducto.h"
using namespace std;

class miVector
{
private:
    int max; // Entero >= 0
    miProducto** elementos; // Arreglo de punteros a miProducto

public:
    miVector(int capacidad) : max(capacidad), elementos(new miProducto*[capacidad])
    {
        for (int i = 0; i < max; ++i)
        {
            elementos[i] = NULL;
        }
    }

    ~miVector()
    {
        for (int i = 0; i < max; ++i)
        {
            delete elementos[i]; // Liberar memoria productos
        }
        delete[] elementos; // Liberar arreglo punteros
    }

    bool agregarProducto(int codigo, const string& descripcion, float precioBase)
    {
        for (int i = 0; i < max; ++i)
        {
            if (elementos[i] == NULL)
            {
                // Crear objeto Producto
                elementos[i] = new miProducto(codigo, descripcion, precioBase);
                return true;
            }
        }
        cout << "El vector está lleno, no se puede agregar más productos." << endl;
        return false;
    }

    int getCapacidad()
    {
        return max;
    }

    miProducto* operator[](int i)
    {
        if (i >= 0 && i < max)
        {
            return elementos[i];
        }
        else
        {
            return NULL; // Devolver null si el índice está fuera de rango
        }
    }
};
