#pragma once
#include "Fecha.h"
#include <string>

class Venta{
private:
    int _idVenta;
    float _importeTotal;
    char _medioPago[20];
    Fecha _fechaVenta;

public:
    Venta();
    Venta(int idVenta, float importeTotal, std::string medioPago, Fecha fechaVenta);

    void setIdVenta(int idVenta);
    void setImporteTotal(float importeTotal);
    void setMedioPago(std::string medioPago);
    void setFechaVenta(Fecha fechaVenta);

    int getIdVenta();
    float getImporteTotal();
    std::string getMedioPago();
    Fecha getFechaVenta();

};


