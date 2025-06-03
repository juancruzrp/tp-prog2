#include <iostream>
#include "Producto.h"
#include <cstring>
using namespace std;
Producto::Producto(){
    int _codProducto = 0;
    strcpy(_nombreProducto, "");
    strcpy(_tipoProducto, "");
    strcpy(_marca, "");
    strcpy(_unidadMedida, "");
    float _precioUnitario = 0;
    int _stock = 0;
}

Producto::Producto(int codProducto, std::string nombreProducto, std::string tipoProducto, std::string marca, std::string unidadMedida,float precioUnitario, int stock){
    setCodProducto(codProducto);
    setNombreProducto(nombreProducto);
    setTipoProducto(tipoProducto);
    setMarca(marca);
    setUnidadMedida(unidadMedida);
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

void Producto::setMarca(std::string marca){
    strcpy(_marca, marca.c_str());
}

void Producto::setUnidadMedida(std::string unidadMedida){
    strcpy(_unidadMedida, unidadMedida.c_str());
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

std::string Producto::getMarca(){
    return _marca;
}

std::string Producto::getUnidadMedida(){
    return _unidadMedida;
}

float Producto::getPrecioUnitario(){
    return _precioUnitario;
}

int Producto::getStock(){
    return _stock;
}
    std::string Producto::toCSV(){
        std::string str = "";
        str = to_string(_codProducto) + ",";
        str += string(_nombreProducto) + ",";
        str += string(_tipoProducto) + ",";
        str += string(_marca) + ",";
        str += string(_unidadMedida) + ",";
        str += to_string(_precioUnitario) + ",";
        str += to_string(_stock);

        return str;
    }
