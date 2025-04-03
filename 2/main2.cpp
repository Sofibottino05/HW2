#include "definiciones2.hpp"
#include <iostream>
#include <iomanip>

int main() {
    curso miCurso("Programación Avanzada");
    curso miCurso2("Álgebra Lineal");

    Estudiante e1("Sofia", 1001, 9.2);
    Estudiante e2("Eduardo", 1002, 7.8);
    Estudiante e3("Ana", 1003, 8.5);
    Estudiante e4("Luis", 1004, 6.9);
    Estudiante e5("Maria", 1005, 8.2);
    Estudiante e6("Carla", 1006, 9.5);

    miCurso.inscribir(e1);
    miCurso.inscribir(e2);
    miCurso.inscribir(e3);
    miCurso.inscribir(e4);
    miCurso.inscribir(e5);

    cout << "\n--- Lista de estudiantes ---\n";
    miCurso.print();

    string nombre_buscar = "Ana";
    if (miCurso.esta_ins(nombre_buscar)) {
        cout << "\n" << nombre_buscar << " Ana está inscrita en el curso.\n";
    } else {
        cout << "\n" << nombre_buscar << " Ana no está inscrita en el curso.\n";
    }

    cout << "\n--- Desinscribiendo a Eduardo ---\n";
    miCurso.desinscribir("Eduardo");

    cout << "\n--- Lista después de la baja ---\n";
    miCurso.print();

    miCurso2 = miCurso;

    cout << "\n--- Lista después de la copia ---\n";
    miCurso2.print();

    cout << "\n--- Desinscribiendo a Ana ---\n";
    miCurso2.desinscribir("Ana");

    cout << "\n--- Desinscribiendo a Luis ---\n";
    miCurso.desinscribir("Luis");

    cout << "\n--- Inscribiendo a Carla al nuevo curso ---\n";
    miCurso.inscribir(e6);

    cout << "\n--- Lista después de la copia modificada ---\n";
    miCurso2.print();

    return 0;
}
