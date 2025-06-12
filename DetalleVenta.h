#pragma once
#include <string>

class DetalleVenta{
private:
    int _idVenta;
    int _codProducto;
    float _precioUnitario;
    int _cantidad;
    float _subtotal;
    bool _estado;

public:
    DetalleVenta();
    DetalleVenta(int idVenta, int codProducto, float precioUnitario, int cantidad, float subtotal, bool estado);

    void setIdVenta(int idVenta);
    void setCodProducto(int codProducto);
    void setPrecioUnitario(float precioUnitario);
    void setCantidad(int cantidad);
    void setSubtotal(float subtotal);
    void setEstado(bool estado);

    int getIdVenta();
    int getCodProducto();
    float getPrecioUnitario();
    int getCantidad();
    float getSubtotal();
    bool getEstado();
};


