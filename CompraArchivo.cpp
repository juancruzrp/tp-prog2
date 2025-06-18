#include <iostream>
#include "Compra.h"
#include "CompraArchivo.h"


CompraArchivo::CompraArchivo(){
    _nombreArchivo = "compra.dat";
}

CompraArchivo::CompraArchivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool CompraArchivo::guardarCompra(Compra registro) {
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == nullptr) {
        return false;
    }

    result = fwrite(&registro, sizeof(Compra), 1, pFile);

    fclose(pFile);
    return result;
}

 Compra CompraArchivo::leer(int pos){

    FILE *pFile;
    Compra registro;

    pFile = fopen(_nombreArchivo.c_str(),"rb");

    if(pFile == nullptr){
        return registro;
    }
    fseek(pFile, sizeof(Compra) * pos, SEEK_SET);
    fread(&registro,sizeof(Compra),1, pFile);
    fclose(pFile);

    return registro;
 }


/*bool CompraArchivo::modificar(Compra reg, int pos) {
    FILE* p = fopen (_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) return false;

    fseek(p, 0, SEEK_END);
    int total = ftell(p);
    int cantidad = total / sizeof(Compra);

    if (pos < 0 || pos >= cantidad) {
        fclose(p);
        return false;
    }

    fseek(p, pos * sizeof(Compra), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Compra), 1, p);
    fclose(p);
    return ok;
}
*/
int CompraArchivo::getCantidadRegistros() {
    FILE* pFile;
    int tamReg = sizeof(Compra);
    int total, cantidad;

   pFile = fopen(_nombreArchivo.c_str(),"rb");
    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);
    total = ftell(pFile);
    fclose(pFile);

    cantidad = total / tamReg;
    return cantidad;
}
