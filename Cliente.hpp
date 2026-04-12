#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.hpp"
#include <vector>
// Declaración adelantada (Venta lo hace Persona C)
class Venta;
class Cliente : public Persona {
private:
    string correo;
    vector<Venta*> historialCompras; 
    public:
    Cliente(string nom, string ape, string ide, string tel, string mail);
    string getCorreo();
    vector<Venta*> getHistorial();
    void setCorreo(string mail);
    void agregarCompra(Venta* venta);
    double getTotalGastado();
    int getCantidadCompras();
    void mostrarHistorial();
    void mostrarInfo();
};

#endif