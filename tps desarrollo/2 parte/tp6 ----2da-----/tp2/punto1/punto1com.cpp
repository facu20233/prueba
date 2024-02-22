  #include <iostream>

class CuentaObjeto {
private:
    // atributos
    static int objCreados;  //estatico    
    static int objDestruidos; //estatico  
public:
    //metodo 
    // clase
    CuentaObjeto() {
        objCreados++;
    }

    CuentaObjeto(const CuentaObjeto&) {
        objCreados++;
    }

    CuentaObjeto& metodo() {
        return *this;
    }

    static void mostrarResumen() {
        std::cout << "Objetos creados: " << objCreados << std::endl;
        std::cout << "Objetos destruidos: " << objDestruidos << std::endl;
    }

    // destr
    ~CuentaObjeto() {
        objDestruidos++;
    }
};

// ----------

// Inicializar contadores estáticos
int CuentaObjeto::objCreados = 0;
int CuentaObjeto::objDestruidos = 0;

int main() {
    std::cout << "!!!Hello World!!!" << std::endl;

    CuentaObjeto obj1;
    CuentaObjeto::mostrarResumen(); //  1era

    {
        CuentaObjeto obj2(obj1);
        CuentaObjeto::mostrarResumen(); //  2da

        CuentaObjeto *obj3 = new CuentaObjeto();
        *obj3 = obj2.metodo();
        CuentaObjeto::mostrarResumen(); //  3ra

        // delete obj3; // Liberar la memoria
    }

    CuentaObjeto::mostrarResumen(); //resumen final

    return 0;
}