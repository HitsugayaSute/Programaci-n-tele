#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;

class Persona {
    protected:
        string nombre;
        string apellido;
        string id;
        string telefono;

    public:
        Persona();
        Persona(string nombre, string apellido, string id, string telefono);
        string getNombre();
        string getApellido();
        string getId();
        string getTelefono();

        void setNombre(string nombre);
        void setApellido(string apellido);
        void setId(string id);
        void setTelefono(string telefono);
        void mostrar();
};
#endif