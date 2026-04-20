#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"
#include <vector>
#include <string>

class Venta;

class Cliente : public Persona{
private:
    std::string correo;
    std::vector<Venta> historialCompras;
public:
    Cliente();
    Cliente(std::string nombre, std::string apellido, std::string id,
            std::string telefono, std::string correo);
    std::string getCorreo();
    std::vector<Venta> getHistorialCompras();
    void setCorreo(std::string correo);
    void agregarCompra(const Venta& venta);
    void mostrarHistorial();
    void mostrar();
    //Yo
    std::string toJSON() const;
    static Cliente fromJSON(std::string json);
};

#endif