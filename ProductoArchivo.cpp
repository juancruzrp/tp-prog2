#include <iostream>
#include "Producto.h"
#include "ProductoArchivo.h"
using namespace std;


ProductoArchivo::ProductoArchivo(){
    _nombreArchivo = "productos.dat";
}

ProductoArchivo::ProductoArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ProductoArchivo::guardarProducto(Producto registro) {
    FILE *pFile;

    pFile = fopen(_nombreArchivo.c_str(), "ab"); // modo agregar binario

    if (pFile == nullptr) {
        return false;
    }

    fwrite(this, sizeof(Producto), 1, pFile); // guardamos el objeto actual
    fclose(pFile);
    return true;
}

void ProductoArchivo::mostrarProductos() {
    Producto reg;

    cout << "Codigo: " << reg.getCodProducto() << endl;
    cout << "Nombre: " << reg.getNombreProducto() << endl;
    cout << "Tipo: " << reg.getTipoProducto() << endl;
    cout << "Precio: $" << reg.getPrecioUnitario() << endl;
    cout << "Stock: " << reg.getStock() << endl;
}

void ProductoArchivo::listarProductos() {
    ProductoArchivo prodArch;
    FILE *archivo;

    archivo = fopen("productos.dat", "rb");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    while (fread(&prodArch, sizeof(Producto), 1, archivo)) {
        prodArch.mostrarProductos(); // Método de la clase Producto
        cout << "-----------------------------" << endl;
    }

    fclose(archivo);
}
