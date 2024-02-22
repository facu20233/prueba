#include <iostream>
#include "Arreglo.h"
#include "IteradorPar.h"
using namespace std;

int main(){
    cout << "hola ";
    Arreglo miArreglo(6,1);
    miArreglo.escribir();

    cout <<"Iterador par"<< endl;
    // IteradorPar iteratorPar(miArreglo, miArreglo.Primer());
    IteradorPar iteratorPar(miArreglo, 1);

    while (!iteratorPar.Final()) {
        cout << iteratorPar.ValorActual() << " " << endl;
        iteratorPar.Siguiente();
    }

    return 0;
}