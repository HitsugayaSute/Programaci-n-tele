#include "Persona.hpp"
Persona::Persona(string nom, string ape, string ide, string tel) {
    nombre = nom;
    apellido = ape;
    id = ide;
    telefono = tel;
}
string Persona::getNombre() { return nombre; }
string Persona::getApellido() { return apellido; }
string Persona::getId() { return id; }
string Persona::getTelefono() { return telefono; }
void Persona::setNombre(string nom) { nombre = nom; }
void Persona::setApellido(string ape) { apellido = ape; }
void Persona::setTelefono(string tel) { telefono = tel; }
string Persona::getNombreCompleto() {
    return nombre + " " + apellido;
}
void Persona::mostrarInfo() {
    cout << "Nombre: " << nombre << " " << apellido << endl;
    cout << "ID: " << id << endl;
    cout << "Teléfono: " << telefono << endl;
}