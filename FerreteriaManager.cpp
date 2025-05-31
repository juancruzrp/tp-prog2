#include <iostream>
#include "Producto.h"
#include "FerreteriaManager.h"
#include "ProductoArchivo.h"
using namespace std;



    /// PENSAR SI AGREGAR VALIDACIONES
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




void FerreteriaManager::mostrarCantidadProductos(){
    ProductoArchivo productoArchivo;
    int cant;

    cant = productoArchivo.getCantidadRegistros();

    cout << "Cantidad de productos registrados: " << cant << endl;
}


/*void FerreteriaManager::listarProductos() {
    Producto prod;
    FILE* archivo = fopen("productos.dat", "rb");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }


}
*/




/*void FerreteriaManager::buscarProductoPorCodigo() {
    int codigoBuscado;
    bool encontrado = false;

    cout << "Ingrese el codigo del producto a buscar: ";
    cin >> codigoBuscado;

    Producto prod;
    FILE* archivo = fopen("productos.dat", "rb");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    while (fread(&prod, sizeof(Producto), 1, archivo)) {
        if (prod.getCodProducto() == codigoBuscado) {
            cout << "Producto encontrado:\n";
            prod.mostrar();
            encontrado = true;
            break;  // cortamos la búsqueda porque ya lo encontramos
        }
    }

    fclose(archivo);

    if (!encontrado) {
        cout << "No se encontro ningun producto con ese codigo.\n";
    }
}
*/
