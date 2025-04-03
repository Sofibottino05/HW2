#include <vector> 
#include <iostream>
#include <string>
#include <algorithm>  

using namespace std;

class CuentaCorriente; 

class Banco {
protected:
    double balance;
    string titularCuenta;

public:
    Banco(string nombre) {
        balance = 0;
        titularCuenta = nombre;
    }

    void depositar(double monto) {
        balance += monto;
    }

    virtual double retirar(double monto) = 0;
    virtual void mostrar_info() = 0;
};

class CajaDeAhorro : public Banco {
    int veces = 0;

public:
    CajaDeAhorro(string nombre) : Banco(nombre) {}

    double retirar(double monto) override {
        if (balance < monto) {
            cout << "No hay suficientes fondos en la Caja de Ahorro\n";
            return 0;
        } else {
            balance -= monto;
            return monto;
        }
    }

    void mostrar_info() override {
        cout << "Nombre: " << titularCuenta << "\n"
             << "Balance de caja de ahorro: " << balance << "\n";
        if (veces > 2) {
            balance -= 20;
        }
    }

    friend class CuentaCorriente;  //Uso friend para que CajaDeAhorro acceda a las variables y atributos de CuentaCorriente
};

class CuentaCorriente : public Banco {
    int veces = 0;
    CajaDeAhorro caja;  //Instancio CajaDeAhorro para acceder al balance en caso de no tener fondos en mi CuentaCorriente

public:
    CuentaCorriente(string nombre) : Banco(nombre), caja(nombre) {}

    double retirar(double monto) override {
        if (balance < monto) {
            if (caja.balance >= monto) { 
                caja.balance -= monto;
                cout << "Se retiraron $" << monto << " de la Caja de Ahorros." << endl;
                return monto;
            } else {
                cout << "Sin dinero disponible en cuenta\n";
                return 0;
            }
        } else {
            balance -= monto;
            cout << "Se retiraron $" << monto << " de la Cuenta Corriente." << endl;
            return monto;
        }
    }

    void mostrar_info() override {
        cout << "Nombre: " << titularCuenta << "\n"
             << "Balance de Cuenta Corriente: " << balance << "\n";
        if (veces > 2) {
            balance -= 20;
        }
    }
};