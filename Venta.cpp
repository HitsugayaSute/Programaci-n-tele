#include "Venta.h"
#include "Utils.h"
#include <iostream>
#include <sstream>
using namespace std;

Venta::Venta() {
    id =0;
    total=0;
}
Venta::Venta(int id, string idCliente, string nombreCliente, string fecha) {
    this->id = id;
    this->idCliente = idCliente;
    this->nombreCliente = nombreCliente;
    this->fecha = fecha;
    total=0;
}
int Venta::getId() {
    return id;
}
string Venta::getIdCliente() {
    return idCliente;
}
string Venta::getNombreCliente() {
    return nombreCliente;
}
string Venta::getFecha() {
    return fecha;
}
vector<Producto> Venta::getProductos() {
    return productos;
}
double Venta::getTotal() {
    return total;
}
void Venta::setId(int id) {
    this->id= id;
}
void Venta::setIdCliente(string idCliente) {
    this->idCliente=idCliente;
}
void Venta::setNombreCliente(string nombreCliente) {
    this->nombreCliente=nombreCliente;
}
void Venta::setFecha(string fecha) {
    this->fecha =fecha;
}
void Venta::agregarProducto(const Producto& producto) {
    productos.push_back(producto);
    calcularTotal();
}
void Venta::eliminarProducto(int idProducto) {
    for (int i=0; i <productos.size(); i++) {
        if (productos[i].getId()==idProducto) {
            productos.erase(productos.begin() + i);
            break;
        }
    }
    calcularTotal();
}
void Venta::calcularTotal() {
    total=0;
    for(int i=0; i< productos.size(); i++){
        total += productos[i].getPrecio();
    }
}

void Venta::mostrarResumen() {
    cout << "ID Venta: " << id << endl;
    cout << "Cliente: "<<nombreCliente << " (" << idCliente<< ")" <<endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Productos vendidos: "<< productos.size() << endl;
    for (int i=0; i<productos.size(); i++) {
        cout << "  - " << productos[i].getNombre()
             << " | Precio: " << productos[i].getPrecio() << endl; //Para organizar un poco el menu
    }
    cout << "Total: " << total << endl;
}
//Yo
string Venta::toJSON() const{
    stringstream ss;
    ss << "{";
    ss << "\"id\":" << id << ",";
    ss << "\"idCliente\":\"" << idCliente << "\",";
    ss << "\"nombreCliente\":\"" << nombreCliente << "\",";
    ss << "\"fecha\":\"" << fecha << "\",";
    ss << "\"total\":" << total;
    ss << "}";
    return ss.str();
}
Venta Venta::fromJSON(string json){
    Venta v;
    v.setId(atoi(extraerValor(json,"id").c_str()));
    v.setIdCliente(extraerValor(json,"idCliente"));
    v.setNombreCliente(extraerValor(json,"nombreCliente"));
    v.setFecha(extraerValor(json,"fecha"));
    return v;
}