#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>

class Producto {
private:
    int id;
    std::string nombre;
    std::string categoria;
    double precio;
    int stock;
    double costo;
public:
    Producto();
    Producto(int id, std::string nombre, std::string categoria, double precio, int stock, double costo);
    int getId();
    std::string getNombre();
    std::string getCategoria();
    double getPrecio();
    int getStock();
    double getCosto();
    void setId(int id);
    void setNombre(std::string nombre);
    void setCategoria(std::string categoria);
    void setPrecio(double precio);
    void setStock(int stock);
    void setCosto(double costo);
    void actualizarStock(int cantidad);
    void mostrar();
    //Yo
    std::string toJSON() const; //Esto es para guardar los datos en el JSON que se va a usar cmo supuesta libreria
    static Producto fromJSON(std::string json);
};
#endif