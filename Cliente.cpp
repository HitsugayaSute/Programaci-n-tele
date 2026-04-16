#include "Cliente.hpp"
#include <iostream>
using namespace std;
Cliente::Cliente(string nom, string ape, string ide, string tel, string mail)
    : Persona(nom, ape, ide, tel) {
    correo = mail;
}
string Cliente::getCorreo() { return correo; }
vector<Venta*> Cliente::getHistorial() { return historialCompras; }
void Cliente::setCorreo(string mail) { correo = mail; }
void Cliente::agregarCompra(Venta* venta) {
    historialCompras.push_back(venta);
}
double Cliente::getTotalGastado() {
    double total = 0;
    for (int i = 0; i < historialCompras.size(); i++) {
        // Necesitamos getTotal() de Venta, pero eso lo implementa Persona C
        // Por ahora dejamos comentado o retornamos 0
        // total += historialCompras[i]->getTotal();
    }
    return total;
}
int Cliente::getCantidadCompras() {
    return historialCompras.size();
}
void Cliente::mostrarHistorial() {
    cout << "Historial de compras de " << getNombreCompleto() << endl;
    for (int i = 0; i < historialCompras.size(); i++) {
        // historialCompras[i]->mostrarResumen();
    }
}
void Cliente::mostrarInfo() {
    Persona::mostrarInfo();
    cout << "Correo: " << correo << endl;
    cout << "Compras realizadas: " << getCantidadCompras() << endl;
}