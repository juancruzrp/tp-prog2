#pragma once
#include <string>

class Producto{
private:
    int _codProducto;
    char _nombreProducto[30];
    char _tipoProducto[30];
    char _marca[30];
    char _unidadMedida[20];
    float _precioUnitario;
    int _stock;

public:
    Producto();
    Producto(int codProducto, std::string nombreProducto, std::string tipoProducto, std::string marca, std::string unidadMedida,float precioUnitario, int stock);

    void setCodProducto(int codProducto);
    void setNombreProducto(std::string nombreProducto);
    void setTipoProducto(std::string tipoProducto);
    void setMarca(std::string marca);
    void setUnidadMedida(std::string unidadMedida);
    void setPrecioUnitario(float precioUnitario);
    void setStock(int stock);

    int getCodProducto();
    std::string getNombreProducto();
    std::string getTipoProducto();
    std::string getMarca();
    std::string getUnidadMedida();
    float getPrecioUnitario();
    int getStock();

};
