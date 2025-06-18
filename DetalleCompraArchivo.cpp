
#include "DetalleCompraArchivo.h"
#include <iostream>
#include <cstdio>

using namespace std;

DetalleCompraArchivo::DetalleCompraArchivo() {
    _nombreArchivo = "DetalleCompra.dat";
}

DetalleCompraArchivo::DetalleCompraArchivo(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

bool DetalleCompraArchivo::guardarDetalle(DetalleCompra registro) {
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == nullptr) {
        return false;
    }

    result = fwrite(&registro, sizeof(DetalleCompra), 1, pFile);

    fclose(pFile);
    return result;
}


DetalleCompra DetalleCompraArchivo::leer(int pos) {
    FILE *pFile;
    DetalleCompra registro;

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return registro;
    }

    fseek(pFile, sizeof(DetalleCompra) * pos, SEEK_SET);
    fread(&registro, sizeof(DetalleCompra), 1, pFile);
    fclose(pFile);

    return registro;
}

int DetalleCompraArchivo::getCantidadRegistros() {
    FILE *pFile;
    int tamReg, total, cantidad;

    tamReg = sizeof(DetalleCompra);

    pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == nullptr) {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);
    total = ftell(pFile);
    cantidad = total / tamReg;

    fclose(pFile);
    return cantidad;
}


bool DetalleCompraArchivo::eliminar(int idCompra) {
    FILE* pFile;
    pFile = fopen(_nombreArchivo.c_str(), "rb+");  // lectura/escritura
    if (pFile == nullptr) {
        return false;
    }

    DetalleCompra detalle;
    int pos = 0;
    while (fread(&detalle, sizeof(DetalleCompra), 1, pFile)) {
        if (detalle.getIdCompra() == idCompra && detalle.getEstado()) {
            detalle.setEstado(false);
            fseek(pFile, sizeof(DetalleCompra) * pos, SEEK_SET); // Volver registro actual
            fwrite(&detalle, sizeof(DetalleCompra), 1, pFile);
            fseek(pFile, sizeof(DetalleCompra) * (pos + 1), SEEK_SET); // sig posicion
        }
        pos++;
    }

    fclose(pFile);
    return true;
}
