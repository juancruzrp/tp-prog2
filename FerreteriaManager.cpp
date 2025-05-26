#include <iostream>
#include "Producto.h"
#include "FerreteriaManager.h"
using namespace std;


    /// PENSAR VALIDACIONES
void FerreteriaManager::cargarProducto(){
    int codProducto, stock;
    string nombreProducto, tipoProducto, marca, unidadMedida;
    float precioUnitario;
    Producto producto;

    cout << "Ingrese codigo del producto: " ;
    cin >> codProducto;

    cout << "Ingrese nombre del producto: " ;
    cin.ignore();
    getline(cin, nombreProducto);

    cout << "Ingrese tipo de producto: ";
    getline(cin, tipoProducto);

    cout << "Ingrese precio unitario: ";
    cin >> precioUnitario;

    cout << "Ingrese stock: ";
    cin >> stock;

    producto = Producto(codProducto, nombreProducto, tipoProducto, marca, unidadMedida, precioUnitario, stock);

}
