#pragma once
#include <string>

class Compra{
private:
    int _idCompra;
    int _idProveedor;
    Fecha _fechaCompra;
    char _tipoFactura[5];
    int _numeroFactura;
    float _importeTotal;
    bool _pagado;

public:
    Compra();
    Compra(int idCompra, int idProveedor, Fecha fechaCompra, std::string tipoFactura, int numeroFactura, float importeTotal, bool pagado);

    void setIdCompra(int idCompra);
    void setIdProveedor(int idProveedor);
    void setFechaCompra(Fecha fechaCompra);
    void setTipoFactura(std::string tipoFactura);
    void setNumeroFactura(int numeroFactura);
    void setImporteTotal(float importeTotal);
    void setPagado(bool pagado);

    int getIdCompra();
    int getIdProveedor();
    Fecha getFechaCompra();
    std::string getTipoFactura();
    int getNumeroFactura();
    float getImporteTotal();
    bool getPagado();
};



