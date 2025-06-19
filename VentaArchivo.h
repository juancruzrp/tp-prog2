#pragma once
#include <string>
#include "Venta.h"

class VentaArchivo{
private:
    std::string _nombreArchivo;

public:
    VentaArchivo();
    VentaArchivo(std::string nombreArchivo);

    bool guardar(Venta);
    bool guardar(Venta registro,int posicion);
    int buscar(int idVenta);
    Venta leer(int pos);
    bool baja(int idVenta);
    int getCantidadRegistros();
};
