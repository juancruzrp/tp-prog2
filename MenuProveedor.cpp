#include <iostream>
#include "MenuProveedor.h"
using namespace std;

void MenuProveedor::mostrar(){

    int opcion;

    do{
    cout << "======================================" << endl;
    cout << "           MENU PROVEEDORES " << endl;
    cout << "======================================"<< endl;
    cout << "1. Registrar nuevo proveedor" << endl;
    cout << "2. Listar todos los proveedores" << endl;
    cout << "3. Buscar proveedor por id" << endl;
    cout << "4. Buscar proveedor por nombre" << endl;
    cout << "5. Modificar telefono" << endl;
    cout << "6. Modificar direccion" << endl;
    cout << "7. Cantidad de proveedores registrados "<< endl;
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
