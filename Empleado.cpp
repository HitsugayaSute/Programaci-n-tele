#include "Empleado.h"
#include "Utils.h"
#include <iostream>
#include <sstream>
using namespace std;

Empleado::Empleado() : Persona() {
    salario=0;
}
Empleado::Empleado(string nombre, string apellido, string id, string telefono, string cargo, double salario)
: Persona(nombre, apellido, id, telefono) {
    this->cargo=cargo;
    this->salario=salario;
}
string Empleado::getCargo() {
    return cargo;
}
double Empleado::getSalario() {
    return salario;
}
void Empleado::setCargo(string cargo) {
    this->cargo=cargo;
}
void Empleado::setSalario(double salario) {
    this->salario=salario;
}
void Empleado::actualizarSalario(double nuevoSalario) {
    salario=nuevoSalario;
}
void Empleado::mostrar() {
    Persona::mostrar();
    cout << "Cargo: " << cargo << endl;
    cout << "Salario: " << salario << endl;
}
//Yo
string Empleado::toJSON() const{
    stringstream ss;
    ss << "{";
    ss << "\"id\":\"" << id << "\",";
    ss << "\"nombre\":\"" << nombre << "\",";
    ss << "\"apellido\":\"" << apellido << "\",";
    ss << "\"telefono\":\"" << telefono << "\",";
    ss << "\"cargo\":\"" << cargo << "\",";
    ss << "\"salario\":" << salario;
    ss << "}";
    return ss.str();
}
Empleado Empleado::fromJSON(string json){
    Empleado e;
    e.setId(extraerValor(json,"id"));
    e.setNombre(extraerValor(json,"nombre"));
    e.setApellido(extraerValor(json,"apellido"));
    e.setTelefono(extraerValor(json,"telefono"));
    e.setCargo(extraerValor(json,"cargo"));
    e.setSalario(atof(extraerValor(json,"salario").c_str()));
    return e;
}