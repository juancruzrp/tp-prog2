#pragma once
#include <string>

class Proveedor{
private:
    int _idProveedor;
    char _nombreProveedor[30];
    char _telefono[30];
    char _email[40];
    char _direccion[30];

public:
    Proveedor();
    Proveedor(int idProveedor, std::string nombreProveedor, std::string telefono, std::string email, std::string direccion);

    void setIdProveedor(int idProveedor);
    void setNombreProveedor(std::string nombreProveedor);
    void setTelefono(std::string telefono);
    void setEmail(std::string email);
    void setDireccion(std::string direccion);


    int getIdProveedor();
    std::string getNombreProveedor();
    std::string getTelefono();
    std::string getEmail();
    std::string getDireccion();

    std::string toCSV();

};

