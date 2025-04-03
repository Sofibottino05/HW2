#ifndef DEFINICIONES1_HPP
#define DEFINICIONES1_HPP

#include <iostream>  //Archivo header.

using namespace std;

class Reloj {
private:
    double hs;
    double min;
    double sec;
    bool ampm;

public:
    Reloj(double h, double m, double s, bool ampm);
    Reloj(double h, double m, double s);
    Reloj(double h, double m);
    Reloj(double h);
    Reloj();
    void getHora();
};

#endif