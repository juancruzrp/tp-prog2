#include <iostream>
#include "Producto.h"
#include "ProductoArchivo.h"
using namespace std;


bool ProductoArchivo::guardar() {
    FILE* archivo = fopen("productos.dat", "ab"); // modo agregar binario
    if (archivo == NULL) return false;

    fwrite(this, sizeof(Producto), 1, archivo); // guardamos el objeto actual
    fclose(archivo);
    return true;
}

void ProductoArchivo::mostrar() {
    Producto reg;

    cout << "Codigo: " << reg.getCodProducto() << endl;
    cout << "Nombre: " << reg.getNombreProducto() << endl;
    cout << "Tipo: " << reg.getTipoProducto() << endl;
    cout << "Precio: $" << reg.getPrecioUnitario() << endl;
    cout << "Stock: " << reg.getStock() << endl;
}
