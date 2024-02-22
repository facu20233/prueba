// vector.h
#include <iostream>
#include "miProducto.h"
using namespace std;




class miVector
{
private:
    int max; // entero>= 0
    miProducto** elementos; //atributo

public:

    miVector()
    {

    }


    ~miVector()
    {

    }

    bool reservaMemoria()
    {

    }

    int getCapacidad(){
        return max; 
    }

    miProducto* operator[](int i)
    {

    }

};






