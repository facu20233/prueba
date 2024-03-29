#include <iostream>

// ADT FILA(entero)
class Nodo {
public: //probar private
    int valor;
    Nodo* siguiente; //para

    // Nodo(int val) : valor(val), siguiente(nullptr) {}
    Nodo(int val){
        valor = val;
        siguiente = NULL;
    }
};

class FilaVacia {
private:
    Nodo* frente;
    Nodo* final;

public:
    // Constructor defecto crea fila vacía, (clase atributos)
    // FilaVacia() : frente(nullptr), final(nullptr) {}
    FilaVacia(){
        frente = NULL;
        final = NULL;
    }

    // Destructor libera la memoria.
    ~FilaVacia() {
        while (!esFilaVacia()) {
            Desfila();
        }
    }

 
    bool esFilaVacia() {
        return frente == NULL;
    }

    // -> 1 2 3
    void Desfila() {
        if (!esFilaVacia()) {
            Nodo* temp = frente;
            frente = frente->siguiente;
            delete temp;
        }
    }

    void Enfila(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (esFilaVacia()) {
            frente = final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
    }

    // int Frente() {
    //     if (!esFilaVacia()) {
    //         return frente->valor;
    //     }
    //     //caso de error.
    //     throw std::runtime_error("fila vacia.");
    // }

    void Mostrar() {
        Nodo* actual = frente;
        while (actual != NULL) {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    // int Longitud() {
    //     Nodo* actual = frente;
    //     int length = 0;
    //     while (actual != nullptr) {
    //         length++;
    //         actual = actual->siguiente;
    //     }
    //     return length;
    // }

    // corregir
    // int ContarX(int X) {
    //     Nodo* actual = frente;
    //     int count = 0;
    //     while (actual != nullptr) {
    //         if (actual->valor == X) {
    //             count++;
    //         }
    //         actual = actual->siguiente;
    //     }
    //     return count;
    // }

    // bool Pertenece(int valor) {
    //     Nodo* actual = frente;
    //     while (actual != nullptr) {
    //         if (actual->valor == valor) {
    //             return true;
    //         }
    //         actual = actual->siguiente;
    //     }
    //     return false;
    // }
};

int main() {
    FilaVacia fila;
    fila.Enfila(1);
    fila.Enfila(2);
    fila.Enfila(3);
    fila.Enfila(4);

    std::cout << "Elementos fila: ";
    fila.Mostrar();

    // int valor = 2;
    // // int cantidad = fila.ContarX(valor);
    // // std::cout << "Cantidad elementos iguales a " << valor << ": " << cantidad << std::endl;

    // valor = 4;
    // bool pertenece = fila.Pertenece(valor);
    // std::cout << "¿El valor " << valor << " pertenece a la fila? " << (pertenece ? "Sí" : "No") << std::endl;

    // return 0;
}