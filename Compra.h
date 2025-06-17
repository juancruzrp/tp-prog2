
#pragma once
#include <string>
#include "Fecha.h"

class Compra {
private:
    int _idCompra;
    int _idProveedor;
    Fecha _fechaCompra;
    char _tipoFactura[4];  // Ej: "A", "B", "C" + '\0'
    int _numeroFactura;
    float _importeTotal;
    bool _pagado;

public:
    // Constructores
    Compra();
    Compra(int idCompra, int idProveedor, Fecha fechaCompra, std::string tipoFactura,
           int numeroFactura, float importeTotal, bool pagado, bool estado);

    // Setters
    void setIdCompra(int idCompra);
    void setIdProveedor(int idProveedor);
    void setFechaCompra(Fecha fechaCompra);
    void setTipoFactura(std::string tipoFactura);
    void setNumeroFactura(int numeroFactura);
    void setImporteTotal(float importeTotal);
    void setPagado(bool pagado);

    // Getters
    int getIdCompra();
    int getIdProveedor();
    Fecha getFechaCompra();
    std::string getTipoFactura();
    int getNumeroFactura();
    float getImporteTotal();
    bool getPagado();

    // Métodos auxiliares para acceder a la fecha
    int getDia();
    int getMes();
    int getAnio();
};



