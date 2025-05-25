#include <iostream>
#include "MenuProducto.h"
using namespace std;

void MenuProducto::mostrar(){

    int opcion;

    do{
    cout << "======================================" << endl;
    cout << "           MENU PRODUCTOS " << endl;
    cout << "======================================"<< endl;
    cout << "1. Registrar nuevo producto" << endl;
    cout << "2. Listar todos los productos" << endl;
    cout << "3. Buscar productos por codigo" << endl;
    cout << "4. Buscar productos por nombre" << endl;
    cout << "5. Buscar productos por tipo" << endl;
    cout << "6. Modificar precio unitario de producto"<< endl;
    cout << "7. Cantidad de productos registrados "<< endl;
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
            case 6:

                break;
            case 7:

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
