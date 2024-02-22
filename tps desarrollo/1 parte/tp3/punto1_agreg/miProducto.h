// miProducto.h
#ifndef MIPRODUCTO_H // en que caso usa encab
#define MIPRODUCTO_H //?
#include <iostream>
using namespace std;


class miProducto
{
private:
    int codigo;
    std::string descripcion;
    float precioBase;
    const float IVA = 0.21; //constante IVA = 0.21

public:

    miProducto(int codigo, const string& descripcion, float precioBase): codigo(codigo), descripcion(descripcion), precioBase(precioBase){}

    ~miProducto(){
        // 
    }

    void listarInformacion(){
        cout << "Código: " << codigo << endl;
        cout << "Descripción: " << descripcion << endl;
        cout << "Precio Base: " << precioBase << endl;

    }

    float calcularPrecioVenta(){ //real>=0
        float precioVenta = precioBase * (1 + IVA);
        return precioVenta; 
    }
};


#endif // MIPRODUCTO_H