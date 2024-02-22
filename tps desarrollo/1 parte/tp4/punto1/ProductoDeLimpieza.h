// ProductoDeLimpieza.h
#include <iostream>
#include "Producto.h"
using namespace std;

class  ProductoDeLimpieza : public Producto
{

private:
    bool toxico;

public:
    ProductoDeLimpieza(int codigo, const std::string &descripcion, float precioBase, bool esToxico): 
    Producto(codigo, descripcion, precioBase), 
    toxico(esToxico){}

    ~ProductoDeLimpieza(){
        // 
    }

    bool esToxico(){
        return toxico;  
    }

    // virtual 
    float calcularPrecio(){ //real >= 0
        float monto = this->getPrecioBase();
        monto = monto + this->calcularIVA(monto);
        return monto;
    }

};

