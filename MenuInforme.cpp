#include <iostream>
#include "MenuInforme.h"
#include "FerreteriaManager.h"
using namespace std;


void MenuInforme::mostrar(){

    int opcion;
    FerreteriaManager manager;

    do{
    cout << "======================================" << endl;
    cout << "           MENU INFORMES" << endl;
    cout << "======================================"<< endl;
    cout << "1. Cantidad total de compras mensuales" << endl;
    cout << "2. Cantidad total de compras anuales" << endl;
    cout << "3. Cantidad total de ventas mensuales" << endl;
    cout << "4. Cantidad total de ventas anuales" << endl;
    cout << "5. Productos mas vendidos" << endl;
    cout << "0. Salir al menu principal" << endl;
    cout << "======================================"<< endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch(opcion) {
            case 1:
                system("cls");
                cout << "======================================" << endl;
                cout << "    CANTIDAD DE COMPRAS MENSUALES" << endl ;
                cout << "======================================" << endl;
                ///
                system("pause");
                system("cls");
                break;
            case 2:
                system("pause");
                system("cls");
                cout << "======================================" << endl;
                cout << "     CANTIDAD DE COMPRAS ANUALES" << endl ;
                cout << "======================================" << endl;
                ///
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                cout << "======================================" << endl;
                cout << "     CANTIDAD DE VENTAS MENSUALES" << endl ;
                cout << "======================================" << endl;
                ///
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                cout << "======================================" << endl;
                cout << "      CANTIDAD DE VENTAS ANUALES" << endl ;
                cout << "======================================" << endl;
                ///
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                cout << "======================================" << endl;
                cout << "         PRODUCTO MAS VENDIDO" << endl ;
                cout << "======================================" << endl;
                ///
                system("pause");
                system("cls");
               break;
            case 0:
                system("cls");
                cout << "======================================" << endl;
                cout << "     SALIENDO AL MENU PRINCIPAL" << endl ;
                cout << "======================================" << endl;
                return;
                break;
            default:
                system("cls");
                cout << "======================================" << endl;
                cout << "          OPCION INVALIDA" << endl ;
                cout << "======================================" << endl;
                system("pause");
                system("cls");
        }

    } while(opcion != 0);


}
