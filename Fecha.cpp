#include <iostream>
#include <limits>
#include "Fecha.h"
using namespace std;

Fecha::Fecha(){
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}


void Fecha::cargar(){
    cout << "Ingrese dia: " ;
    cin >> _dia;
        while(cin.fail() || _dia<=0 || _dia>31){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "DIA INVALIDO. VUELVA A INGRESAR DIA." << endl ;
            system("pause");
            system("cls");
            cout << "Ingrese Dia: " ;
            cin >> _dia;
        }

    cout << "Ingrese mes: ";
    cin >> _mes;
        while(cin.fail() || _mes<=0 || _mes>12 || (_dia>28 && _mes==2) || (_dia>30 && _mes ==4) || (_dia>30 && _mes==6) || (_dia>30 && _mes==9) || (_dia>30 && _mes==11)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "MES INVALIDO. VUELVA A INGRESAR MES." << endl ;
            system("pause");
            system("cls");
            cout << "Ingrese Mes: " ;
            cin >> _mes;
        }

    cout << "Ingrese anio: ";
    cin >> _anio;
        while(cin.fail() || _anio !=2025 ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "AÑO INVALIDO. VUELVA A INGRESAR ANIO." << endl ;
            system("pause");
            system("cls");
            cout << "Ingrese Anio: " ;
            cin >> _anio;
        }

}

void Fecha::mostrar(){
    cout << "Fecha: " ;
    cout << _dia << "/" << _mes << "/" << _anio;

}



int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}
