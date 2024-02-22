  #include <iostream>

class cuentaObjeto {
private:
    // atributos
    static int objCreados;  //estatico    
    static int objDestruidos; //estatico  
public:
    //metodo 
    // clase
    cuentaObjeto() {
        objCreados++;
    }

    cuentaObjeto(const cuentaObjeto&) {
        objCreados++;
    }

    cuentaObjeto& metodo() {
        return *this;
    }

    static void mostrarResumen() {
        std::cout << "Objetos creados: " << objCreados << std::endl;
        std::cout << "Objetos destruidos: " << objDestruidos << std::endl;
    }

    // destr
    ~cuentaObjeto() {
        objDestruidos++;
    }
};

// Inicializar contadores estáticos
int cuentaObjeto::objCreados = 0;
int cuentaObjeto::objDestruidos = 0;

int main() {
    std::cout << "!!!Hello World!!!" << std::endl;

    cuentaObjeto obj1;
    cuentaObjeto::mostrarResumen(); //  1era

    {
        cuentaObjeto obj2(obj1);
        cuentaObjeto::mostrarResumen(); //  2da

        cuentaObjeto *obj3 = new cuentaObjeto();
        *obj3 = obj2.metodo();
        cuentaObjeto::mostrarResumen(); //  3ra

        // delete obj3; // Liberar la memoria
    }

    cuentaObjeto::mostrarResumen(); //resumen final

    return 0;
}