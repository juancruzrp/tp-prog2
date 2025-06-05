#include <iostream>
#include "Producto.h"
#include "ProductoArchivo.h"
using namespace std;


ProductoArchivo::ProductoArchivo(){
    _nombreArchivo = "productos.dat";
}

ProductoArchivo::ProductoArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


bool ProductoArchivo::guardarProducto(Producto registro) {
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == nullptr) {
        return false;
    }

    result = fwrite(&registro, sizeof(Producto), 1, pFile);

    fclose(pFile);
    return result;
}



int ProductoArchivo::getCantidadRegistros(){
    FILE *pFile;
    int tamReg, total, cantidad;

    tamReg = sizeof(Producto);

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


 Producto ProductoArchivo::leer(int pos){

    FILE *pFile;
    Producto registro;

    pFile = fopen(_nombreArchivo.c_str(),"rb");

    if(pFile == nullptr){
        return registro;
    }
    fseek(pFile,sizeof(Producto)* pos,SEEK_SET);
    fread(&registro,sizeof(Producto),1, pFile);
    fclose(pFile);

    return registro;
 }
