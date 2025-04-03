#include <iostream>
#include <complex>
#include <variant>
#include "definiciones2.hpp"

using namespace std;

int main() {
    
    Entero entero1(0); 
    Real real1(0.0);
    Complejo complejo1(0.0, 0.0);

    Tipo resultadoEnteroSuma = entero1.suma(5, 3);    //Ejemplifico el uso de todos los incizos
    Tipo resultadoEnteroResta = entero1.resta(10, 7);
    Tipo resultadoEnteroMulti = entero1.multi(4, 2);

    cout << "Suma de enteros: " << std::get<int>(resultadoEnteroSuma) << endl;
    cout << "Resta de enteros: " << std::get<int>(resultadoEnteroResta) << endl;
    cout << "Multiplicación de enteros: " << std::get<int>(resultadoEnteroMulti) << endl;

    Tipo resultadoRealSuma = real1.suma(5.5, 2.3);
    Tipo resultadoRealResta = real1.resta(10.1, 7.2);
    Tipo resultadoRealMulti = real1.multi(4.2, 2.0);

    cout << "Suma de reales: " << std::get<double>(resultadoRealSuma) << endl;
    cout << "Resta de reales: " << std::get<double>(resultadoRealResta) << endl;
    cout << "Multiplicación de reales: " << std::get<double>(resultadoRealMulti) << endl;

    std::complex<double> c1(1, 2); 
    std::complex<double> c2(3, 4); 
    Tipo resultadoComplejoSuma = complejo1.suma(c1, c2);
    Tipo resultadoComplejoResta = complejo1.resta(c1, c2);
    Tipo resultadoComplejoMulti = complejo1.multi(c1, c2);

    cout << "Suma de complejos: " << std::get<std::complex<double>>(resultadoComplejoSuma) << endl;
    cout << "Resta de complejos: " << std::get<std::complex<double>>(resultadoComplejoResta) << endl;
    cout << "Multiplicación de complejos: " << std::get<std::complex<double>>(resultadoComplejoMulti) << endl;

    return 0;
}
