#include "Cliente.h"
#include "Venta.h"
#include "Utils.h"
#include <iostream>
#include <sstream>
using namespace std;

Cliente::Cliente() : Persona() {}
Cliente::Cliente(string nombre, string apellido, string id,
                 string telefono, string correo)
    : Persona(nombre, apellido, id, telefono) {
    this->correo=correo;
}
string Cliente::getCorreo() {
    return correo;
}
vector<Venta> Cliente::getHistorialCompras() {
    return historialCompras;
}
void Cliente::setCorreo(string correo) {
    this->correo=correo;
}
void Cliente::agregarCompra(const Venta& venta) {
    historialCompras.push_back(venta);
}
void Cliente::mostrarHistorial() {
    cout << "Historial de compras de " << nombre << " " << apellido << ":" << endl;
    if (historialCompras.empty()) {
        cout << "No tiene compras registradas." << endl;
        return;
    }
    for (int i = 0; i < historialCompras.size(); i++) {
        cout << "Venta " << i + 1 << endl;
        historialCompras[i].mostrarResumen();
        cout << "----------------------" << endl; //Para que tenga estetica
    }
}
void Cliente::mostrar() {
    Persona::mostrar();
    cout << "Correo: " << correo << endl;
    cout << "Cantidad de compras: " << historialCompras.size() << endl;
}
//Yo
string Cliente::toJSON() const{
    stringstream ss;
    ss << "{";
    ss << "\"id\":\"" << id << "\",";
    ss << "\"nombre\":\"" << nombre << "\",";
    ss << "\"apellido\":\"" << apellido << "\",";
    ss << "\"telefono\":\"" << telefono << "\",";
    ss << "\"correo\":\"" << correo << "\"";
    ss << "}";
    return ss.str();
}
Cliente Cliente::fromJSON(string json){
    Cliente c;
    c.setId(extraerValor(json,"id"));
    c.setNombre(extraerValor(json,"nombre"));
    c.setApellido(extraerValor(json,"apellido"));
    c.setTelefono(extraerValor(json,"telefono"));
    c.setCorreo(extraerValor(json,"correo"));
    return c;
}
