#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include "Producto.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Venta.h"

/*Esto lo voy a hacer para mantener todo con organizacion y tener mas control*/
using namespace std;
class Sistema {
private:
    vector<Producto> productos;
    vector<Cliente> clientes;
    vector<Empleado> empleados;
    vector<Venta> ventas;
public:
    void iniciar();
    void menuPrincipal();
    /*Voy a separar las cosas para no perderme*/
    void menuProductos();
    void agregarProducto();
    void modificarProducto();
    void eliminarProducto();
    void consultarProductos();
    void buscarProductoPorNombre();
    void filtrarPorCategoria();
    void filtrarPorRangoPrecio();
    void stockCritico();
    void productoMasCarosYMasBaratos();
    int buscarProductoPorId(int id);
//vamos a seguir por donde lo deje ayer
    void menuClientes();
    void agregarCliente();
    void modificarCliente();
    void eliminarCliente();
    void consultarClientes();
    void verHistorialCliente();
    void filtrarPorGasto();
    void filtrarPorCompras();
    double totalGastadoCliente(int pos);
    int buscarClientePorId(string id);

    void menuEmpleados();
    void agregarEmpleado();
    void modificarEmpleado();
    void eliminarEmpleado();
    void consultarEmpleados();
    void estadisticasEmpleados();
    int buscarEmpleadoPorId(string id);
    
    void menuVentas();
    void registrarVenta();
    void eliminarVenta();
    void consultarVentas();
    void filtrarVentasPorCliente();
    void filtrarVentasPorFecha();
    void estadisticasVentas();
    int buscarVentaPorId(int id);


    void menuReportes();
    void costoTotalInventario();
    void promedioVentasPorCliente();
    void promedioPrecioPorCategoria();
    void filtrarPorMargenGanancia();
    void productoMasCaroGeneral();
    void productoMasBaratoGeneral();

    void guardarDatos();
    void cargarDatos();
};
#endif