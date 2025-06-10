#include <iostream>
#include "VentaArchivo.h"
using namespace std;

VentaArchivo::VentaArchivo(){
 _nombreArchivo = "ventas.dat";
}

VentaArchivo::VentaArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool VentaArchivo::guardar(Venta registro){
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == nullptr) {
        return false;
    }

    result = fwrite(&registro, sizeof(Venta), 1, pFile);

    fclose(pFile);
    return result;

}

int VentaArchivo::buscar(int){
}

Venta VentaArchivo::leer(Venta){
}

bool VentaArchivo::eliminar(){
}

int VentaArchivo::getCantidadRegistros(){
}
