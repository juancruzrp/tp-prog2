#include <iostream>
#include "Producto.h"
#include "FerreteriaManager.h"
using namespace std;


    /// PENSAR VALIDACIONES
void FerreteriaManager::cargarProducto(){
    int codProducto, stock;
    string nombreProducto, tipoProducto;
    float precioUnitario;
    Producto producto;

    cout << "Ingrese codigo del producto: " ;
    cin >> codProducto;

    cout << "Ingrese nombre del producto: " ;
    cin.ignore();
    getline(cin, nombreProducto);

    cout << "Ingrese tipo de producto: ";
    getline(cin, tipoProducto);

    cout << "Ingrese precio unitario: ";
    cin >> precioUnitario;

    cout << "Ingrese stock: ";
    cin >> stock;

    producto = Producto(codProducto, nombreProducto, tipoProducto, precioUnitario, stock);

   if (producto.guardarEnArchivo()) {
        cout << "Producto guardado correctamente.\n";
    } else {
        cout << "Error al guardar el producto.\n";
    }

}


FILE* archivo = fopen("productos.dat", "ab");





void FerreteriaManager::listarProductos() {
    Producto prod;
    FILE* archivo = fopen("productos.dat", "rb");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    while (fread(&prod, sizeof(Producto), 1, archivo)) {
        prod.mostrar(); // Método de la clase Producto
        cout << "-----------------------------\n";
    }

    fclose(archivo);
}

