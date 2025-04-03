#include <iostream>
#include <complex>
#include <variant>
#include "definiciones3.hpp"

using namespace std;
using Tipo = variant<int, double, complex<double>>;  //Uso variant para declarar mis constructores virtuales puros de forma generica, y ahorrar codigo
                                                        //a la hora de tener que hacer los constructores de las clases derivadas de numero, ya que los 3 tipos de numeros
class Numero {                                               // devuelven como output un tipo de variable diferente.
public:
    virtual Tipo suma(Tipo valor1, Tipo valor2) = 0;
    virtual Tipo resta(Tipo valor1, Tipo valor2) = 0; 
    virtual Tipo multi(Tipo valor1, Tipo valor2) = 0;

    virtual ~Numero() {}
};

class Entero : public Numero {
    int valor;

public:                                  //Declaro todas mis clases con su debido valor, incluyendo la clase complex para definir el valor del numero complejo
    Entero(int v) : valor(v) {}

    Tipo suma(Tipo valor1, Tipo valor2) override {
        return get<int>(valor1) + get<int>(valor2);
    }

    Tipo resta(Tipo valor1, Tipo valor2) override {
        return get<int>(valor1) - get<int>(valor2);
    }

    Tipo multi(Tipo valor1, Tipo valor2) override {
        return get<int>(valor1) * get<int>(valor2);
    }
};

class Real : public Numero {
    double valor;

public:
    Real(double v) : valor(v) {}

    Tipo suma(Tipo valor1, Tipo valor2) override {
        return get<double>(valor1) + get<double>(valor2);
    }

    Tipo resta(Tipo valor1, Tipo valor2) override {
        return get<double>(valor1) - get<double>(valor2);
    }

    Tipo multi(Tipo valor1, Tipo valor2) override {
        return :get<double>(valor1) * get<double>(valor2);
    }
};

class Complejo : public Numero {
    complex<double> valor;

public:
    Complejo(double real, double imaginario) 
        : valor(real, imaginario) {}

    Tipo suma(Tipo valor1, Tipo valor2) override {
        return get<complex<double>>(valor1) + get<complex<double>>(valor2);
    }

    Tipo resta(Tipo valor1, Tipo valor2) override {
        return get<complex<double>>(valor1) - get<complex<double>>(valor2);
    }

    Tipo multi(Tipo valor1, Tipo valor2) override {
        return get<complex<double>>(valor1) * get<complex<double>>(valor2);
    }
};
