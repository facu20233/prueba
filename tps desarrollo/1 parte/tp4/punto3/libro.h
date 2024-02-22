// libro.h
#include <iostream>
#include "publicacion.h"
using namespace std;

class libro : public publicacion
{
private:
    int ISBN; //? 
    string autorPrincipal;
    bool bestSeller;
    
public:
    libro(const string& _titulo, int _anioEdicion, float _precioBase, int _ISBN, const string& _autorPrincipal, bool _bestSeller): 
    publicacion(_titulo, _anioEdicion, _precioBase), 
    ISBN(_ISBN), 
    autorPrincipal(_autorPrincipal), bestSeller(_bestSeller) {}

    ~libro(){
        // 
    }

    // void listarInformacion(){
    //     // 
    // }

    bool esBestSeller(){
        return bestSeller;
    }

    float calcularPrecio(){
        float costo = getPrecioBase();
        if (bestSeller)
        {
            costo = costo*1.1;
            
        }
        costo = costo*1.21;
        return costo;
    }
    
};


