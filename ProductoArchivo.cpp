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

void ProductoArchivo::listarProductos() {
    Producto prod;
    FILE* archivo = fopen(_nombreArchivo.c_str(), "rb");

    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    while (fread(&prod, sizeof(Producto), 1, archivo) == 1) {
        cout << "------------------------------" << endl;
        cout << "Código: " << prod.getCodProducto() << endl;
        cout << "Nombre: " << prod.getNombreProducto() << endl;
        cout << "Tipo: " << prod.getTipoProducto() << endl;
        cout << "Marca: " << prod.getMarca() << endl;
        cout << "Unidad de medida: " << prod.getUnidadMedida() << endl;
        cout << "Precio unitario: $" << prod.getPrecioUnitario() << endl;
        cout << "Stock: " << prod.getStock() << endl;
    }

    fclose(archivo);
}



bool ProductoArchivo::guardarProducto(Producto registro) {
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == nullptr) {
        return false;
    }

    result = fwrite(&registro, sizeof(Producto), 1, pFile);

    fclose(pFile);
    return result;
}




int ProductoArchivo::getCantidadRegistros(){
    FILE *pFile;
    int tamReg, total, cantidad;

    tamReg = sizeof(Producto);

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile==nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    total = ftell(pFile);

    cantidad = total / tamReg ;

    fclose(pFile);

    return cantidad;
}
