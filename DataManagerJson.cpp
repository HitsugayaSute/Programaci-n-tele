#include "DataManagerJson.h"
#include "Utils.h"
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

static const string FILE_NAME = "Administrador de datos.json";
string DataManagerJson::leerArchivo() { /*Esto ya lo explique en el otro*/
    ifstream file(FILE_NAME.c_str());
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
void DataManagerJson::guardarArchivo(const string& contenido) { /*Al igual que esto*/
    ofstream file(FILE_NAME.c_str());
    file << contenido;
}
/*Ahora empiezan los cambios, este de aca va a servir para guardar todos los datos*/
void DataManagerJson::guardarTodo(const vector<Producto>& productos,
                                  const vector<Cliente>& clientes,
                                  const vector<Empleado>& empleados,
                                  const vector<Venta>& ventas) {
    string json="{\n"; /*Procedo a explicar lo que pienso hacer y para que funciona*/
    json +="  \"productos\": ["; /*Como yo explico esto, bueno esto basicamente va a ser generar la
    estructura de los datos 1 por 1 dentro de la libreria*/
    for(size_t i=0; i< productos.size(); i++) {
        json += productos[i].toJSON();
        if(i + 1 < productos.size()) json += ","; /*Esto separa los datos*/
    }
    json +="],\n";/*Esto va a separar los datos anteriores, osea va a indicar donde es que terminan*/
    json +="  \"clientes\": ["; /*Y este va a ser el inicializador, lo que va a indicar donde empiezan
    los datos de los clientes*/
    for(size_t i=0; i<clientes.size(); i++) { /*Por si el profe les pregunta para que sirve esto
    es basicamente como un delimitador, va a ir separando los datos de 1 en 1 hasta que i sea igual que
    la cantidad de los clientes, asi no se ingresan datos de mas*/
        json += clientes[i].toJSON(); //Este va a importar el dato que esta en la posicion de i a la libreria
        if(i + 1 < clientes.size()) json +=","; // Y este va a aumentar la posicion y separar los datos
    }
    json +="],\n"; //De aqui para abajo es lo mismo todo el rato
    json +="  \"empleados\": [";
    for(size_t i=0; i< empleados.size(); i++){
        json += empleados[i].toJSON();
        if (i + 1 < empleados.size()) json +=",";
    }
    json += "],\n";
    json +="  \"ventas\": [";
    for(size_t i = 0; i < ventas.size(); i++){
        json += ventas[i].toJSON();
        if(i + 1 < ventas.size()) json += ",";
    }
    json += "]\n";
    json += "}\n";
    guardarArchivo(json);
}
void DataManagerJson::cargarTodo(vector<Producto>& productos, vector<Cliente>& clientes, vector<Empleado>& empleados, vector<Venta>& ventas){
    string json=leerArchivo();
    productos.clear();
    clientes.clear();
    empleados.clear();
    ventas.clear();
    vector<string> p=splitObjetos(extraerSeccion(json, "productos"));
    vector<string> c=splitObjetos(extraerSeccion(json, "clientes"));
    vector<string> e=splitObjetos(extraerSeccion(json, "empleados"));
    vector<string> v=splitObjetos(extraerSeccion(json, "ventas"));
    for(int i=0; i<p.size(); i++) productos.push_back(Producto::fromJSON(p[i]));
    for(int i=0; i<c.size(); i++) clientes.push_back(Cliente::fromJSON(c[i]));
    for(int i=0; i<e.size(); i++) empleados.push_back(Empleado::fromJSON(e[i]));
    for(int i=0; i<v.size(); i++) ventas.push_back(Venta::fromJSON(v[i]));
}
//Termine con esto tambien