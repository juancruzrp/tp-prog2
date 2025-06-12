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

Venta VentaArchivo::leer(int pos){
    FILE *pFile;
    Venta registro;

    pFile = fopen(_nombreArchivo.c_str(),"rb");

    if(pFile == nullptr){
        return registro;
    }
    fseek(pFile,sizeof(Venta)* pos,SEEK_SET);
    fread(&registro,sizeof(Venta),1, pFile);
    fclose(pFile);

    return registro;
}


bool VentaArchivo::eliminar(){
}





int VentaArchivo::getCantidadRegistros(){
    FILE *pFile;
    int tamReg, total, cantidad;

    tamReg = sizeof(Venta);

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
