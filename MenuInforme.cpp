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
    cout << "1. Productos con bajo stock disponible" << endl;
    cout << "2. Monto total de compras anuales" << endl;
    cout << "3. Compras pendientes de pago" << endl;
    cout << "4. Productos no vendidos" << endl;
    cout << "0. Salir al menu principal" << endl;
    cout << "======================================"<< endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch(opcion) {
            case 1:
                system("cls");
                cout << "======================================" << endl;
                cout << "  PRODUCTOS CON BAJO STOCK DISPONIBLE" << endl ;
                cout << "======================================" << endl;
                manager.productosBajoStock();
                system("pause");
                system("cls");
                break;
            case 2:
                system("pause");
                system("cls");
                cout << "======================================" << endl;
                cout << "     MONTO TOTAL DE COMPRAS ANULES" << endl ;
                cout << "======================================" << endl;
                manager.totalGastadoPorAnioMes();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                cout << "======================================" << endl;
                cout << "      COMPRAS PENDIENTES DE PAGO" << endl ;
                cout << "======================================" << endl;
                manager.listarComprasPendientes();
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                cout << "======================================" << endl;
                cout << "        PRODUCTOS NO VENDIDOS" << endl ;
                cout << "======================================" << endl;
                manager.productosNoVendidos();
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
