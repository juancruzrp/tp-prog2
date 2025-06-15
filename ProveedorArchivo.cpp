#include <iostream>
#include "Proveedor.h"
#include "ProveedorArchivo.h"
using namespace std;


ProveedorArchivo::ProveedorArchivo(){
    _nombreArchivo = "proveedores.dat";
}

ProveedorArchivo::ProveedorArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}


bool ProveedorArchivo::guardarProveedor(Proveedor registro) {
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == nullptr) {
        return false;
    }

    result = fwrite(&registro, sizeof(Proveedor), 1, pFile);

    fclose(pFile);
    return result;
}



int ProveedorArchivo::getCantidadRegistros(){
    FILE *pFile;
    int tamReg, total, cantidad;

    tamReg = sizeof(Proveedor);

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


 Proveedor ProveedorArchivo::leer(int pos){

    FILE *pFile;
    Proveedor registro;

    pFile = fopen(_nombreArchivo.c_str(),"rb");

    if(pFile == nullptr){
        return registro;
    }
    fseek(pFile,sizeof(Proveedor)* pos,SEEK_SET);
    fread(&registro,sizeof(Proveedor),1, pFile);
    fclose(pFile);

    return registro;
 }
int ProveedorArchivo::buscarProveedor(int idProveedor){
    FILE *pFile;
    Proveedor registro;
    int posicion=0;
    pFile =fopen(_nombreArchivo.c_str(),"rb");
    if(pFile == nullptr){
        return -1;
    }
    while(fread( &registro , sizeof(Proveedor), 1 , pFile)==1){
        if(registro.getIdProveedor()==idProveedor){
            fclose(pFile);
            return posicion;

        }
        posicion++;

    }
    fclose(pFile);
    return -1;
}

bool ProveedorArchivo::guardarProveedor(Proveedor registro,int posicion){

    FILE *pFile;
    bool result;

    pFile =fopen(_nombreArchivo.c_str(),"rb+");

    if( pFile == nullptr){
        return false;
    }
    fseek( pFile , posicion * sizeof(Proveedor), SEEK_SET);
    result = fwrite(&registro, sizeof(Proveedor), 1, pFile);
    fclose(pFile);
    return result;
    }
