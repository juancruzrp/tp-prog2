#pragma once
#include <string>

class DetalleCompra{
private:
    int _idCompra;
    int _codProducto;
    float _precioUnitario;
    int _cantidad;
    float _subtotal;

public:
    DetalleCompra();
    DetalleCompra(int idCompra, int codProducto, float precioUnitario, int cantidad, float subtotal);

    void setIdCompra(int idCompra);
    void setCodProducto(int codProducto);
    void setPrecioUnitario(float precioUnitario);
    void setCantidad(int cantidad);
    void setSubtotal(float subtotal);

    int getIdCompra();
    int getCodProducto();
    float getPrecioUnitario();
    int getCantidad();
    float getSubtotal();
};


