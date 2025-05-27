#include <iostream>
#include "Producto.h"
#include "FerreteriaManager.h"
#include "ProductoArchivo.h"
using namespace std;


    /// PENSAR VALIDACIONES
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
        cout << "Hubo un error al cargar el producto.";
    }

}


/*void FerreteriaManager::mostrarProductos(){
    ProductoArchivo productoArchivo;

    productoArchivo.mostrarProductos();


}*/

void FerreteriaManager::mostrarCantidadProductos(){
    ProductoArchivo productoArchivo;
    int cant;

    cant = productoArchivo.cantidadProductosRegistrados();

    cout << "Cantidad de productos registrados: " << cant << endl;

}



