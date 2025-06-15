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
int ProductoArchivo::buscarProducto(int idProducto){
    FILE *pFile;
    Producto registro;
    int posicion=0;
    pFile =fopen(_nombreArchivo.c_str(),"rb");
    if(pFile == nullptr){
        return -1;
    }
    while(fread( &registro , sizeof(Producto), 1 , pFile)==1){
        if(registro.getCodProducto() == idProducto){
            fclose(pFile);
            return posicion;

        }
        posicion++;

    }
    fclose(pFile);
    return -1;
}

bool ProductoArchivo::guardarProducto(Producto registro,int posicion){

    FILE *pFile;
    bool result;

    pFile =fopen(_nombreArchivo.c_str(),"rb+");

    if( pFile == nullptr){
        return false;
    }
    fseek( pFile , posicion * sizeof(Producto), SEEK_SET);
    result = fwrite(&registro, sizeof(Producto), 1, pFile);
    fclose(pFile);
    return result;
    }
