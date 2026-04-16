#include "Empleado.hpp"
#include <iostream>
using namespace std;
Empleado::Empleado(string nom, string ape, string ide, string tel, string car, double sal)
    : Persona(nom, ape, ide, tel) {
    cargo = car;
    salario = sal;
}
string Empleado::getCargo() { return cargo; }
double Empleado::getSalario() { return salario; }
void Empleado::setCargo(string car) { cargo = car; }
void Empleado::setSalario(double sal) { salario = sal; }

void Empleado::actualizarSalario(double nuevoSalario) {
    if (nuevoSalario > 0) {
        salario = nuevoSalario;
    } else {
        cout << "Error: salario invalido" << endl;
    }
}
void Empleado::mostrarInfo() {
    Persona::mostrarInfo();
    cout << "Cargo: " << cargo << endl;
    cout << "Salario: $" << salario << endl;
}