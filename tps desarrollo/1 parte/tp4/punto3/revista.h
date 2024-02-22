// revista.h
#include <iostream>
#include "publicacion.h"
using namespace std;

class revista : public publicacion
{
private:
    int ISSN; //?
    int numero;
    int volumen;
    string campoTematico;

public:
    revista(const string& _titulo, int _anioEdicion, float _precioBase, int _ISSN, int _numero, int _volumen, const string& _campoTematico): 
    publicacion(_titulo, _anioEdicion, _precioBase), 
    ISSN(_ISSN), 
    numero(_numero), 
    volumen(_volumen), 
    campoTematico(_campoTematico) {}

    ~revista(){
        // 
    }

    float calcularPrecio(){
        float costo = getPrecioBase();
        if (getAnioEdicion()>5)
        {
            return costo;
        }else
        {
            costo = costo*0.85;
        }
        costo = costo*1.21;
        return costo;
    }
};


