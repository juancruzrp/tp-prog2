#pragma once
#include "DetalleVenta.h"
#include "VentaArchivo.h"
#include <string>

class DetalleVentaArchivo{
private:
    std::string _nombreArchivo;

public:
    DetalleVentaArchivo();
    DetalleVentaArchivo(std::string nombreArchivo);

    bool guardar(DetalleVenta registro);
    DetalleVenta leer(int pos);
    bool eliminar(int idEliminar);
    int getCantidadRegistros();
    bool alta(int idEliminar);
};
