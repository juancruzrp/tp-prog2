#include "DetalleVenta.h"
#include <string>


DetalleVenta::DetalleVenta(){
    _idVenta = 0;
    _codProducto = 0;
    _precioUnitario = 0;
    _cantidad = 0;
    _subtotal = 0;
    _estado = 1;

}

DetalleVenta::DetalleVenta(int idVenta, int codProducto, float precioUnitario, int cantidad, float subtotal, bool estado){
    setIdVenta(idVenta);
    setCodProducto(codProducto);
    setPrecioUnitario(precioUnitario);
    setCantidad(cantidad);
    setSubtotal(subtotal);
    setEstado(estado);

}

void DetalleVenta::setIdVenta(int idVenta){
    _idVenta = idVenta;
}

void DetalleVenta::setCodProducto(int codProducto){
    _codProducto = codProducto;
}

void DetalleVenta::setPrecioUnitario(float precioUnitario){
    _precioUnitario = precioUnitario;
}

void DetalleVenta::setCantidad(int cantidad){
    _cantidad = cantidad;
}

void DetalleVenta::setSubtotal(float subtotal){
    _subtotal = subtotal;
}

void DetalleVenta::setEstado(bool estado){
    _estado = estado;
}

int DetalleVenta::getIdVenta(){
    return _idVenta;
}

int DetalleVenta::getCodProducto(){
    return _codProducto;
}

float DetalleVenta::getPrecioUnitario(){
    return _precioUnitario;
}

int DetalleVenta::getCantidad(){
    return _cantidad;
}

float DetalleVenta::getSubtotal(){
    return _subtotal;
}

bool DetalleVenta::getEstado(){
    return _estado;
}
