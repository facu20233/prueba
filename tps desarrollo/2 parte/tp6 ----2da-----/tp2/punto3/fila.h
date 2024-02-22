// fila.h
#include <iostream>


// ADT FILA(entero)
// private
class Nodo {
private: //probar private
    int valor;
    Nodo* siguiente; 

    friend class Fila; //clase fila accede a los atributos priv de la clase nodo 

public:
    // constructor parametro
    Nodo(int val){
        valor = val;
        siguiente = NULL;
    }
};

class Fila {
private:
    Nodo* frente;
    Nodo* final;

public:
    // Constructor defecto crea fila vacía, (clase atributos)
    Fila(){
        frente = NULL;
        final = NULL;
    }

    // Constructor de copia
    Fila(const Fila& otraFila) {
        frente = nullptr;
        final = nullptr;

        Nodo* actual = otraFila.frente;
        while (actual != nullptr) {
            Enfila(actual->valor);
            actual = actual->siguiente;
        }
    }

    // Destructor - libera la memoria.
    ~Fila() {
        while (!EsFilaVacia()) {
            Defila();
        }
    }

    bool EsFilaVacia() {
        return frente == NULL;
    }

    // -> 1 2 3
    void Defila() {
        if (!EsFilaVacia()) {
            Nodo* temp = frente;
            frente = frente->siguiente;
            delete temp;
        }
    }

    void Enfila(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (EsFilaVacia()) {
            frente = final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
    }

    int Frente() {
        if (!EsFilaVacia()) {
            return frente->valor;
        }
        //caso de error.
        throw std::runtime_error("fila vacia.");
    }

    int Longitud() {
        Nodo* actual = frente;
        int length = 0;
        while (actual != nullptr) {
            length++;
            actual = actual->siguiente;
        }
        return length;
    }

    bool Pertenece(int valor) {
        Nodo* actual = frente;
        while (actual != nullptr) {
            if (actual->valor == valor) {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    void Mostrar() {
        Nodo* actual = frente;
        while (actual != NULL) {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    
};