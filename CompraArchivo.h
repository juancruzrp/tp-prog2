
#pragma once
#include "Compra.h"
#include <fstream>
#include <string>
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
    int buscar(int idCompra);
    bool guardar(Compra compra, int pos);
    int getCantidadRegistros();
    bool eliminar(int idCompra);
};

