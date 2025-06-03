#pragma once
#include "Producto.h"
#include <string>

class ProductoArchivo{
private:
    std::string _nombreArchivo;

public:
    ProductoArchivo();
    ProductoArchivo(std::string nombreArchivo);

    bool guardarProducto(Producto registro);
    void mostrarProductos();
    void listarProductos();
    int getCantidadRegistros();
    Producto leer(int pos);

};
