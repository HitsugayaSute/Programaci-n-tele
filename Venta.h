#ifndef VENTA_H
#define VENTA_H
#include <string>
#include <vector>
#include "Producto.h"
using namespace std;

class Venta {
private:
    int id;
    string idCliente;
    string nombreCliente;
    string fecha;
    vector<Producto> productos;
    double total;
public:
    Venta();
    Venta(int id, string idCliente, string nombreCliente, string fecha);
    int getId();
    string getIdCliente();
    string getNombreCliente();
    string getFecha();
    vector<Producto> getProductos();
    double getTotal();
    void setId(int id);
    void setIdCliente(string idCliente);
    void setNombreCliente(string nombreCliente);
    void setFecha(string fecha);
    void agregarProducto(const Producto& producto);
    void eliminarProducto(int idProducto);
    void calcularTotal();
    void mostrarResumen();

    string toJSON() const;
    static Venta fromJSON(string json);
};
#endif