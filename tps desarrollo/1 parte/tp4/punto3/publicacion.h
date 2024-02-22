// publicacion.h
#include <iostream>
#ifndef PUBLICACION_H
#define PUBLICACION_H
using namespace std;

class publicacion
{
    
private:
    string titulo;
    int anioEdicion;
    float PrecioBase; 

public:
    publicacion(const string& _titulo, int _anioEdicion, float _precioBase): 
    titulo(_titulo), 
    anioEdicion(_anioEdicion), 
    PrecioBase(_precioBase) {}

    virtual ~publicacion();

    virtual void listarInformacion() const {
        cout << "Título: " << titulo << endl;
        cout << "Año de Edición: " << anioEdicion << endl;
        cout << "Precio Base: " << PrecioBase << endl;
    }
    virtual float calcularPrecio(){
        return PrecioBase; //corregir
    }

    // get
    float getPrecioBase(){
        return PrecioBase;
    }

    int getAnioEdicion(){
        return anioEdicion;
    }
    

};

#endif //PUBLICACION_H
