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
    ProductoArchivo prodArch;

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

    producto = Producto(codProducto, nombreProducto, tipoProducto, marca, unidadMedida, precioUnitario, stock);

   if (prodArch.guardar()) {
        cout << "Producto guardado correctamente.\n";
    } else {
        cout << "Error al guardar el producto.\n";
    }

}


FILE* archivo = fopen("productos.dat", "ab");


void FerreteriaManager::listarProductos() {
    ProductoArchivo prodArch;
    FILE* archivo = fopen("productos.dat", "rb");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    while (fread(&prodArch, sizeof(Producto), 1, archivo)) {
        prodArch.mostrar(); // Método de la clase Producto
        cout << "-----------------------------\n";
    }

    fclose(archivo);
}

