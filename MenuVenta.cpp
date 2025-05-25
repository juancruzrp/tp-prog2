#include <iostream>
#include "MenuVenta.h"
using namespace std;

void MenuVenta::mostrar(){

    int opcion;

    do{
    cout << "======================================" << endl;
    cout << "              MENU VENTA" << endl;
    cout << "======================================"<< endl;
    cout << "1. Registrar nueva venta" << endl;
    cout << "2. Listar todas las ventas" << endl;
    cout << "3. Buscar venta por fecha" << endl;
    cout << "4. Buscar venta por producto" << endl;
    cout << "5. Cantidad de ventas registradas "<< endl;
    cout << "0. Salir al menu principal" << endl;
    cout << "======================================"<< endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch(opcion) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

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
