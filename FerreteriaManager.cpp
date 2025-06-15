#include <iostream>
#include "FerreteriaManager.h"
#include "Producto.h"
#include "ProductoArchivo.h"
#include "Proveedor.h"
#include "ProveedorArchivo.h"
using namespace std;



    /// PENSAR SI AGREGAR VALIDACIONES
                                         ///FUNCIONES PARA PRODUCTOS///
void FerreteriaManager::cargarProducto(){
    int codProducto, stock;
    string nombreProducto, tipoProducto, marca, unidadMedida;
    float precioUnitario;
    Producto producto;
    ProductoArchivo productoArchivo;


    cout << "Ingrese codigo del producto: " ;
    cin >> codProducto;

    cout << "Ingrese nombre del producto: " ;
    cin.ignore();
    getline(cin, nombreProducto);

    cout << "Ingrese tipo de producto: ";
    getline(cin, tipoProducto);

    cout << "Ingrese marca del producto: ";
    getline(cin, marca);

    cout << "Ingrese unidad de medida del producto: ";
    getline(cin, unidadMedida);

    cout << "Ingrese precio unitario: ";
    cin >> precioUnitario;

    cout << "Ingrese stock: ";
    cin >> stock;

    producto = Producto(codProducto, nombreProducto, tipoProducto, marca, unidadMedida, precioUnitario, stock);



    if (productoArchivo.guardarProducto(producto)){
        cout << "Se guardo correctamente";
    }
    else {
        cout << "Hubo un error al cargar el producto.";}

    /*if (producto.guardarEnArchivo()) {
        cout << "Producto guardado correctamente.\n";
    } else {
        cout << "Error al guardar el producto.\n";

    }
*/
}




void FerreteriaManager::listarCantidadProductos(){
    ProductoArchivo productoArchivo;
    int cantidadProductos;

    cantidadProductos = productoArchivo.getCantidadRegistros();

    cout << "Cantidad de productos registrados: " << cantidadProductos << endl;
}


void FerreteriaManager::listarProductos() {
    ProductoArchivo productoArchivo;
    Producto registro;
    int cantidadProductos =productoArchivo.getCantidadRegistros();

    for(int i=0 ; i<cantidadProductos ; i++ ){

        registro = productoArchivo.leer(i);
        cout<< registro.toCSV() << endl;
    }


    FILE* archivo = fopen("productos.dat", "rb");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }


}





void FerreteriaManager::buscarProductoPorCodigo() {
    ProductoArchivo productoArchivo;
    Producto registro;
    int buscarCodigo;
    int cantidadProductos = productoArchivo.getCantidadRegistros();

    cout<<"Ingrese el codigo de producto que desea buscar:";
    cin >> buscarCodigo;

    for(int i=0; i<cantidadProductos ; i++){

        registro = productoArchivo.leer(i);
        if(registro.getCodProducto()== buscarCodigo){

        cout <<"Nombre del producto: " << registro.getNombreProducto() << endl;
        cout <<"Tipo de producto: " << registro.getTipoProducto() << endl;
        cout <<"Marca del producto: " << registro.getMarca() << endl;
    }

}
return;
}

void FerreteriaManager::buscarProductoPorNombre(){
    ProductoArchivo productoArchivo;
    Producto registro;
    std::string buscarNombre;
    int cantidadProductos = productoArchivo.getCantidadRegistros();

    cout<<"Ingrese el nombre de producto que desea buscar:";
    cin >> buscarNombre;

    for(int i=0; i<cantidadProductos ; i++){

        registro = productoArchivo.leer(i);
        if(registro.getNombreProducto()== buscarNombre){

        cout <<"codigo del producto: " << registro.getCodProducto() << endl;
        cout <<"Tipo de producto: " << registro.getTipoProducto() << endl;
        cout <<"Marca del producto: " << registro.getMarca() << endl;
    }

}
return;
}

void FerreteriaManager::buscarProductoPorTipo(){
    ProductoArchivo productoArchivo;
    Producto registro;
    std::string buscarTipo;
    int cantidadProductos = productoArchivo.getCantidadRegistros();

    cout<<"Ingrese el nombre de producto que desea buscar: ";
    cin >> buscarTipo;

    for(int i=0; i<cantidadProductos ; i++){

        registro = productoArchivo.leer(i);
        if(registro.getTipoProducto()== buscarTipo){

        cout <<"codigo del producto: " << registro.getCodProducto() << endl;
        cout <<"Nombre de producto: " << registro.getNombreProducto() << endl;
        cout <<"Marca del producto: " << registro.getMarca() << endl;
    }

}
return;
}
void FerreteriaManager::modificarPrecioProducto(){
    int idProducto,posicion;
    float nuevoPrecio;
    cout<< "Ingrese el id del producto a modificar:";
    cin >> idProducto;

    ProductoArchivo archivo;
    posicion = archivo.buscarProducto(idProducto);

    if(posicion >=0){
        Producto registro = archivo.leer(posicion);
        cout <<"Precio unitario actual:"<<registro.getPrecioUnitario()<<endl;
        cout<<"Ingrese el nuevo precio unitario:";
        cin >> nuevoPrecio;
        registro.setPrecioUnitario(nuevoPrecio);
        if(archivo.guardarProducto(registro, posicion)){
            cout<<"Registro modificado con exito."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro."<<endl;
        }
    }
    else{
        cout<<"No existe el id del producto."<<endl;
    }

}

                                         ///FUNCIONES PARA PROVEEDORES///
