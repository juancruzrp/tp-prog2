#pragma once
#include "Venta.h"
#include <string>

class VentaArchivo{
private:
    std::string _nombreArchivo;

public:
    VentaArchivo();
    VentaArchivo(std::string nombreArchivo);

    bool guardar(Venta);
    int buscar(int);
    Venta leer(Venta);
    bool eliminar();
    int getCantidadRegistros();
};
