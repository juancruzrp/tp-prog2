
#pragma once
#include "Compra.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class CompraArchivo {
private:
    std::string _nombreArchivo;

public:
    CompraArchivo();
    CompraArchivo(std::string nombreArchivo);

     bool guardarCompra(Compra registro);
    int contarCompras();
    int contarRegistros();
    void mostrarCompras();
    void listarCompras();
    int buscarCompra(int idCompra);
    Compra leer(int pos);
    std::vector<Compra> leerTodasLasCompras();
    //std::vector<Compra> buscarCompraPorFecha(Fecha fecha);
    //bool modificar(Compra reg, int pos);

    int getCantidadRegistros();
    bool eliminar(int idCompra);
};

