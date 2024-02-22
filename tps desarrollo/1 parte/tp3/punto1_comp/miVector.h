// vector.h
#include <iostream>
#include "miProducto.h"
using namespace std;

/*
usando vector productos, no reserva memoria
puntero doble 
puntero simple y vector

comp o agregacion c++?
agregacion: le mando los productos
composicion: creo el producto en vector
*/ 


class miVector
{
private:
    int max; // entero>= 0

    // coleccion, arreglo referencia (no por valor)
    // coleccion de punteros
    miProducto** elementos; //atributo

public:
    // def
    // vector(){
    //     max = 0;
    // }

    // cuando param, cuando def?
    // const param

    // const param
    miVector(int capacidad): max(capacidad), elementos(new miProducto*[capacidad])
    {
        for (int i = 0; i < max; ++i)
        {
            elementos[i] = NULL;
        }
    }

    // destructor
    ~miVector()
    {
        for (int i = 0; i < max; ++i)
        {
            delete elementos[i]; // Liberar memoria productos
        }
        delete[] elementos; // Liberar arreglo punteros
    }

    // privado
    // reservar memoria para esos puntero
    // stack, heap
    // bool reservaMemoria(int dim/capacidad)
    // 

    bool reservaMemoria()
    {
        // verdadero si no es  null
        // falso si es null
        if (max <= getCapacidad())
        {
            int codigo;
            string descripcion;
            float precioBase;

            cout << "Ingrese el código del producto: ";
            cin >> codigo;
            cout << "Ingrese la descripción del producto: ";
            cin.ignore(); // Limpiar el buffer de entrada
            getline(cin, descripcion);
            cout << "Ingrese el precio base del producto: ";
            cin >> precioBase;

            // Crear objeto Producto y almacenarlo en el vector
            // elementos[max] = new miProducto(codigo, descripcion, precioBase);
            // max++;
            // cout << "-----------------" << endl;

            // Crear objeto Producto
            miProducto* nuevoProducto = new miProducto(codigo, descripcion, precioBase);

            // Agregar producto vector
            elementos[max] = nuevoProducto;
            max++;
            cout << "-----------------" << endl;

            return true;
        }
        else
        {
            cout << "El vector esta lleno, no se puede agregar" << endl;
            return false;
        }
    }

    int getCapacidad(){
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
            return NULL; // Devolver null, índice fuera de rango
        }
    }

};






