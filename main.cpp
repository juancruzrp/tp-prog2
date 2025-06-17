#include <iostream>
#include "MenuProducto.h"
#include "MenuProveedor.h"
#include "MenuCompra.h"
#include "MenuVenta.h"
#include "MenuInforme.h"
using namespace std;

int main()
{
    int opcion;
    MenuProducto menuproducto;
    MenuProveedor menuproveedor;
     MenuCompra MenuCompra;
    MenuVenta menuventa;
    MenuInforme menuinforme;


    do{
    cout << "======================================" << endl;
    cout << "    SISTEMA DE GESTION FERRETERIA   " << endl ;
    cout << "======================================" << endl;
    cout << "1. Menu Productos" << endl;
    cout << "2. Menu Proveedores" << endl;
    cout << "3. Menu Compras" << endl;
    cout << "4. Menu Ventas" << endl;
    cout << "5. Generar Informe" << endl;
    cout << "0. Salir" << endl;
    cout << "======================================"<< endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            system("cls");
            menuproducto.mostrar();
            system("pause");
            system("cls");
        break;
        case 2:
            system("cls");
            menuproveedor.mostrar();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            MenuCompra.mostrar();
            system("pause");
            system("cls");

            break;
        case 4:
            system("cls");
            menuventa.mostrar();
            system("pause");
            system("cls");

            break;

        case 5:
            system("cls");
            menuinforme.mostrar();
            system("pause");
            system("cls");

            break;
        case 0:
            system("cls");
            cout << "======================================" << endl;
            cout << "       SALIENDO DEL SISTEMA" << endl ;
            cout << "======================================" << endl;
            return 0;
            break;
        default:
            system("cls");
            cout << "======================================" << endl;
            cout << "          OPCION INVALIDA" << endl ;
            cout << "======================================" << endl;
            system("pause");
            system("cls");
        }


    }while(opcion!=0);



    return 0;
}
