// producto.h
#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
using namespace std;

// clase base
class Producto
{

private:
    int codigo;
    string descripcion;
    float precioBase;
    float const IVA = 0.21;

public:
    Producto(int codigo, const std::string &descripcion, float precioBase): 
    codigo(codigo), 
    descripcion(descripcion), 
    precioBase(precioBase){}

    ~Producto(){
        // 
    }

    // listar por pantalla la informacion de un producto
    void listarInformacion()
    {
        std::cout << "Código: " << codigo << std::endl;
        std::cout << "Descripción: " << descripcion << std::endl;
        std::cout << "Precio base: $" << precioBase << std::endl;
    }

    virtual float calcularPrecio()
    {
        return precioBase + calcularIVA(precioBase);
    }

protected:
    float getPrecioBase(){
        return precioBase;
    }

    float calcularIVA(float monto){ //real >= 0
        return monto*this->IVA;
    }

};

#endif //PRODUCTO_H