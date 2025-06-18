
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
    bool _estado;

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
    void setEstado(bool estado);
    // Getters
    int getIdCompra();
    int getIdProveedor();
    Fecha getFechaCompra();
    std::string getTipoFactura();
    int getNumeroFactura();
    float getImporteTotal();
    bool getPagado();
    bool getEstado() const;

    // Métodos auxiliares para acceder a la fecha
    int getDia();
    int getMes();
    int getAnio();
};



