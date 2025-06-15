#pragma once
#include "Proveedor.h"
#include <string>

class ProveedorArchivo{
private:
    std::string _nombreArchivo;

public:
    ProveedorArchivo();
    ProveedorArchivo(std::string nombreArchivo);

    bool guardarProveedor(Proveedor registro);
    bool guardarProveedor(Proveedor registro,int posicion);
    void mostrarProveedores();
    void listarProveedores();
    int getCantidadRegistros();
    Proveedor leer(int pos);
    int buscarProveedor(int pos);
};

