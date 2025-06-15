#include <iostream>
#include "DetalleVentaArchivo.h"
using namespace std;

DetalleVentaArchivo::DetalleVentaArchivo(){
    _nombreArchivo = "DetalleVenta.dat";
}

DetalleVentaArchivo::DetalleVentaArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}



bool DetalleVentaArchivo::guardar(DetalleVenta registro) {
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == nullptr) {
        return false;
    }

    result = fwrite(&registro, sizeof(DetalleVenta), 1, pFile);

    fclose(pFile);
    return result;
}






DetalleVenta DetalleVentaArchivo::leer(int pos){

    FILE *pFile;
    DetalleVenta registro;

    pFile = fopen(_nombreArchivo.c_str(),"rb");

    if(pFile == nullptr){
        return registro;
    }
    fseek(pFile,sizeof(DetalleVenta)* pos,SEEK_SET);
    fread(&registro,sizeof(DetalleVenta),1, pFile);
    fclose(pFile);

    return registro;
 }






int DetalleVentaArchivo::getCantidadRegistros(){
    FILE *pFile;
    int tamReg, total, cantidad;

    tamReg = sizeof(DetalleVenta);

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile==nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    total = ftell(pFile);

    cantidad = total / tamReg ;

    fclose(pFile);

    return cantidad;
}



bool DetalleVentaArchivo::eliminar(int idEliminar){
    DetalleVentaArchivo detalleVenta;
    DetalleVenta id;
    VentaArchivo venta;
    Venta idB;
    int cantidadRegistros = detalleVenta.getCantidadRegistros();

    for (int x=0; x<cantidadRegistros ; x++){
        id = detalleVenta.leer(x);
        idB = venta.leer(x);
            if (id.getIdVenta() == idEliminar && idB.getIdVenta() == idEliminar){
                id.setEstado(0);
                idB.setEstado(0);
            }
    }

}

bool DetalleVentaArchivo::alta(int idEliminar){
    DetalleVentaArchivo detalleVenta;
    DetalleVenta id;
    VentaArchivo venta;
    Venta idB;
    int cantidadRegistros = getCantidadRegistros();

    for (int x=0; x<cantidadRegistros ; x++){
        id = detalleVenta.leer(x);
        idB = venta.leer(x);
            if (id.getIdVenta() == idEliminar && idB.getIdVenta() == idEliminar){
                id.setEstado(1);
                idB.setEstado(1);
            }
    }

}

