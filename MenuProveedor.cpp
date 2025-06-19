#include <iostream>
#include "FerreteriaManager.h"
#include "MenuProveedor.h"
using namespace std;

void MenuProveedor::mostrar(){

    int opcion;
    FerreteriaManager manager;

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
                system("cls");
                cout << "======================================" << endl;
                cout << "       CARGAR NUEVO PROVEEDOR" << endl ;
                cout << "======================================" << endl;
                manager.cargarProveedor();
                ///system("cls");
                cout << "======================================" << endl;
                cout << "    PROVEEDOR CARGADO CORRECTAMENTE" << endl ;
                cout << "======================================" << endl;
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                cout << "======================================" << endl;
                cout << "          LISTAR PROVEEDORES          "   << endl ;
                cout << "======================================" << endl;
                manager.listarProveedores();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                cout << "======================================" << endl;
                cout << "        BUSCAR PROVEEDOR POR ID       " << endl ;
                cout << "======================================" << endl;
                manager.buscarProveedorPorID();
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                cout << "======================================" << endl;
                cout << "      BUSCAR PROVEEDOR POR NOMBRE     " << endl ;
                cout << "======================================" << endl;
                manager.buscarProveedorPorNombre();
                ///system("cls");
                ///system("pause");'
                ///system("cls");
                break;
            case 5:
                system("cls");
                cout << "======================================" << endl;
                cout << "    MODIFICAR TELEFONO DE PROVEEDOR   " << endl ;
                cout << "======================================" << endl;
                manager.modificarTelefonoProveedor();
                ///system("cls");
                cout << "======================================" << endl;
                cout << "     MODIFICACION HECHA CON EXITO     " << endl ;
                cout << "======================================" << endl;
                ///system("pause");
                ///system("cls");
               break;
            case 6:
                system("cls");
                cout << "======================================" << endl;
                cout << "    MODIFICAR DIRECCION DE PROVEEDOR  " << endl ;
                cout << "======================================" << endl;
                manager.modificarDireccionProveedor();
                ///system("cls");
                cout << "======================================" << endl;
                cout << "     MODIFICACION HECHA CON EXITO     " << endl ;
                cout << "======================================" << endl;
                ///system("pause");
                ///system("cls");
                break;
            case 7:
                system("cls");
                cout << "======================================" << endl;
                cout << "  CANTIDAD DE PROVEEDORES REGISTRADOS " << endl ;
                cout << "======================================" << endl;
                manager.listarCantidadProveedores();
                ///system("pause");
                ///system("cls");
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
