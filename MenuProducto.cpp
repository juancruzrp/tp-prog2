#include <iostream>
#include "MenuProducto.h"
#include "FerreteriaManager.h"
using namespace std;

void MenuProducto::mostrar(){

    int opcion;
    FerreteriaManager manager;

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
                system("cls");
                cout << "======================================" << endl;
                cout << "       CARGAR NUEVO PRODUCTO" << endl ;
                cout << "======================================" << endl;
                manager.cargarProducto();
                system("cls");
                cout << "======================================" << endl;
                cout << "    PRODUCTO CARGADO CORRECTAMENTE" << endl ;
                cout << "======================================" << endl;
                system("pause");
                system("cls");
                break;
            case 2:
                manager.listarProductos();  // <<—— Aca llamás a la función
                 system("pause");
                 system("cls");
                cout << "======================================" << endl;
                cout << "           LISTAR PRODUCTOS" << endl ;
                cout << "======================================" << endl;
                ///
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                cout << "======================================" << endl;
                cout << "      BUSCAR PRODUCTO POR CODIGO" << endl ;
                cout << "======================================" << endl;
                ///
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                cout << "======================================" << endl;
                cout << "       BUSCAR PRODUCTO POR NOMBRE" << endl ;
                cout << "======================================" << endl;
                ///
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                cout << "======================================" << endl;
                cout << "       BUSCAR PRODUCTO POR TIPO" << endl ;
                cout << "======================================" << endl;
                ///
                system("pause");
                system("cls");
               break;
            case 6:
                system("cls");
                cout << "======================================" << endl;
                cout << "     MODIFICAR PRECIO DE PRODUCTO" << endl ;
                cout << "======================================" << endl;
                ///
                system("pause");
                system("cls");
                break;
            case 7:
                system("cls");
                cout << "======================================" << endl;
                cout << "  CANTIDAD DE PRODUCTOS REGISTRADOS" << endl ;
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
