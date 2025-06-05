#include <iostream>
#include "Proveedor.h"
#include <cstring>
using namespace std;

Proveedor::Proveedor(){
    _idProveedor = 0;
    strcpy(_nombreProveedor, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
    strcpy(_direccion, "");

}

Proveedor::Proveedor(int idProveedor, std::string nombreProveedor, std::string telefono, std::string email, std::string direccion){
    setIdProveedor(idProveedor);
    setNombreProveedor(nombreProveedor);
    setTelefono(telefono);
    setEmail(email);
    setDireccion(direccion);

}

void Proveedor::setIdProveedor(int idProveedor){
    _idProveedor = idProveedor;
}

void Proveedor::setNombreProveedor(std::string nombreProveedor){
    strcpy(_nombreProveedor, nombreProveedor.c_str());
}

void Proveedor::setTelefono(std::string telefono){
    strcpy(_telefono, telefono.c_str());
}

void Proveedor::setEmail(std::string email){
    strcpy(_email, email.c_str());
}

void Proveedor::setDireccion(std::string direccion){
    strcpy(_direccion, direccion.c_str());
}

int Proveedor::getIdProveedor(){
    return _idProveedor;
}

std::string Proveedor::getNombreProveedor(){
    return _nombreProveedor;
}

std::string Proveedor::getTelefono(){
    return _telefono;
}

std::string Proveedor::getEmail(){
    return _email;
}

std::string Proveedor::getDireccion(){
    return _direccion;
}

std::string Proveedor::toCSV(){
    std::string str = "";
    str = to_string(_idProveedor) + ",";
    str += string(_nombreProveedor) + ",";
    str += string(_telefono) + ",";
    str += string(_email) + ",";
    str += string(_direccion);

        return str;
}