void FerreteriaManager::cargarProveedor(){
    int idProveedor;
    string nombreProveedor, telefono, mail, direccion;
    Proveedor proveedor;
    ProveedorArchivo proveedorArchivo;

    cout << "Ingrese codigo del proveedor: " ;
    cin >> idProveedor;

    cout << "Ingrese nombre del proveedor: " ;
    cin.ignore();
    getline(cin, nombreProveedor);

    cout << "Ingrese un telefono de contacto: ";
    getline(cin, telefono);

    cout << "Ingrese un mail: ";
    getline(cin, mail);

    cout << "Ingrese la direccion del proveedor: ";
    getline(cin, direccion);

  proveedor = Proveedor( idProveedor, nombreProveedor, telefono, mail, direccion);

  if (proveedorArchivo.guardarProveedor(proveedor)){
        cout << "Se guardo correctamente";
    }
    else {
        cout << "Hubo un error al cargar el proveedor.";}
}

void FerreteriaManager::listarCantidadProveedores(){
    ProveedorArchivo proveedorArchivo;
    int cantidadProveedores;

    cantidadProveedores = proveedorArchivo.getCantidadRegistros();

    cout << "Cantidad de proveedores registrados: " << cantidadProveedores << endl;

}



void FerreteriaManager::listarProveedores() {
    ProveedorArchivo proveedorArchivo;
    Proveedor registro;
    int cantidadProveedores =proveedorArchivo.getCantidadRegistros();

    for(int i=0 ; i<cantidadProveedores ; i++ ){

        registro = proveedorArchivo.leer(i);
        cout<< registro.toCSV() << endl;
    }


    FILE* archivo = fopen("proveedores.dat", "rb");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }


}

void FerreteriaManager::buscarProveedorPorID() {
    ProveedorArchivo proveedorArchivo;
    Proveedor registro;
    int buscarCodigo;
    int cantidadProveedores = proveedorArchivo.getCantidadRegistros();

    cout<<"Ingrese el codigo del proveedor que desea buscar:";
    cin >> buscarCodigo;

    for(int i=0; i<cantidadProveedores ; i++){

        registro = proveedorArchivo.leer(i);
        if(registro.getIdProveedor()== buscarCodigo){

        cout <<"Nombre del proveedor: " << registro.getNombreProveedor() << endl;
        cout <<"Tel de contacto: " << registro.getTelefono() << endl;
        cout <<"Direccion del proveedor: " << registro.getDireccion()<< endl;
    }

}
return;
}

void FerreteriaManager::buscarProveedorPorNombre(){
    ProveedorArchivo proveedorArchivo;
    Proveedor registro;
    std::string buscarNombre;
    int cantidadProveedores =  proveedorArchivo.getCantidadRegistros();

    cout<<"Ingrese el nombre del proveedor que desea buscar:";
    cin >> buscarNombre;

    for(int i=0; i<cantidadProveedores ; i++){

        registro = proveedorArchivo.leer(i);
        if(registro.getNombreProveedor()== buscarNombre){

        cout <<"codigo del proveedor: " << registro.getIdProveedor() << endl;
        cout <<"Tel de contacto: " << registro.getTelefono() << endl;
        cout <<"Direccion del proveedor: " << registro.getDireccion() << endl;
    }

}
return;
}

void FerreteriaManager::modificarTelefonoProveedor(){
    int idProveedor,posicion;
    string nuevoTelefono;
    cout<< "Ingresar el id del proveedor a modificar:";
    cin >> idProveedor;

    ProveedorArchivo archivo;
    posicion = archivo.buscarProveedor(idProveedor);

    if(posicion >=0){
        Proveedor registro = archivo.leer(posicion);
        cout<<"Ingrese el nuevo numero de telefono:";
        cin >> nuevoTelefono;
        registro.setTelefono(nuevoTelefono);
        if(archivo.guardarProveedor(registro, posicion)){
            cout<<"Registro modificado con exito."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro."<<endl;
        }
    }
    else{
        cout<<"No existe el id del proveedor."<<endl;
    }

}
void FerreteriaManager::modificarDireccionProveedor(){
    int idProveedor,posicion;
    string nuevaDireccion;
    cout<< "Ingresar el id del proveedor a modificar:";
    cin >> idProveedor;

    ProveedorArchivo archivo;
    posicion = archivo.buscarProveedor(idProveedor);

    if(posicion >=0){
        Proveedor registro = archivo.leer(posicion);
        cout<<"Ingrese la nueva direccion del proveedor:";
        cin.ignore();
        getline(cin,nuevaDireccion);
        registro.setDireccion(nuevaDireccion);
        if(archivo.guardarProveedor(registro, posicion)){
            cout<<"Registro modificado con exito."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro."<<endl;
        }
    }
    else{
        cout<<"No existe el id del proveedor."<<endl;
    }

}
