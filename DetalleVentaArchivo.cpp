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



bool DetalleVentaArchivo::guardar(DetalleVenta registro,int posicion){

    FILE *pFile;
    bool result;

    pFile =fopen(_nombreArchivo.c_str(),"rb+");

    if( pFile == nullptr){
        return false;
    }

    fseek( pFile , posicion * sizeof(DetalleVenta), SEEK_SET);
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


int DetalleVentaArchivo::buscar(int idVenta){
    FILE *pFile;
    DetalleVenta registro;
    int posicion=0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr) {
        return -1;
    }

    while(fread(&registro, sizeof(DetalleVenta), 1, pFile) == 1){
        if(registro.getIdVenta() == idVenta){
            fclose(pFile);
            return posicion;
        }
        posicion++;
    }

    fclose(pFile);
    return -1;
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


int buscar(int){
}

bool baja(int idVenta){

}



