#include "definiciones1.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Reloj::Reloj(double hs, double min, double sec, bool ampm) {
    this->hs = hs;
    this->min = min;
    this->sec = sec;
    this->ampm = ampm;
}

Reloj::Reloj(double hs, double min, double sec) : Reloj(hs, min, sec, false) {} // Constructor de Reloj que toma parametros de hora, minutos y segundos, y asigna automaticamente AM.

Reloj::Reloj(double hs, double min) : Reloj(hs, min, 0, false) {}// Consrtuctor de Reloj que toma los parametros horas y minutos, y asigna automaticamente 00 a los segundos, y AM.

Reloj::Reloj(double hs) : Reloj(hs, 0, 0, false) {}// Constructor de Reloj que toma unicamente el parametro hora, y asigna en 00 minutos y segundos, y en AM.

Reloj::Reloj() : Reloj(0, 0, 0, false) {}//Constructor predeterminado para reloj, que no toma parametros, y setea en 00 todos los valores numericos, y en AM ampm.

void Reloj::getHora() {// Getter de la hora
    cout << "Son las: "<< setw(2) << setfill('0') << hs << ":"   //Uso la libreria iomanip para completar los espacios de 0 en los horarios.
         << setw(2) << setfill('0') << min << ":"
         << setw(2) << setfill('0') << sec
         << (ampm ? " PM" : " AM") << endl;
}
