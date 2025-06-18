#include <iostream>
#include "FerreteriaManager.h"
#include "MenuVenta.h"
using namespace std;

void MenuVenta::mostrar(){

    int opcion;
    FerreteriaManager manager;

    do{
    cout << "======================================" << endl;
    cout << "              MENU VENTA" << endl;
    cout << "======================================"<< endl;
    cout << "1. Registrar nueva venta" << endl;
    cout << "2. Listar todas las ventas" << endl;
    cout << "3. Listar detalle de venta" << endl;
    cout << "4. Buscar venta por fecha" << endl;
    cout << "5. Buscar venta por producto" << endl;
    cout << "6. Cantidad de ventas registradas " << endl;
    cout << "7. Eliminar venta " << endl;
    cout << "0. Salir al menu principal" << endl;
    cout << "======================================"<< endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch(opcion) {
            case 1:
                system("cls");
                cout << "======================================" << endl;
                cout << "        REGISTRAR NUEVA VENTA" << endl ;
                cout << "======================================" << endl;
                manager.cargarVenta();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                cout << "======================================" << endl;
                cout << "       LISTAR TODAS LAS VENTAS" << endl ;
                cout << "======================================" << endl;
                manager.listarVentas();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                cout << "======================================" << endl;
                cout << "       LISTAR DETALLE DE VENTA" << endl ;
                cout << "======================================" << endl;
                manager.listarDetalleVenta();
                system("pause");
                system("cls");
                break;

            case 4:
                system("cls");
                cout << "======================================" << endl;
                cout << "        BUSCAR VENTA POR FECHA" << endl ;
                cout << "======================================" << endl;
                manager.buscarVentaPorFecha();
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                cout << "======================================" << endl;
                cout << "      BUSCAR VENTA POR PRODUCTO" << endl ;
                cout << "======================================" << endl;
                manager.buscarVentaPorProducto();
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                cout << "======================================" << endl;
                cout << "    CANTIDAD DE VENTAS REGISTRADAS" << endl ;
                cout << "======================================" << endl;
                manager.listarCantidadVentas();
                system("pause");
                system("cls");
                break;
            case 7:
                system("cls");
                cout << "======================================" << endl;
                cout << "            ELIMINAR VENTA " << endl ;
                cout << "======================================" << endl;
                manager.bajaDeVenta();
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
