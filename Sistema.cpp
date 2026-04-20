#include "Sistema.h"
#include "Utils.h"
#include "DataManagerJson.h"
#include <iostream>
#include <limits> //Para poder agregar productos y eso usando los espacios, y que no haya 
//ningun problema con los cin y los getline
#include <algorithm>
#include <map> //para ventas y demas
using namespace std;

void Sistema::iniciar() {
    cargarDatos();
    menuPrincipal();
    guardarDatos();
}
void Sistema::guardarDatos() {
    DataManagerJson::guardarTodo(productos, clientes, empleados, ventas);
}
void Sistema::menuPrincipal() {
    int op;
    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1-Productos\n";
        cout << "2-Clientes\n";
        cout << "3-Empleados\n";
        cout << "4-Ventas\n";
        cout << "5-Reportes y estadisticas\n";
        cout << "6-Guardar y salir\n";
        cout << "Opcion: ";
        cin >> op;
        //Esto lo voy a hacer como si estuviera trabajando en batch pq me es mas comodo hacer
        //un menu asi
        switch (op) {
            case 1: menuProductos(); break;
            case 2: menuClientes(); break;
            case 3: menuEmpleados(); break;
            case 4: menuVentas(); break;
            case 5: menuReportes(); break;
            case 6: guardarDatos(); break;
            default: cout << "Opcion no valida (Elija una opcion del 1 al 6)\n";
        }
    } while (op != 6);
}
//Que locura estoy armando yo aqui...
int Sistema::buscarProductoPorId(int id){
    for(int i=0; i<productos.size(); i++){
        if(productos[i].getId() == id){
            return i;
        }
    }
    return -1;
}
void Sistema::menuProductos(){
    int op;
    do{
        cout << "\n===== PRODUCTOS =====\n";
        cout << "1-Agregar producto\n";
        cout << "2-Modificar producto\n";
        cout << "3-Eliminar producto\n";
        cout << "4-Consultar todos\n";
        cout << "5-Buscar por nombre\n";
        cout << "6-Filtrar por categoria\n";
        cout << "7-Filtrar por rango de precio\n";
        cout << "8-Stock critico\n";
        cout << "9-Mas caros y mas baratos\n";
        cout << "10-Volver\n";
        cout << "Opcion: ";
        cin >> op;

        switch(op){
            case 1: agregarProducto(); break;
            case 2: modificarProducto(); break;
            case 3: eliminarProducto(); break;
            case 4: consultarProductos(); break;
            case 5: buscarProductoPorNombre(); break;
            case 6: filtrarPorCategoria(); break;
            case 7: filtrarPorRangoPrecio(); break;
            case 8: stockCritico(); break;
            case 9: productoMasCarosYMasBaratos(); break;
            case 10: break;
            default: cout << "Opcion no valida (Ingrese una opcion del 1 al 10)\n";
        }
    } while(op !=10);
}
//AGREGAR PRODUCTO (Me estoy perdiendo ya)
void Sistema::agregarProducto(){
    int id, stock;
    string nombre, categoria;
    double precio, costo;
    cout << "ID: ";
    cin >> id;
    if(buscarProductoPorId(id) != -1){
        cout << "Ya existe un producto con esa ID.\n";
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); /*Para evitar lios con el
    getline pq la primera vez que introduzcas un producto no va a haber problema
    pero la segunda va a dar error lo digo por expriencia*/
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Categoria: ";
    getline(cin, categoria);
    cout << "Precio(en USD): ";
    cin >> precio;
    cout << "Stock: ";
    cin >> stock;
    cout << "Costo(en USD): ";
    cin >> costo;
    productos.push_back(Producto(id, nombre, categoria, precio, stock, costo));
    cout << "Producto agregado.\n";
}
//MODIFICARLO
void Sistema::modificarProducto() {
    int id;
    cout << "ID del producto que quieres modificar: ";
    cin >> id;
    int pos=buscarProductoPorId(id);
    if (pos == -1){
        cout<< "No se encontro ese producto.\n";
        return;
    }
    string nombre, categoria;
    double precio, costo;
    int stock;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nuevo nombre: ";
    getline(cin, nombre);
    cout << "Nueva categoria: ";
    getline(cin, categoria);
    cout << "Nuevo precio: ";
    cin >> precio;
    cout << "Nuevo stock: ";
    cin >> stock;
    cout << "Nuevo costo: ";
    cin >> costo;

    productos[pos].setNombre(nombre);
    productos[pos].setCategoria(categoria);
    productos[pos].setPrecio(precio);
    productos[pos].setStock(stock);
    productos[pos].setCosto(costo);
    cout << "Producto modificado con exito.\n";
}
//ELIMINARLO
void Sistema::eliminarProducto() {
    int id;
    cout << "ID del producto que deseas eliminar: ";
    cin >> id;
    int pos =buscarProductoPorId(id);
    if (pos== -1) {
        cout<< "No se encontro ese producto.\n";
        return;
    }
    productos.erase(productos.begin() + pos);
    cout << "Producto eliminado con exito.\n";
}
//MOSTRAR LOS PRODUCTOS DISPONIBLESSSSS
void Sistema::consultarProductos(){
    if(productos.empty()){
        cout << "No hay productos registrados.\n";
        return;
    }
    for(int i=0; i<productos.size(); i++){
        cout << "\n---* Producto numero " << i + 1 << " *---\n";
        productos[i].mostrar();
    }
}
//BUSQUEDA PARCIAL
void Sistema::buscarProductoPorNombre(){
    string texto;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Buscar: ";
    getline(cin, texto);
    bool encontrado = false;
    for(int i=0; i<productos.size(); i++){
        if(productos[i].getNombre().find(texto) != string::npos){
            cout << "\n";
            productos[i].mostrar();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontro ninguna coincidencia.\n";
    }
}
/*Cuando termine con los productos voy a dormir que llevo ya toda la tarde-noche en esto*/
//FILTRAR CATEGORIA
void Sistema::filtrarPorCategoria(){
    string categoria;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Categoria: ";
    getline(cin, categoria);
    bool encontrado=false;
    for(int i=0; i<productos.size(); i++){
        if(productos[i].getCategoria()==categoria){
            cout << "\n";
            productos[i].mostrar();
            encontrado=true;
        }
    }
    if (!encontrado) {
        cout << "No hay ningun producto en esa categoria.\n";
    }
}
//FILTRAR PRECIO
void Sistema::filtrarPorRangoPrecio(){
    double min, max;
    cout << "Precio minimo: ";
    cin >> min;
    cout << "Precio maximo: ";
    cin >> max;
    bool encontrado=false;
    for(int i=0; i<productos.size(); i++){
        if (productos[i].getPrecio() >= min && productos[i].getPrecio() <= max){
            cout << "\n";
            productos[i].mostrar();
            encontrado=true;
        }
    }
    if(!encontrado){
        cout << "No existen productos entre esos precios.\n";
    }
}
void Sistema::stockCritico() {
    int limite;
    cout << "Limite de stock critico: ";
    cin >> limite;
    bool encontrado=false;
    for(int i=0; i<productos.size(); i++){
        if(productos[i].getStock()<limite){
            cout << "\n";
            productos[i].mostrar();
            encontrado=true;
        }
    }
    if(!encontrado){
        cout<<"No hay productos con stock critico.\n"; //no existen como mis horas de sueño
    }
}
void Sistema::productoMasCarosYMasBaratos(){
    if(productos.empty()){
        cout << "No hay productos disponibles.\n";
        return;
    }
    int posCaro = 0;
    int posBarato = 0;
    for(int i=1; i <productos.size(); i++){
        if(productos[i].getPrecio() > productos[posCaro].getPrecio()){
            posCaro = i;
        }
        if(productos[i].getPrecio() < productos[posBarato].getPrecio()){
            posBarato=i;
        }
    }
    cout << "\nProducto mas caro:\n";
    productos[posCaro].mostrar();
    cout << "\nProducto mas barato:\n";
    productos[posBarato].mostrar();
}
//A dormir, mañana termino las otras
//vamo a seguir

int Sistema::buscarClientePorId(string id){ //Misma funcion que el de productos
    /*Pero creo que no lo explique*/
    for(int i=0; i<clientes.size(); i++){ //Busca entre los datos de los clientes
        if (clientes[i].getId()==id) return i; //cuendo encuentra la id la muestra
    }
    return -1; //para volver al menu anterior
}
void Sistema::menuClientes(){
    int op;
    do {
        cout << "\n===== CLIENTES =====\n";
        cout << "1-Agregar cliente\n";
        cout << "2-Modificar cliente\n";
        cout << "3-Eliminar cliente\n";
        cout << "4-Consultar datos de un cliente\n";
        cout << "5-Ver historial del cliente\n";
        cout << "6-Filtrar por gasto\n";
        cout << "7-Filtrar por compras\n";
        cout << "8-Volver al menu principal\n";
        cout << "Opcion: ";
        cin >> op;

        switch(op){
            case 1: agregarCliente(); break;
            case 2: modificarCliente(); break;
            case 3: eliminarCliente(); break;
            case 4: consultarClientes(); break;
            case 5: verHistorialCliente(); break;
            case 6: filtrarPorGasto(); break;
            case 7: filtrarPorCompras(); break;
            case 8: break;
            default: cout << "Opcion no valida (ingrese una opcion del 1 al 8)\n";
        }
    } while(op!=8);
}
void Sistema::agregarCliente(){
    string id, nombre, apellido, telefono, correo;
    cout << "ID: ";
    cin >> id;
    if(buscarClientePorId(id)!=-1){
        cout << "Ya existe un cliente con esa ID.\n";
        return;
    }
    cout << "Nombre(Solo 1 nombre sin apellidos): ";
    cin >> nombre;
    cout << "Apellido(Solo 1 apellido): ";
    cin >> apellido;
    cout << "Telefono: ";
    cin >> telefono;
    cout << "Correo: ";
    cin >> correo;
    clientes.push_back(Cliente(nombre, apellido, id, telefono, correo));
    cout << "Se ah agregado el cliente correctamente." << endl;
}
void Sistema::modificarCliente(){
    string id;
    cout << "ID del cliente: ";
    cin >> id;
    int pos=buscarClientePorId(id);
    if(pos == -1){
        cout << "No se ah encontrado ningun cliente con esa ID.\n";
        return;
    }
    string nombre, apellido, telefono, correo;
    cout << "Nuevo nombre: ";
    cin >> nombre;
    cout << "Nuevo apellido: ";
    cin >> apellido;
    cout << "Nuevo telefono: ";
    cin >> telefono;
    cout << "Nuevo correo: ";
    cin >> correo;
    clientes[pos].setNombre(nombre);
    clientes[pos].setApellido(apellido);
    clientes[pos].setTelefono(telefono);
    clientes[pos].setCorreo(correo);
    cout << "Se ah modificado correctamente el cliente con la siguiente id: " << id << endl;
}
void Sistema::eliminarCliente() {
    string id;
    cout << "ID cliente: ";
    cin >> id;
    int pos=buscarClientePorId(id);
    if(pos == -1){
        cout << "No se ah encontrado ningun cliente con esa ID.\n";
        return;
    }
    if(!clientes[pos].getHistorialCompras().empty()){
        cout << "No se puede eliminar este cliente porque tiene compras registradas.\n";
        return;
    }
    clientes.erase(clientes.begin() + pos);
    cout << "Se ah eliminado correctamente\n";
}
void Sistema::consultarClientes(){
    for(int i= 0; i<clientes.size(); i++){
        cout << "\n--- Cliente ---\n";
        clientes[i].mostrar();
    }
}
void Sistema::verHistorialCliente() {
    string id;
    cout << "ID del cliente: ";
    cin >> id;
    int pos = buscarClientePorId(id);
    if(pos == -1){
        cout << "No se ah encontrado ningun cliente con esa ID.\n";
        return;
    }
    clientes[pos].mostrarHistorial();
}
double Sistema::totalGastadoCliente(int pos){
    double total = 0;
    vector<Venta> hist = clientes[pos].getHistorialCompras();
    for(int i=0; i<hist.size(); i++){
        total += hist[i].getTotal();
    }
    return total;
}
void Sistema::filtrarPorGasto() {
    double min;
    cout << "Gasto minimo: ";
    cin >> min;
    for(int i=0; i<clientes.size(); i++){
        if(totalGastadoCliente(i)>=min){ 
            clientes[i].mostrar();
            cout << "Total gastado: " << totalGastadoCliente(i) << endl;
        }
    }
}
void Sistema::filtrarPorCompras() {
    int min;
    cout << "Minimo de compras: ";
    cin >> min;
    for(int i=0; i<clientes.size(); i++){
        if(clientes[i].getHistorialCompras().size() >= min){
            clientes[i].mostrar();
        }
    }
}
//Termine con los clientes

//Vamos para los empleados
int Sistema::buscarEmpleadoPorId(string id){
    for(int i=0; i<empleados.size(); i++){
        if(empleados[i].getId() == id) return i;
    }
    return -1;
}
void Sistema::menuEmpleados(){
    int op;
    do{
        cout << "\n===== EMPLEADOS =====\n";
        cout << "1-Agregar\n";
        cout << "2-Modificar\n";
        cout << "3-Eliminar\n";
        cout << "4-Consultar\n";
        cout << "5-Estadisticas\n";
        cout << "6-Volver\n";
        cout << "Opcion: ";
        cin >> op;
        switch(op){
            case 1: agregarEmpleado(); break;
            case 2: modificarEmpleado(); break;
            case 3: eliminarEmpleado(); break;
            case 4: consultarEmpleados(); break;
            case 5: estadisticasEmpleados(); break;
            case 6: break;
            default: cout << "Opcion no valida (ingrese una opcion del 1 al 6)\n";
        }
    } while(op != 6);
}
void Sistema::agregarEmpleado(){
    string id, nombre, apellido, telefono, cargo;
    double salario;
    cout << "ID del Empleado nuevo: ";
    cin >> id;
    if(buscarEmpleadoPorId(id) != -1){
        cout << "Ya existe un empleado con esa ID.\n";
        return;
    }
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Apellido: ";
    cin >> apellido;
    cout << "Telefono: ";
    cin >> telefono;
    cout << "Cargo: ";
    cin >> cargo;
    cout << "Salario: ";
    cin >> salario;
    empleados.push_back(Empleado(nombre, apellido, id, telefono, cargo, salario));
    cout << "Se agrego correctamente :)\n";
}
void Sistema::modificarEmpleado(){
    string id;
    cout << "ID del empleado a modificar: ";
    cin >> id;
    int pos=buscarEmpleadoPorId(id);
    if(pos == -1){
        cout << "No se encontro ningun empleado con esa ID.\n";
        return;
    }
    string nombre, apellido, telefono, cargo; /*Se que en los clientes tambien lo hice y probablemente
    en los productos tambien, si se preguntan pq no uso un }else{ es pq si se dan cuenta dentro del if
    hay un return que si encuentra algo pues nunca va a llegar al codigo de aqui abajo*/
    double salario;
    cout << "Nuevo nombre: ";
    cin >> nombre;
    cout << "Nuevo apellido: ";
    cin >> apellido;
    cout << "Nuevo telefono: ";
    cin >> telefono;
    cout << "Nuevo cargo: ";
    cin >> cargo;
    cout << "Nuevo salario: ";
    cin >> salario;
    empleados[pos].setNombre(nombre);
    empleados[pos].setApellido(apellido);
    empleados[pos].setTelefono(telefono);
    empleados[pos].setCargo(cargo);
    empleados[pos].setSalario(salario);
    cout << "Empleado modificado correctamente.\n";
}
void Sistema::eliminarEmpleado(){
    string id;
    cout << "ID del empleado que deseas eliminar: ";
    cin >> id;
    int pos=buscarEmpleadoPorId(id);
    if(pos== -1){
        cout << "Empleado no encontrado.\n";
        return;
    }
    empleados.erase(empleados.begin() + pos);
    cout << "Empleado eliminado correctamente.\n";
}
void Sistema::consultarEmpleados(){
    if(empleados.empty()){
        cout << "No hay empleados registrados :( \n";
        return;
    }
    for(int i=0; i<empleados.size(); i++){
        cout << "\n--- Empleado " << i + 1 << " ---\n";
        empleados[i].mostrar();
    }
}
void Sistema::estadisticasEmpleados(){
    if (empleados.empty()) {
        cout << "No hay empleados! \n";
        return;
    }
    double suma=0;
    int posMayor=0;
    map<string, int> conteoCargo;
    for(int i=0; i<empleados.size(); i++){
        suma += empleados[i].getSalario();
        conteoCargo[empleados[i].getCargo()]++;
        if(empleados[i].getSalario()>empleados[posMayor].getSalario()){
            posMayor=i;
        }
    }
    cout << "Salario promedio de los empleados: " << (suma / empleados.size()) << endl;
    cout << "Empleado con mayor salario:\n";
    empleados[posMayor].mostrar();
    cout << "\nConteo por cargo:\n";
    /*Lo siguiente esta un poco enredado pq hasta yo pase trabajo para hacerlo
    primero si se dan cuenta arriba se creo una variable string e int con el mismo nombre en un map
    esto va a servir para ubicar todo en un mismo lugar*/
    /*El codigo que esta justo aqui abajo hasta
                                    v aqui lo que va a hacer es declarar a it como si fuese i*/
    for (map<string, int>::iterator it=conteoCargo.begin(); it != conteoCargo.end(); ++it){
        //si se les pregunta pq es tipo map pues pq estas trabajando con 2 datos dentro
        //la string y el int de conteoCargo    conteoCargo.begin marca que el primer cargo tipo
        //string es el numero 1, y sucesivamente hasta que it sea diferente de conteoCargo.end que vendria siendo el ultimo dato dentro del map
        cout << it->first << ": " << it->second << endl; //y esto no es nada del otro mundo, it first
        //es la primera variable, la string y second la int
    }
}

int Sistema::buscarVentaPorId(int id){
    for(int i=0; i<ventas.size(); i++){
        if(ventas[i].getId()==id) return i;
    }
    return -1;
}
void Sistema::menuVentas(){
    int op;
    do{
        cout << "\n===== VENTAS =====\n";
        cout << "1-Registrar venta\n";
        cout << "2-Eliminar venta\n";
        cout << "3-Consultar ventas\n";
        cout << "4-Filtrar por cliente\n";
        cout << "5-Filtrar por rango de fechas\n";
        cout << "6-Estadisticas\n";
        cout << "7-Volver\n";
        cout << "Opcion: ";
        cin >> op;
        switch(op){
            case 1: registrarVenta(); break;
            case 2: eliminarVenta(); break;
            case 3: consultarVentas(); break;
            case 4: filtrarVentasPorCliente(); break;
            case 5: filtrarVentasPorFecha(); break;
            case 6: estadisticasVentas(); break;
            case 7: break;
            default: cout << "Opcion no valida (ingrese una opcion del 1 al 7).\n";
        }
    } while(op != 7);
}
void Sistema::registrarVenta(){
    int idVenta;
    string idCliente, fecha;
    cout << "ID de la venta: ";
    cin >> idVenta;
    if(buscarVentaPorId(idVenta) != -1){
        cout << "Ya existe una venta con esa ID.\n";
        return;
    }
    cout << "ID del cliente: ";
    cin >> idCliente;
    int posCliente=buscarClientePorId(idCliente);
    if(posCliente == -1){
        cout << "No se encontro ningun cliente con esa ID.\n";
        return;
    }
    cout << "Fecha (DD-MM-YYYY): ";
    cin >> fecha;
    Venta venta(idVenta, idCliente, clientes[posCliente].getNombre() + " " + clientes[posCliente].getApellido(), fecha);
    int idProducto;
    while(true){
        cout << "ID del producto a agregar (0 para terminar): ";
        cin >> idProducto;
        if(idProducto==0) break;
        int posProducto=buscarProductoPorId(idProducto);
        if(posProducto == -1){
            cout << "No se encontro ese producto.\n";
            continue;
        }
        if(productos[posProducto].getStock() <= 0){
            cout << "No hay stock suficiente.\n";
            continue;
        }
        venta.agregarProducto(productos[posProducto]);
    }
    if(venta.getProductos().empty()){
        cout << "La venta actual no tiene productos, ah sido cancelada.\n";
        return;
    }
    for(int i=0; i<venta.getProductos().size(); i++){
        int idProd=venta.getProductos()[i].getId();
        int posProd=buscarProductoPorId(idProd);
        if(posProd != -1){
            productos[posProd].actualizarStock(-1);
        }
    }
    venta.calcularTotal();
    ventas.push_back(venta);
    clientes[posCliente].agregarCompra(venta);
    cout << "Venta registrada correctamente :D \n";
}
void Sistema::eliminarVenta() {
    int id;
    cout << "ID de la venta que deseas eliminar: ";
    cin >> id;
    int posVenta=buscarVentaPorId(id);
    if(posVenta == -1){
        cout << "No se ah encontrado ninguna venta.\n";
        return;
    }
    Venta venta = ventas[posVenta];
    for(int i=0; i<venta.getProductos().size(); i++){
        int idProd=venta.getProductos()[i].getId();
        int posProd=buscarProductoPorId(idProd);
        if(posProd != -1){
            productos[posProd].actualizarStock(1);
        }
    }
    string idCliente=venta.getIdCliente();
    int posCliente=buscarClientePorId(idCliente);
    if(posCliente != -1){
        vector<Venta> historial = clientes[posCliente].getHistorialCompras();
        vector<Venta> nuevoHistorial;
        for(int i=0; i<historial.size(); i++){
            if(historial[i].getId() != id){
                nuevoHistorial.push_back(historial[i]);
            }
        }
        clientes[posCliente] = Cliente(
            clientes[posCliente].getNombre(),
            clientes[posCliente].getApellido(),
            clientes[posCliente].getId(),
            clientes[posCliente].getTelefono(),
            clientes[posCliente].getCorreo()
        );
        for(int i=0; i<nuevoHistorial.size(); i++){
            clientes[posCliente].agregarCompra(nuevoHistorial[i]);
        }
    }
    ventas.erase(ventas.begin() + posVenta);
    cout << "Venta eliminada y stock restaurado.\n";
}
void Sistema::consultarVentas(){
    if(ventas.empty()){
        cout << "No hay ventas.\n";
        return;
    }
    for(int i=0; i<ventas.size(); i++){
        cout << "\n--- Venta " << i + 1 << " ---\n";
        ventas[i].mostrarResumen();
    }
}
void Sistema::filtrarVentasPorCliente(){
    string idCliente;
    cout << "ID del cliente: ";
    cin >>idCliente;
    bool encontrado=false;
    for(int i=0; i<ventas.size(); i++){
        if(ventas[i].getIdCliente()==idCliente){
            ventas[i].mostrarResumen();
            cout << "----------------------\n";
            encontrado=true;
        }
    }
    if(!encontrado){
        cout << "Ese cliente no ah hecho ninguna compra" << endl;
    }
}
void Sistema::filtrarVentasPorFecha(){
    string desde, hasta;
    cout << "Fecha Desde (DD-MM-YYYY): ";
    cin >> desde;
    cout << "Fecha hasta (DD-MM-YYYY): ";
    cin >> hasta;
    bool encontrado=false;
    for(int i=0; i<ventas.size(); i++){
        if (ventas[i].getFecha() >= desde && ventas[i].getFecha() <= hasta){
            ventas[i].mostrarResumen();
            cout << "----------------------\n";
            encontrado=true;
        }
    }
    if(!encontrado){
        cout << "No se encontro ninguna venta en esos anyios.\n";
    }
}
void Sistema::estadisticasVentas(){
    if (ventas.empty()) {
        cout << "No se han hecho ventas aun.\n";
        return;
    }
    map<string, double> totalPorCategoria;
    map<int, int> vecesVendidosPorProducto;
    map<string, int> comprasPorCliente;
    for(int i=0; i<ventas.size(); i++){
        comprasPorCliente[ventas[i].getIdCliente()]++;
        vector<Producto> prods = ventas[i].getProductos();
        for(int j=0; j<prods.size(); j++){
            totalPorCategoria[prods[j].getCategoria()] += prods[j].getPrecio();
            vecesVendidosPorProducto[prods[j].getId()]++;
        }
    }
///AAAAAAAAAAAAAAAAAAAAAH 
    cout << "\n===== Total de Ventas por categoria =====\n";
    for(map<string, double>::iterator it=totalPorCategoria.begin(); it != totalPorCategoria.end(); ++it){
        cout << it->first << ": " << it->second << endl;
    }
    int idMasVendido = -1;
    int maxVeces = -1; //se inicializa en -1 para poder registrar los productos sin ventas
    for(map<int, int>::iterator it=vecesVendidosPorProducto.begin(); it != vecesVendidosPorProducto.end(); ++it){
        if(it->second > maxVeces){
            maxVeces=it->second;
            idMasVendido=it->first;
        }
    }
    if(idMasVendido != -1){
        int pos=buscarProductoPorId(idMasVendido);
        cout << "\nProducto mas vendido: " <<productos[pos].getNombre()<< " (" <<maxVeces<< " veces)\n";
    }
//Se me acaba de joder el disco duro extraible... manda... mrd
    string idClienteTop = "";
    int maxCompras = -1;
    for(map<string, int>::iterator it = comprasPorCliente.begin(); it != comprasPorCliente.end(); ++it){
        if(it->second>maxCompras){
            maxCompras=it->second;
            idClienteTop=it->first;
        }
    }
    if(idClienteTop != ""){
        int posCliente=buscarClientePorId(idClienteTop);
        cout << "Cliente con mas compras: "
             << clientes[posCliente].getNombre() << " "
             << clientes[posCliente].getApellido()
             << " (" << maxCompras << " compras)\n";
    }
}

void Sistema::menuReportes(){
    int op;
    do {
        cout << "\n===== REPORTES =====\n";
        cout << "1-Costo total del inventario\n";
        cout << "2-Promedio de las ventas por cliente\n";
        cout << "3-Promedio del precio por categoria\n";
        cout << "4-Filtrar productos por margen de ganancia\n";
        cout << "5-Producto mas caro\n";
        cout << "6-Producto mas barato\n";
        cout << "7-Volver\n";
        cout << "Opcion: ";
        cin >> op;
        switch(op){
            case 1: costoTotalInventario(); break;
            case 2: promedioVentasPorCliente(); break;
            case 3: promedioPrecioPorCategoria(); break;
            case 4: filtrarPorMargenGanancia(); break;
            case 5: productoMasCaroGeneral(); break;
            case 6: productoMasBaratoGeneral(); break;
            case 7: break;
            default: cout << "Opcion no valida (ingrese una opcion del 1 al 7)" << endl;
        }
    } while(op != 7);
}
void Sistema::costoTotalInventario(){
    double total = 0;
    for(int i=0; i<productos.size(); i++){
        total += productos[i].getStock() * productos[i].getPrecio();
    }
    cout << "Costo total: " << total << endl;
}
void Sistema::promedioVentasPorCliente(){
    if(clientes.empty()){
        cout << "No hay clientes aun.\n";
        return;
    }
    double suma=0;
    for(int i=0; i<clientes.size(); i++){
        suma += totalGastadoCliente(i);
    }
    cout << "Promedio de las ventas(Por cliente): " << (suma / clientes.size()) << endl;
}
void Sistema::promedioPrecioPorCategoria(){
    if(productos.empty()){
        cout << "No hay productos.\n";
        return;
    }
    map<string, double> sumaPorCategoria;
    map<string, int> conteoPorCategoria;
    for(int i=0; i<productos.size(); i++){
        string cat=productos[i].getCategoria();
        sumaPorCategoria[cat] += productos[i].getPrecio();
        conteoPorCategoria[cat]++;
    }
    cout << "\n===== Precio promedio x categoria =====\n";
    for(map<string, double>::iterator it =sumaPorCategoria.begin(); it != sumaPorCategoria.end(); ++it){
        string cat=it->first;
        double promedio= it->second / conteoPorCategoria[cat];
        cout << cat << ": " << promedio << endl;
    }
}
void Sistema::filtrarPorMargenGanancia(){
    if(productos.empty()){
        cout << "No hay productos.\n";
        return;
    }
    double minimo;
    cout << "Margen minimo(precio): ";
    cin >> minimo;
    bool encontrado=false;
    for(int i=0; i<productos.size(); i++){
        double margen=productos[i].getPrecio() - productos[i].getCosto();
        if(margen >= minimo){
            productos[i].mostrar();
            cout << "Margen de ganancia: " << margen << endl;
            cout << "----------------------\n";
            encontrado=true;
        }
    }
    if(!encontrado){
        cout << "No hay productos con ese margen de precio.\n";
    }
}
void Sistema::productoMasCaroGeneral(){
    if(productos.empty()){
        cout << "No hay productos.\n";
        return;
    }
    int pos=0;
    for(int i=1; i<productos.size(); i++){
        if(productos[i].getPrecio() > productos[pos].getPrecio()){
            pos=i;
        }
    }
    cout << "\nProducto mas caro:\n";
    productos[pos].mostrar();
}
void Sistema::productoMasBaratoGeneral(){
    if(productos.empty()){
        cout << "No hay productos.\n";
        return;
    }
    int pos=0;
    for(int i=1; i<productos.size(); i++){
        if(productos[i].getPrecio() < productos[pos].getPrecio()){
            pos=i;
        }
    }
    cout << "\nProducto mas barato:\n";
    productos[pos].mostrar();
}
//TERMINEEEEEEEEEEEEEEEEEEEEEEEEEEEE plp casi 1000 lineas
//Por celebrar antes de tiempo me pasa
void Sistema::cargarDatos(){
    DataManagerJson::cargarTodo(productos, clientes, empleados, ventas);
    for(int i=0; i<clientes.size(); i++){
    clientes[i] = Cliente(
        clientes[i].getNombre(),
        clientes[i].getApellido(),
        clientes[i].getId(),
        clientes[i].getTelefono(),
        clientes[i].getCorreo()
    );
}
for(int i=0; i<ventas.size(); i++){
    for (int j=0; j<clientes.size(); j++){
        if (ventas[i].getIdCliente()==clientes[j].getId()){
            clientes[j].agregarCompra(ventas[i]);
        }
    }
}
}
//Ahora si termine