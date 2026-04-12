#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string>
using namespace std;
class Persona{
protected:
string nombre;
string apellido;
string id;
string telefono;
public:
Persona();
Persona(string nom, string ape, string id,string tel);
string getNombre();
string getApellido();
string getId();
string getTelefono();
void setNombre(string nom);
void setApellido(string ape);
void setTelefono(string tel);
string getNombreCompleto();
void mostrarInfo();
};
#endif