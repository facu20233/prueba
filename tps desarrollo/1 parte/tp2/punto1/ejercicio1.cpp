//Ejercicio1

#include <iostream>
#include "cuentaObjeto.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	
    cuentaObjeto obj1;
    cuentaObjeto::mostrarResumen(); //1era
    {
        cuentaObjeto obj2(obj1);
        cuentaObjeto::mostrarResumen(); //2da invc
        cuentaObjeto *obj3 = new CuentaObjeto();
        *obj3 = obj2.metodo(*obj3);
        cuentaObjeto::mostrarResumen(); //3ra
    }
    cuentaObjeto::mostrarResumen();

    return 0;
}

