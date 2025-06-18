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


CompraArchivo::getCantidadRegistros() {
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

int CompraArchivo::buscar(int idCompra) {
    Compra compra;
    FILE* p = fopen(_nombreArchivo.c_str(), "rb");
    if (p == nullptr) return -1;

    int pos = 0;
    while (fread(&compra, sizeof(Compra), 1, p)) {
        if (compra.getIdCompra() == idCompra && compra.getEstado()) {
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}
bool CompraArchivo::guardar(Compra compra, int pos) {
    FILE* p = fopen(_nombreArchivo.c_str(), "rb+");
    if (p == nullptr) return false;

    fseek(p, pos * sizeof(Compra), SEEK_SET);
    bool ok = fwrite(&compra, sizeof(Compra), 1, p);

    fclose(p);
    return ok;
}
