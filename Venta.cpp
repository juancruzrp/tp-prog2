#include <iostream>
#include "Venta.h"
#include <cstring>
using namespace std;

Venta::Venta(){
    _idVenta = 0;
    _importeTotal = 0;
    strcpy(_medioPago, "");
    _fechaVenta = Fecha();
    _estado = true;
}

Venta::Venta(int idVenta, float importeTotal, std::string medioPago, Fecha fechaVenta, bool estado){
    setIdVenta(idVenta);
    setImporteTotal(importeTotal);
    setMedioPago(medioPago);
    setFechaVenta(fechaVenta);
    setEstado(true);

}



void Venta::setIdVenta(int idVenta){
    _idVenta = idVenta;
}

void Venta::setImporteTotal(float importeTotal){
    _importeTotal = importeTotal;
}
void Venta::setMedioPago(std::string medioPago){
    strcpy(_medioPago, medioPago.c_str());
}

void Venta::setFechaVenta(Fecha fechaVenta){
    _fechaVenta = fechaVenta;
}

void Venta::setEstado(bool estado){
    _estado = estado;
}

int Venta::getIdVenta(){
    return _idVenta;
}

float Venta::getImporteTotal(){
    return _importeTotal;
}

std::string Venta::getMedioPago(){
    return _medioPago;
}

Fecha Venta::getFechaVenta(){
    return _fechaVenta;
}

bool Venta::getEstado(){
    return _estado;
}

