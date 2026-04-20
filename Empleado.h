#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"
#include <string>

class Empleado : public Persona {
private:
    std::string cargo;
    double salario;
public:
    Empleado();
    Empleado(std::string nombre, std::string apellido, std::string id,
             std::string telefono, std::string cargo, double salario);
    std::string getCargo();
    double getSalario();
    void setCargo(std::string cargo);
    void setSalario(double salario);
    void actualizarSalario(double nuevoSalario);
    void mostrar();
    //Yo
    std::string toJSON() const;
    static Empleado fromJSON(std::string json);
};
#endif