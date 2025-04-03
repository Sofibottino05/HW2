#include <iostream>
#include "definiciones1.hpp"
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

vector<double> splitline(const std::string& str) { // cree un metodo splitline para poder dividir string del input del horario, y guardar los horarios en variables separadas
    std::vector<double> numeros;                   // para luego pasarlos como parametros al instanciar la clase Reloj.
    std::istringstream ss(str);
    double num;
    while (ss >> num) {
        numeros.push_back(num);
    }
    return numeros;
}

int main() {
    double hs = 0, min = 0, sec = 0;
    bool ampm = 0;
    string texto;

    while (true) {
        cout << "Ingrese la hora (HH MM SS AM/PM [0 = AM, 1 = PM]): ";
        getline(cin, texto);                                                //Uso splitline y guardo los int en mis variables

        vector<double> numeros = splitline(texto);

        if (numeros.size() > 0) hs = numeros[0];
        if (numeros.size() > 1) min = numeros[1];
        if (numeros.size() > 2) sec = numeros[2];
        if (numeros.size() > 3) ampm = (numeros[3] != 0);

        if (hs >= 1 && hs <= 12 && min >= 0 && min <= 59 && sec >= 0 && sec <= 59) {
            break;  
        } else {
            cout << "Horario fuera de rango, ingrese nuevamente los datos." << endl;
        }
    }

    Reloj R;              //Inicializo mi objeto Reloj, y llamo al constructir adecuado dependiendo de la cantidad de variables que inserté en el input.
    if (texto.empty()) {
        R = Reloj();
    } else if (splitline(texto).size() == 1) {
        R = Reloj(hs);
    } else if (splitline(texto).size() == 2) {
        R = Reloj(hs, min);
    } else if (splitline(texto).size() == 3) {
        R = Reloj(hs, min, sec);
    } else {
        R = Reloj(hs, min, sec, ampm);
    }

    R.getHora();     // Imprimo la hora ingresada
    return 0;
}
