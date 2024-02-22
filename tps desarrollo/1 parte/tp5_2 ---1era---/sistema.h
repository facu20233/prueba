// sistema.h
#include <iostream>
#include <vector>
#include "cuenta.h"

class Sistema
{
private:
    std::vector<Cuenta *> cuentas;

public:
    Sistema()
    {
        // Constructor del sistema, aquí puedes realizar inicializaciones.
    }

    ~Sistema()
    {
        // Destructor del sistema, aquí puedes realizar limpieza si es necesaria.
        for (Cuenta *cuenta : cuentas)
        {
            delete cuenta;
        }
    }

    void facturarUsuarios(int mesActual)
    {
        // Recorre todas las cuentas y calcula el monto a pagar para cada una.
        cout << "-----facturar---" << endl;
        float montoTotal = 0.0;
        for (Cuenta *cuenta : cuentas)
        {
            float monto = cuenta->montoPagarPorMes(mesActual);
            montoTotal += monto;
        }
        cout << "Monto total: $" << montoTotal << endl;
    }

    void agregarCuenta(const string &correo,const string &tarjeta)
    {
        Cuenta *nuevaCuenta = new Cuenta(correo, tarjeta);
        cuentas.push_back(nuevaCuenta);
    }

    const vector<Cuenta*>& getCuentas(){
        return cuentas;
    }
};
