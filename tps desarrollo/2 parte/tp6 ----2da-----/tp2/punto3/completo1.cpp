#include <iostream>

class Nodo {
public:
    int valor;
    Nodo* siguiente;

    Nodo(int val) : valor(val), siguiente(nullptr) {}
};

class FilaVacia {
private:
    Nodo* frente;
    Nodo* final;

public:
    FilaVacia() : frente(nullptr), final(nullptr) {}

    ~FilaVacia() {
        while (!FilaVacia()) {
            Defila();
        }
    }

    bool FilaVacia() {
        return frente == nullptr;
    }

    void Enfila(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (FilaVacia()) {
            frente = final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
    }

    int Frente() {
        if (!FilaVacia()) {
            return frente->valor;
        } else {
            std::cerr << "La fila está vacía." << std::endl;
            return -1; //indica error o fila vacía
        }
    }

    void Defila() {
        if (!FilaVacia()) {
            Nodo* temp = frente;
            frente = frente->siguiente;
            delete temp;
        } else {
            std::cerr << "La fila vacia" << std::endl;
        }
    }

    void Mostrar() {
        Nodo* actual = frente;
        while (actual != nullptr) {
            std::cout << actual->valor << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    int ContarX(int x) {
        Nodo* actual = frente;
        int contador = 0;
        while (actual != nullptr) {
            if (actual->valor == x) {
                contador++;
            }
            actual = actual->siguiente;
        }
        return contador;
    }
};

int main() {
    FilaVacia miFila;
    
    miFila.Enfila(1);
    miFila.Enfila(2);
    miFila.Enfila(3);
    miFila.Enfila(2);
    miFila.Enfila(4);
    miFila.Enfila(2);

    std::cout << "Elementos en la fila: ";
    miFila.Mostrar();

    int x = 2;
    int cantidadX = miFila.ContarX(x);
    std::cout << "Cantidad de elementos iguales a " << x << ": " << cantidadX << std::endl;

    return 0;
}