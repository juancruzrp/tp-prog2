#pragma once
#include <iostream>
#include <fstream>
#include "DetalleCompra.h"


class DetalleCompraArchivo{
private:
    std::string _nombreArchivo;

public:
    DetalleCompraArchivo();
    DetalleCompraArchivo(std::string nombreArchivo);

    bool guardarDetalle(DetalleCompra registro);
    DetalleCompra leer(int pos);

    int getCantidadRegistros();
    bool eliminar(int idCompra);
    bool guardar(DetalleCompra detalle, int pos);
};

