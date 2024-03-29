#include <iostream>
// ADT FILA(entero)
class Nodo {
private: //probar private
    int valor;
    Nodo* siguiente; 

    friend class FilaVacia; //clase fila accede a los atributos priv de la clase nodo 

public:
    // constructor parametro
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
    FilaVacia(){
        frente = NULL;
        final = NULL;
    }

    // Destructor - libera la memoria.
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

    void Mostrar() {
        Nodo* actual = frente;
        while (actual != NULL) {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

};

int main() {
    FilaVacia fila;
    fila.Enfila(1);
    fila.Enfila(2);
    fila.Enfila(3);
    fila.Enfila(4);

    std::cout << "Elementos fila: ";
    fila.Mostrar();

}