#include <iostream>
#include <memory>
using namespace std;

class Numero {
public:
    virtual shared_ptr<Numero> suma(shared_ptr<Numero> otro) const = 0;
    virtual shared_ptr<Numero> resta(shared_ptr<Numero> otro) const = 0;
    virtual shared_ptr<Numero> multi(shared_ptr<Numero> otro) const = 0;
    virtual void imprimir() const = 0;
    virtual ~Numero() = default;
};

class Entero : public Numero {
private:
    int valor;

public:
    Entero(int v) : valor(v) {}

    shared_ptr<Numero> suma(shared_ptr<Numero> otro) const override;
    shared_ptr<Numero> resta(shared_ptr<Numero> otro) const override;
    shared_ptr<Numero> multi(shared_ptr<Numero> otro) const override;

    void imprimir() const override {
        cout << valor;
    }

    int getValor() const {
        return valor;
    }
};

class Real : public Numero {
private:
    double valor;

public:
    Real(double v) : valor(v) {}

    shared_ptr<Numero> suma(shared_ptr<Numero> otro) const override;
    shared_ptr<Numero> resta(shared_ptr<Numero> otro) const override;
    shared_ptr<Numero> multi(shared_ptr<Numero> otro) const override;

    void imprimir() const override {
        cout << valor;
    }

    double getValor() const {
        return valor;
    }
};

class Complejo : public Numero {
private:
    double real;
    double imag;

public:
    Complejo(double r, double i) : real(r), imag(i) {}

    shared_ptr<Numero> suma(shared_ptr<Numero> otro) const override;
    shared_ptr<Numero> resta(shared_ptr<Numero> otro) const override;
    shared_ptr<Numero> multi(shared_ptr<Numero> otro) const override;

    void imprimir() const override {
        cout << "(" << real << " + " << imag << "i)";
    }

    double getReal() const {
        return real;
    }

    double getImag() const {
        return imag;
    }
};

// Implementaciones para Entero
shared_ptr<Numero> Entero::suma(shared_ptr<Numero> otro) const {
    if (auto ptr = dynamic_pointer_cast<Entero>(otro))
        return make_shared<Entero>(valor + ptr->getValor());
    else if (auto ptr = dynamic_pointer_cast<Real>(otro))
        return make_shared<Real>(valor + ptr->getValor());
    return nullptr;
}

shared_ptr<Numero> Entero::resta(shared_ptr<Numero> otro) const {
    if (auto ptr = dynamic_pointer_cast<Entero>(otro))
        return make_shared<Entero>(valor - ptr->getValor());
    else if (auto ptr = dynamic_pointer_cast<Real>(otro))
        return make_shared<Real>(valor - ptr->getValor());
    return nullptr;
}

shared_ptr<Numero> Entero::multi(shared_ptr<Numero> otro) const {
    if (auto ptr = dynamic_pointer_cast<Entero>(otro))
        return make_shared<Entero>(valor * ptr->getValor());
    else if (auto ptr = dynamic_pointer_cast<Real>(otro))
        return make_shared<Real>(valor * ptr->getValor());
    return nullptr;
}

// Funciones para Real
shared_ptr<Numero> Real::suma(shared_ptr<Numero> otro) const {
    if (auto ptr = dynamic_pointer_cast<Real>(otro))
        return make_shared<Real>(valor + ptr->getValor());
    else if (auto ptr = dynamic_pointer_cast<Entero>(otro))
        return make_shared<Real>(valor + ptr->getValor());
    return nullptr;
}

shared_ptr<Numero> Real::resta(shared_ptr<Numero> otro) const {
    if (auto ptr = dynamic_pointer_cast<Real>(otro))
        return make_shared<Real>(valor - ptr->getValor());
    else if (auto ptr = dynamic_pointer_cast<Entero>(otro))
        return make_shared<Real>(valor - ptr->getValor());
    return nullptr;
}

shared_ptr<Numero> Real::multi(shared_ptr<Numero> otro) const {
    if (auto ptr = dynamic_pointer_cast<Real>(otro))
        return make_shared<Real>(valor * ptr->getValor());
    else if (auto ptr = dynamic_pointer_cast<Entero>(otro))
        return make_shared<Real>(valor * ptr->getValor());
    return nullptr;
}

// Funciones para Complejo
shared_ptr<Numero> Complejo::suma(shared_ptr<Numero> otro) const {
    auto ptr = dynamic_pointer_cast<Complejo>(otro);
    if (ptr)
        return make_shared<Complejo>(real + ptr->getReal(), imag + ptr->getImag());
    return nullptr;
}

shared_ptr<Numero> Complejo::resta(shared_ptr<Numero> otro) const {
    auto ptr = dynamic_pointer_cast<Complejo>(otro);
    if (ptr)
        return make_shared<Complejo>(real - ptr->getReal(), imag - ptr->getImag());
    return nullptr;
}

shared_ptr<Numero> Complejo::multi(shared_ptr<Numero> otro) const {
    auto ptr = dynamic_pointer_cast<Complejo>(otro);
    if (ptr) {
        double r = real * ptr->getReal() - imag * ptr->getImag();
        double i = real * ptr->getImag() + imag * ptr->getReal();
        return make_shared<Complejo>(r, i);
    }
    return nullptr;
}

// Función main con pruebas
int main() {
    shared_ptr<Numero> e1 = make_shared<Entero>(4);
    shared_ptr<Numero> e2 = make_shared<Entero>(7);
    shared_ptr<Numero> r1 = make_shared<Real>(3.5);
    shared_ptr<Numero> r2 = make_shared<Real>(2.0);
    shared_ptr<Numero> c1 = make_shared<Complejo>(2.0, 1.0);
    shared_ptr<Numero> c2 = make_shared<Complejo>(1.0, 3.0);

    // Entero + Entero
    cout << "Entero + Entero: ";
    auto res1 = e1->suma(e2);
    if (res1) res1->imprimir();
    cout << endl;

    // Entero + Real
    cout << "Entero + Real: ";
    auto res2 = e1->suma(r1);
    if (res2) res2->imprimir();
    cout << endl;

    // Real * Entero
    cout << "Real * Entero: ";
    auto res3 = r1->multi(e2);
    if (res3) res3->imprimir();
    cout << endl;

    // Complejo + Complejo
    cout << "Complejo + Complejo: ";
    auto res4 = c1->suma(c2);
    if (res4) res4->imprimir();
    cout << endl;

    // Entero + Complejo (no compatible)
    cout << "Entero + Complejo: ";
    auto res5 = e1->suma(c1);
    if (res5)
        res5->imprimir();
    else
        cout << "Tipos incompatibles.";
    cout << endl;

    return 0;
}
