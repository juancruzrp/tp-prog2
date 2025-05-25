#include <iostream>
#include "Producto.h"
#include <cstring>
using namespace std;

Producto::Producto(){
    int _codProducto = 0;
    strcpy(_nombreProducto, "");
    strcpy(_tipoProducto, "");
    float _precioUnitario = 0;
    int _stock = 0;
}

Producto::Producto(int codProducto, std::string nombreProducto, std::string tipoProducto, float precioUnitario, int stock){
    setCodProducto(codProducto);
    setNombreProducto(nombreProducto);
    setTipoProducto(tipoProducto);
    setPrecioUnitario(precioUnitario);
    setStock(stock);
}

void Producto::setCodProducto(int codProducto){
    _codProducto = codProducto;
}

void Producto::setNombreProducto(std::string nombreProducto){
    strcpy(_nombreProducto, nombreProducto.c_str());
}

void Producto::setTipoProducto(std::string tipoProducto){
    strcpy(_tipoProducto, tipoProducto.c_str());
}

void Producto::setPrecioUnitario(float precioUnitario){
    _precioUnitario = precioUnitario;
}

void Producto::setStock(int stock){
    _stock = stock;
}

int Producto::getCodProducto(){
    return _codProducto;
}

std::string Producto::getNombreProducto(){
    return _nombreProducto;
}

std::string Producto::getTipoProducto(){
    return _tipoProducto;
}

float Producto::getPrecioUnitario(){
    return _precioUnitario;
}

int Producto::getStock(){
    return _stock;
}
