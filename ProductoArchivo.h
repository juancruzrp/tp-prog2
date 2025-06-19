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
    bool guardarProducto(Producto registro,int posicion);
    void mostrarProductos();
    void listarProductos();
    int getCantidadRegistros();
    Producto leer(int pos);
    int buscarProducto(int posicion);
    bool sumarStock(int codProducto, int cantidad);
};
