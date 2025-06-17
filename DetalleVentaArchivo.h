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

    bool guardar(DetalleVenta);
    bool guardar(DetalleVenta,int);
    int buscar(int);
    DetalleVenta leer(int pos);
    bool baja(int idVenta);
    int getCantidadRegistros();
};
