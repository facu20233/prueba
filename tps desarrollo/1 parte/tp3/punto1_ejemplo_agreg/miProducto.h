// miProducto.h

#ifndef MIPRODUCTO_H // en que caso usa encab
#define MIPRODUCTO_H //?
#include <iostream>
using namespace std;


class miProducto
{
private:
    int codigo;
    float precioBase;
    const float IVA = 0.21; //constante IVA = 0.21

public:

    // constructor parametro
    miProducto(){}

    // des
    ~miProducto(){
        // 
    }

    void listarInformacion(){
        cout << "Código: " << codigo << endl;
        cout << "Precio Base: " << precioBase << endl;

    }

    float calcularPrecioVenta(){ //real>=0
        float precioVenta = precioBase * (1 + IVA);
        return precioVenta; 
    }
};


#endif // MIPRODUCTO_H