#ifndef DEFINICIONES2_HPP
#define DEFINICIONES2_HPP

#include <vector> 
#include <iostream>
#include <string>
#include <algorithm>  // Para remove y find

using namespace std;

class Estudiante {  
    string nombre;
    int nro_legajo;
    double promedio;
                                                                    
public:
    Estudiante(string nombre, int nro_legajo, double promedio);
    string getNombre() const { return nombre; }
    void print() const;
};

class curso {
    string nombre;
    vector<Estudiante> estudiantes;

public:
    curso(string nombre);
    curso(const curso& otro);
    curso& operator=(const curso& otro);
    
    void inscribir(Estudiante estudiante);
    void desinscribir(string estudiante);
    bool esta_ins(string estudiante);
    bool esta_com();
    void print();
};

#endif
