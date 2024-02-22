// ingrediente.h
#include <iostream>
using namespace std;

class ingrediente
{
private:
    string descripcion;
    float precio;
public:
    ingrediente(string descripcion, float precio);
    ~ingrediente();
};


