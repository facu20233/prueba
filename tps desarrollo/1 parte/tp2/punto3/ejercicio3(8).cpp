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
    // fila vacia
    Fila(){
        frente = NULL;
        final = NULL;
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

    // como usuario
    int ContarX(Fila &fila, int X) {
        int contador = 0;

        while (!fila.EsFilaVacia()) {
            int elemento = fila.Frente();
            fila.Defila();

            if (elemento == X) {
                contador++;
            }
        }

        return contador;
    }

};

int main() {
    Fila fila;
    fila.Enfila(1);
    fila.Enfila(2);
    fila.Enfila(2);
    fila.Enfila(3);
    fila.Enfila(4);
    
    // mostrar
    std::cout << "Elementos fila: ";
    fila.Mostrar();

    // pertenece
    int valor = 4;
    bool pertenece = fila.Pertenece(valor);
    std::cout << "¿El valor " << valor << " pertenece a la fila? " << (pertenece ? "Sí" : "No") << std::endl;

    // contarX
    int x = 2;
    int cantidadX = fila.ContarX(fila, x);
    std::cout << "Cantidad de elementos iguales a " << x << ": " << cantidadX << std::endl;

    return 0;
}