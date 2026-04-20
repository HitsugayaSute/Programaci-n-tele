#include "Persona.h"
#include "Utils.h"
#include <iostream>
using namespace std;

Persona::Persona() {}
Persona::Persona(string nombre, string apellido, string id, string telefono) {
    this->nombre=nombre;
    this->apellido =apellido;
    this->id = id;
    this->telefono= telefono;
}
string Persona::getNombre() {return nombre;}
string Persona::getApellido() {return apellido;}
string Persona::getId() { return id;}
string Persona::getTelefono() {return telefono; }

void Persona::setNombre(string nombre) { this->nombre =nombre;}
void Persona::setApellido(string apellido) {this->apellido=apellido;}
void Persona::setId(string id) { this->id=id; }
void Persona::setTelefono(string telefono) {this->telefono =telefono; }

void Persona::mostrar() {
    cout << "Nombre: " << nombre << " " << apellido << endl;
    cout << "ID: " << id << endl;
    cout << "Telefono: " << telefono << endl;
}