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
    Venta leer(int pos);
    int modificar(int idVenta);
    bool eliminar();
    int getCantidadRegistros();
};
