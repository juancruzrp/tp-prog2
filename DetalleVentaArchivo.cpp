#include <iostream>
#include "DetalleVentaArchivo.h"
using namespace std;

DetalleVentaArchivo::DetalleVentaArchivo(){
    _nombreArchivo = "DetalleVenta.dat";
}

DetalleVentaArchivo::DetalleVentaArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}
