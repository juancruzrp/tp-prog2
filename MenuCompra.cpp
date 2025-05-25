#include <iostream>
#include "MenuCompra.h"
using namespace std;

void MenuCompra::mostrar(){

    int opcion;

    do{
    cout << "======================================" << endl;
    cout << "             MENU COMPRA" << endl;
    cout << "======================================"<< endl;
    cout << "1. Registrar nueva compra" << endl;
    cout << "2. Listar todas las compras" << endl;
    cout << "3. Buscar compra por fecha" << endl;
    cout << "4. Buscar compra por proveedor" << endl;
    cout << "5. Cantidad de compras registradas "<< endl;
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
