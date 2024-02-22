// VectorDinamico.h
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class VectorDinamico
{
private:
    vector<T> elementos;
    
public:
    VectorDinamico(int tam) : elementos(tam) {}

    // Constructor de copia
    VectorDinamico(const VectorDinamico<T> &otro) : elementos(otro.elementos) {}

    ~VectorDinamico()
    {
        //
    }

    // Seleccionar capacidad del vector
    void seleccionarCapacidad(int capacidad)
    {
        elementos.resize(capacidad);
    }

    // Seleccionar un elemento dado su posición
    T seleccionarElemento(int posicion) const
    {
        if (posicion >= 0 && posicion < elementos.size())
        {
            return elementos[posicion];
        }
    }

    // Insertar un elemento al principio
    void insertarAlPrincipio(const T &elemento)
    {
        elementos.insert(elementos.begin(), elemento);
    }

    // Insertar un elemento al final
    void insertarAlFinal(const T &elemento)
    {
        elementos.push_back(elemento);
    }

    // Insertar un elemento en una posición determinada
    void insertarEnPosicion(int posicion, const T &elemento)
    {
        if (posicion >= 0 && posicion <= elementos.size())
        {
            elementos.insert(elementos.begin() + posicion, elemento);
        }
    }

    // Imprimir el contenido del vector
    void imprimirVector() const
    {
        for (const auto &elem : elementos)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

    bool pertenece(const VectorDinamico<T> &vector, const T &elemento)
    {
        return std::find(vector.elementos.begin(), vector.elementos.end(), elemento) != vector.elementos.end();
    }

    T max(const VectorDinamico<T> &vector)
    {
        if (vector.elementos.empty())
        {
            throw std::out_of_range("Vector vacío");
        }
        return *std::max_element(vector.elementos.begin(), vector.elementos.end());
    }
};
