#ifndef DATAMANAGERJSON_H
#define DATAMANAGERJSON_H
#include <vector>
#include <string>
#include "Producto.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Venta.h"
using namespace std;

/*Para explicar, en la otra lo habia echo para guardar las cosas x separado
pero ejemh habia un error en lo que hice del que me di cuenta cuando termine
pq soy imbecil. En fin para resumir que guardabas una cosa y se borraban las demas*/
/*Ahora lo voy a hacer para guardar todo de una*/
class DataManagerJson {
public:
    static string leerArchivo();
    static void guardarArchivo(const string& contenido);
    static void cargarTodo(vector<Producto>& productos,
                           vector<Cliente>& clientes,
                           vector<Empleado>& empleados,
                           vector<Venta>& ventas);
    static void guardarTodo(const vector<Producto>& productos,
                            const vector<Cliente>& clientes,
                            const vector<Empleado>& empleados,
                            const vector<Venta>& ventas);
};
#endif