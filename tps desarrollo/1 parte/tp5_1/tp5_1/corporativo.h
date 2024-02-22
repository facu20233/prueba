// corporativo.h
#include <iostream>
#include "evento.h"
using namespace std;

class corporativo : public evento
{
private:
    string nombre;
    bool beneficiario;
    
public:
    corporativo(int codigo, const string& descrip, const string& fecha, int cantPersonas, int cantServicios, string nombre, bool beneficiario): 
    evento(codigo, descrip, fecha, cantPersonas, cantServicios), 
    nombre(nombre), 
    beneficiario(beneficiario) {}

    ~corporativo(){
        // 
    }
};


