#include "Producto.h"
#include <iostream>
#include <sstream>
using namespace std;

Producto::Producto() {
    id=0;
    precio=0;
    stock=0;
    costo=0;
}
Producto::Producto(int id, string nombre, string categoria, double precio, int stock, double costo) {
    this->id=id;
    this->nombre=nombre;
    this->categoria=categoria;
    this->precio=precio;
    this->stock=stock;
    this->costo=costo;
}
int Producto::getId() {
    return id;
}
string Producto::getNombre() {
    return nombre;
}
string Producto::getCategoria() {
    return categoria;
}
double Producto::getPrecio() {
    return precio;
}
int Producto::getStock() {
    return stock;
}
double Producto::getCosto() {
    return costo;
}
void Producto::setId(int id) {
    this->id=id;
}
void Producto::setNombre(string nombre) {
    this->nombre=nombre;
}
void Producto::setCategoria(string categoria) {
    this->categoria=categoria;
}
void Producto::setPrecio(double precio) {
    this->precio=precio;
}
void Producto::setStock(int stock) {
    this->stock=stock;
}
void Producto::setCosto(double costo) {
    this->costo=costo;
}
void Producto::actualizarStock(int cantidad) {
    stock +=cantidad;
}
void Producto::mostrar(){
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Precio: " << precio << endl;
    cout << "Stock: " << stock << endl;
    cout << "Costo: " << costo << endl;
}
//Yo
//Para ingresar los datos en la libreria, pasando los que ya... en fin para guardar datos
    string Producto::toJSON() const{
    stringstream ss;
    ss << "{";
    ss << "\"id\":" << id << ",";
    ss << "\"nombre\":\"" << nombre << "\",";
    ss << "\"categoria\":\"" << categoria << "\",";
    ss << "\"precio\":" << precio << ",";
    ss << "\"stock\":" << stock << ",";
    ss << "\"costo\":" << costo;
    ss << "}";
    return ss.str();
}
//Y esto para sacarlos
static string extraerValor(string json, string clave){
    size_t pos=json.find("\"" + clave + "\"");
    if(pos==string::npos) return "";
    pos=json.find(":", pos);
    if(pos==string::npos) return "";
    pos++;
    while(pos<json.size()&&(json[pos]== ' ' || json[pos]=='\"')) pos++;
    size_t end = pos;
    if(json[pos]=='\"'){
        pos++;
        end=json.find("\"", pos);
        return json.substr(pos, end - pos);
    }else{
        while(end<json.size() &&
               json[end] !=',' &&
               json[end] !='}' &&
               json[end] != ' '){
            end++;
        }
        return json.substr(pos, end - pos);
    }
}
Producto Producto::fromJSON(string json){
    Producto p;
    p.setId(atoi(extraerValor(json,"id").c_str()));
    p.setNombre(extraerValor(json,"nombre"));
    p.setCategoria(extraerValor(json,"categoria"));
    p.setPrecio(atof(extraerValor(json,"precio").c_str()));
    p.setStock(atoi(extraerValor(json,"stock").c_str()));
    p.setCosto(atof(extraerValor(json,"costo").c_str()));
    return p;
}