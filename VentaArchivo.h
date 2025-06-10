#pragma once
#include "Venta.h"
#include <string>

class VentaArchivo{
private:

public:
    bool guardar(Venta);
    int buscar(int);
    Venta leer(Venta);
    bool eliminar();
    int getCantidadRegistros();
};
