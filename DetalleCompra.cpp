#include <iostream>
#include "DetalleCompra.h"
using namespace std;

DetalleCompra::DetalleCompra() {
    _idCompra = 0;
    _codProducto = 0;
    _precioUnitario = 0;
    _cantidad = 0;
    _subtotal = 0;
    _estado = true;
}

// Constructor
DetalleCompra::DetalleCompra(int idCompra, int codProducto, float precioUnitario, int cantidad) {
    _idCompra = idCompra;
    _codProducto = codProducto;
    _precioUnitario = precioUnitario;
    _cantidad = cantidad;
    _subtotal = precioUnitario * cantidad;
    _estado = true;
}


// Setters
void DetalleCompra::setIdCompra(int idCompra) {
    _idCompra = idCompra;
}

void DetalleCompra::setCodProducto(int codProducto) {
    _codProducto = codProducto;
}

void DetalleCompra::setPrecioUnitario(float precioUnitario) {
    _precioUnitario = precioUnitario;
}

void DetalleCompra::setCantidad(int cantidad) {
    _cantidad = cantidad;
}

void DetalleCompra::setSubtotal(float subtotal) {
    _subtotal = subtotal;
}

// Getters
int DetalleCompra::getIdCompra() {
    return _idCompra;
}

int DetalleCompra::getCodProducto() {
    return _codProducto;
}

float DetalleCompra::getPrecioUnitario() {
    return _precioUnitario;
}

int DetalleCompra::getCantidad() {
    return _cantidad;
}

float DetalleCompra::getSubtotal() {
    return _subtotal;
}

// Calcula subtotal
void DetalleCompra::calcularSubtotal() {
    _subtotal = _precioUnitario * _cantidad;
}
