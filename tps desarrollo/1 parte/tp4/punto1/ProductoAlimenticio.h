// ProductoAlimenticio.h
#include <iostream>
#include "Producto.h"
using namespace std;

class ProductoAlimenticio : public Producto
{
    
private:
    bool toxico;
    int mesDeVencimineto;
    int anioVencimiento;
    bool aptoCeliaco;

public:
    ProductoAlimenticio(int codigo, const std::string &descripcion, float precioBase, bool esToxico, int mesVencimiento, int anioVencimiento, bool esAptoCeliaco): 
    Producto(codigo, descripcion, precioBase), 
    toxico(esToxico), 
    mesDeVencimineto(mesDeVencimineto),
    anioVencimiento(anioVencimiento), 
    aptoCeliaco(esAptoCeliaco){}

    ~ProductoAlimenticio(){
        // 
    }

    bool estaVencido(int mesActual, int anioActual) const
    {
        return (anioActual > anioVencimiento) || (anioActual == anioVencimiento && mesActual > mesDeVencimineto);
    }

    bool esAptoCeliacos() 
    {
        return aptoCeliaco;
    }

    float calcularPrecio(){
        float monto = this->getPrecioBase();
        if (this->esAptoCeliacos())
        {
            monto = monto*1.1;
        }
        monto = monto + (this->calcularIVA(monto))/2;
        return monto;
    }

};


