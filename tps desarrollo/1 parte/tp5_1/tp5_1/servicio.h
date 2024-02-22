// servicio.h
#include <iostream>
using namespace std;

class servicio
{
private:
    int codigo;
    string descrip;
    float montoBase;

public:
    servicio(int codigo, string descripcion, double montoBase):
    codigo(codigo),
     descrip(descripcion), 
     montoBase(montoBase) {}

    ~servicio(){
    // 
    }

    // get - set
    float getMontoBase(){
        return montoBase;
    }

    string getDescrip(){
        return descrip;
    }
};
