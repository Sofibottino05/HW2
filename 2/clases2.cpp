#include "definiciones2.hpp"
#include <set>

curso::curso(string nombre) {
    this->nombre = nombre;
}

curso::curso(const curso& otro) : nombre(otro.nombre), estudiantes(otro.estudiantes) {}

curso& curso::operator=(const curso& otro) {   // operador para haer deep copy de la clase
    if (this == &otro) return *this; // Evitar autoasignación del objeto a si mismo

    nombre = otro.nombre;
    estudiantes = otro.estudiantes; // Se copian todos los estudiantes

    return *this;
}

void curso::inscribir(Estudiante estudiante) {  // Inscribe los estudiantes sii el curso tiene menos de 20 alumnos
    if (estudiantes.size() < 20) { 
        estudiantes.push_back(estudiante);
    } else {
        cout << "Clase llena, no se pueden agregar más estudiantes.\n";
    }
}

void curso::desinscribir(string estudiante) {  // Desinscribe los estudiantes pasados como parametro en formato de string
    estudiantes.erase(remove_if(estudiantes.begin(), estudiantes.end(),
                    [&](const Estudiante& e) { return e.getNombre() == estudiante; }),  
                    estudiantes.end());
}

bool curso::esta_ins(string estudiante) {  // Verifica si el estudiante pasado como string esta inscripto
    return find_if(estudiantes.begin(), estudiantes.end(),
                   [&](const Estudiante& e) { return e.getNombre() == estudiante; })
           != estudiantes.end();
}

bool curso::esta_com() {    // Verifica si el curso tiene 20 estudiantes o no
    if (estudiantes.size() >= 20) {
        cout << "Clase llena\n";
        return true;
    } else {
        cout << "La clase todavía cuenta con vacantes\n";
        return false;
    }
}

void curso::print() {  // imprime el curso en orden alfabetico, usando set
    cout << "Curso: " << nombre << "\n";
    cout << "Estudiantes (ordenados automáticamente por nombre):\n";

    set<string> nombresOrdenados;
    for (const auto& e : estudiantes) {
        nombresOrdenados.insert(e.getNombre());
    }

    for (const auto& nombre : nombresOrdenados) {
        cout << nombre << "\n";
    }
}

Estudiante::Estudiante(string nombre, int nro_legajo, double promedio) // Constructor de estudiante
    : nombre(nombre), nro_legajo(nro_legajo), promedio(promedio) {}

void Estudiante::print() const {  // imprime los datos de los estudiantes
    cout << "Nombre: " << nombre << ", Legajo: " << nro_legajo << ", Promedio: " << promedio << "\n";
}
