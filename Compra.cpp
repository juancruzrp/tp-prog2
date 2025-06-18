
#include "Compra.h"
#include <cstring>
using namespace std;


Compra::Compra() {
    _idCompra = 0;
    _idProveedor = 0;
    _fechaCompra = Fecha();
   strcpy(_tipoFactura, "");
    _numeroFactura = 0;
    _importeTotal = 0.0;
    _pagado = false;
     _estado = true;

}

Compra::Compra(int idCompra, int idProveedor, Fecha fecha,std::string tipoFactura , int numeroFactura, float importeTotal, bool pagado, bool estado){
    _idCompra = idCompra;
    _idProveedor = idProveedor;
    _fechaCompra = fecha;
   strcpy(_tipoFactura, tipoFactura.c_str());
    _numeroFactura = numeroFactura;
    _importeTotal = importeTotal;
    _pagado = pagado;
    estado = estado;
}

void Compra::setIdCompra(int idCompra) {
    _idCompra = idCompra;
}

void Compra::setIdProveedor(int idProveedor) {
    _idProveedor = idProveedor;
}

void Compra::setFechaCompra(Fecha fecha) {
    _fechaCompra = fecha;
}
void Compra::setTipoFactura(std::string tipoFactura) {
    strcpy(_tipoFactura, tipoFactura.c_str());
}

void Compra::setNumeroFactura(int numeroFactura) {
    _numeroFactura = numeroFactura;
}

void Compra::setImporteTotal(float importeTotal) {
    _importeTotal = importeTotal;
}

void Compra::setPagado(bool pagado) {
    _pagado = pagado;
}

void Compra::setEstado(bool estado) {
    _estado = estado;
}
// Getters
int Compra::getIdCompra() {
    return _idCompra;
}

int Compra::getIdProveedor() {
    return _idProveedor;
}

std::string Compra::getTipoFactura() {
    return std::string(_tipoFactura);
}

int Compra::getNumeroFactura() {
    return _numeroFactura;
}

float Compra::getImporteTotal() {
    return _importeTotal;
}

bool Compra::getPagado() {
    return _pagado;
}

Fecha Compra::getFechaCompra() {
    return _fechaCompra;
}

int Compra::getDia() {
    return _fechaCompra.getDia(); }
int Compra::getMes() {
    return _fechaCompra.getMes();
}
int Compra::getAnio() {
    return _fechaCompra.getAnio();
    }

bool Compra::getEstado() const {
    return _estado;
}

