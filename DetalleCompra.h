

#ifndef DETALLECOMPRA_H
#define DETALLECOMPRA_H

class DetalleCompra {
private:
    int _idCompra;        // ID que vincula con Compra
    int _codProducto;
    float _precioUnitario;
    int _cantidad;
    float _subtotal;
    bool _estado;

public:
    DetalleCompra();
    DetalleCompra(int idCompra, int codProducto, float precioUnitario, int cantidad);

    // Setters
    void setIdCompra(int idCompra);
    void setCodProducto(int codProducto);
    void setPrecioUnitario(float precioUnitario);
    void setCantidad(int cantidad);
    void setSubtotal(float subtotal);
    bool getEstado() const { return _estado; }


    // Getters
    int getIdCompra();
    int getCodProducto();
    float getPrecioUnitario();
    int getCantidad();
    float getSubtotal();
    void setEstado(bool estado) { _estado = estado; }


    // Método para calcular subtotal (precio * cantidad)
    void calcularSubtotal();
};

#endif
