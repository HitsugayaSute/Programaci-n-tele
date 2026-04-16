#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.hpp"
class Empleado: public Persona{
private:
string cargo;
double salario;
public:
Empleado(string nom,string ap,string ide,string tel,string car,double sal);
string getCargo();
double getSalario();
void setCargo(string car);
void setSalario(string Sal);
void actualizarSalario(double nuevoSalario);
void mostrarInfo();
};
#endif