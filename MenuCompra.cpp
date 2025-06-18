#include <iostream>
#include "MenuCompra.h"
#include "FerreteriaManager.h"
using namespace std;

void MenuCompra::mostrar(){

    int opcion;
    FerreteriaManager manager;

    do{
    cout << "======================================" << endl;
    cout << "             MENU COMPRA" << endl;
    cout << "======================================"<< endl;
    cout << "1. Registrar nueva compra" << endl;
    cout << "2. Listar todas las compras" << endl;
    cout << "3. Buscar compra por fecha" << endl;
    cout << "4. Buscar compra por proveedor" << endl;
    cout << "5. Cantidad de compras registradas "<< endl;
    cout << "6. Eliminar venta " << endl;
    cout << "0. Salir al menu principal" << endl;
    cout << "======================================"<< endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch(opcion) {
            case 1:
                system("cls");
                cout << "======================================" << endl;
                cout << "       REGISTRAR NUEVO COMPRA" << endl ;
                cout << "======================================" << endl;
              manager.cargarCompra();
                system("cls");
                cout << "======================================" << endl;
                cout << "    COMPRA REGISTRADA CORRECTAMENTE" << endl ;
                cout << "======================================" << endl;
                system("pause");
                system("cls");
                break;

            case 2:
                  system("cls");
                cout << "======================================" << endl;
                cout << "           LISTAR TODAS LAS COMPRAS" << endl ;
                cout << "======================================" << endl;
                manager.listarCompras();
                system("pause");
                system("cls");

                break;

            case 3:
                system("cls");
                cout << "======================================" << endl;
                cout << "      BUSCAR COMPRA POR FEHCA" << endl ;
                cout << "======================================" << endl;
                manager.buscarCompraPorFecha();
                system("pause");
                system("cls");

                break;
            case 4:
                system("cls");
                cout << "======================================" << endl;
                cout << "      BUSCAR COMPRA POR PROVEEDOR" << endl ;
                cout << "======================================" << endl;
                manager.buscarCompraPorProveedor();
                system("pause");
                system("cls");

                break;
            case 5:
                 system("cls");
                cout << "======================================" << endl;
                cout << "      CANTIDAD DE COMPRAS REGISTRADAS" << endl ;
                cout << "======================================" << endl;
                manager.listarCantidadCompras();
                system("pause");
                system("cls");

               break;
               case 6:
                system("cls");
                cout << "======================================" << endl;
                cout << "            ELIMINAR VENTA " << endl ;
                cout << "======================================" << endl;
             //  manager.eliminarCompra();
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
