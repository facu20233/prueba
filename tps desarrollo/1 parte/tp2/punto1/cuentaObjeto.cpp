//Ejercicio1

#include <iostream>
#include "cuentaObjeto.h"
using namespace std;

// Inicializar contadores estáticos
int CuentaObjeto::objCreados = 0;
int CuentaObjeto::objDestruidos = 0;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	
    CuentaObjeto obj1;
    CuentaObjeto::mostrarResumen(); //1era
    {
        CuentaObjeto obj2(obj1);
        CuentaObjeto::mostrarResumen(); //2da invc
        CuentaObjeto *obj3 = new CuentaObjeto();
        // *obj3 = obj2.metodo(*obj3);
        *obj3 = obj2.metodo();
        CuentaObjeto::mostrarResumen(); //3ra
    }
    CuentaObjeto::mostrarResumen();

    return 0;
}

