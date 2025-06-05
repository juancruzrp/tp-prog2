#pragma once
#include "DetalleVenta.h"
#include <string>

class DetalleVentaArchivo{
private:
    std::string _nombreArchivo;

public:
    DetalleVentaArchivo();
    DetalleVentaArchivo(std::string nombreArchivo);

    bool guardar();
    DetalleVenta leer();
    bool eliminar();
    int cantidadRegistros();
};
