#pragma once
#include <string>

class Producto{
private:
    int _codProducto;
    char _nombreProducto[30];
    char _tipoProducto[20];
    float _precioUnitario;
    int _stock;

public:
    Producto();
    Producto(int codProducto, std::string nombreProducto, std::string tipoProducto, float precioUnitario, int stock);

    void setCodProducto(int codProducto);
    void setNombreProducto(std::string nombreProducto);
    void setTipoProducto(std::string tipoProducto);
    void setPrecioUnitario(float precioUnitario);
    void setStock(int stock);

    int getCodProducto();
    std::string getNombreProducto();
    std::string getTipoProducto();
    float getPrecioUnitario();
    int getStock();

};
