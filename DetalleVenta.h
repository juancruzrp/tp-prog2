#pragma once
#include <string>

class DetalleVenta{
private:
    int _idVenta;
    int _codProducto;
    float _precioUnitario;
    int _cantidad;
    float _subtotal;

public:
    DetalleVenta();
    DetalleVenta(int idVenta, int codProducto, float precioUnitario, int cantidad, float subtotal);

    void setIdVenta(int idVenta);
    void setCodProducto(int codProducto);
    void setPrecioUnitario(float precioUnitario)
    void setCantidad(int cantidad);
    void setSubtotal(float subtotal);

    int getIdVenta();
    int getCodProducto();
    float getPrecioUnitario()
    int getCantidad();
    float getSubtotal();

};


