#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include "FerreteriaManager.h"
#include "Producto.h"
#include "ProductoArchivo.h"
#include "Proveedor.h"
#include "ProveedorArchivo.h"
#include "Venta.h"
#include "VentaArchivo.h"
#include "DetalleVentaArchivo.h"
#include "Compra.h"
#include "CompraArchivo.h"
#include "DetalleCompra.h"
#include "DetalleCompraArchivo.h"
#include "Fecha.h"
using namespace std;


    /// PENSAR SI AGREGAR VALIDACIONES
                                         ///FUNCIONES PARA PRODUCTOS///
void FerreteriaManager::cargarProducto(){
    int codProducto, stock;
    string nombreProducto, tipoProducto, marca, unidadMedida;
    float precioUnitario;
    Producto producto;
    ProductoArchivo productoArchivo;

    ///se pide un codigo de producto,si se ingresa algo que no sea un entero
    ///se vuelve a pedir el ingreso hasta que sea correcto.
    ///cin.clear() limpia el estado del error
    ///cin.ignore() ignora hasta 15 caracteres o hasta un espacio('\n')
    cout << "Ingrese codigo del producto: " ;
    while(!(cin >> codProducto)){
    cin.clear();
    cin.ignore(15,'\n');
    cout << "Ingrese nuevamente el codigo del producto: " ;
    }
    cout << "Ingrese nombre del producto: " ;
    cin.ignore();
    getline(cin, nombreProducto);

    cout << "Ingrese tipo de producto: ";
    getline(cin, tipoProducto);

    cout << "Ingrese marca del producto: ";
    getline(cin, marca);

    cout << "Ingrese unidad de medida del producto: ";
    getline(cin, unidadMedida);

    cout << "Ingrese precio unitario: ";
    cin >> precioUnitario;

    cout << "Ingrese stock: ";
    cin >> stock;

    producto = Producto(codProducto, nombreProducto, tipoProducto, marca, unidadMedida, precioUnitario, stock);



    if (productoArchivo.guardarProducto(producto)){
        cout << "Se guardo correctamente";
    }
    else {
        cout << "Hubo un error al cargar el producto.";}


}

void FerreteriaManager::listarCantidadProductos(){
    ProductoArchivo productoArchivo;
    int cantidadProductos;

    cantidadProductos = productoArchivo.getCantidadRegistros();

    cout << "Cantidad de productos registrados: " << cantidadProductos << endl;
}


void FerreteriaManager::listarProductos() {
    ProductoArchivo productoArchivo;
    Producto registro;
    int cantidadProductos =productoArchivo.getCantidadRegistros();

    for(int i=0 ; i<cantidadProductos ; i++ ){

        registro = productoArchivo.leer(i);
        cout<< registro.toCSV() << endl;
    }


    FILE* archivo = fopen("productos.dat", "rb");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }


}

void FerreteriaManager::buscarProductoPorCodigo() {
    ProductoArchivo productoArchivo;
    Producto registro;
    int buscarCodigo;
    int cantidadProductos = productoArchivo.getCantidadRegistros();

    cout<<"Ingrese el codigo de producto que desea buscar:";
    cin >> buscarCodigo;

    for(int i=0; i<cantidadProductos ; i++){

        registro = productoArchivo.leer(i);
        if(registro.getCodProducto()== buscarCodigo){

        cout <<"Nombre del producto: " << registro.getNombreProducto() << endl;
        cout <<"Tipo de producto: " << registro.getTipoProducto() << endl;
        cout <<"Marca del producto: " << registro.getMarca() << endl;
    }

}
return;
}

void FerreteriaManager::buscarProductoPorNombre(){
    ProductoArchivo productoArchivo;
    Producto registro;
    std::string buscarNombre;
    int cantidadProductos = productoArchivo.getCantidadRegistros();

    cout<<"Ingrese el nombre de producto que desea buscar:";
    cin >> buscarNombre;

    for(int i=0; i<cantidadProductos ; i++){

        registro = productoArchivo.leer(i);
        if(registro.getNombreProducto()== buscarNombre){

        cout <<"codigo del producto: " << registro.getCodProducto() << endl;
        cout <<"Tipo de producto: " << registro.getTipoProducto() << endl;
        cout <<"Marca del producto: " << registro.getMarca() << endl;
    }

}
return;
}

void FerreteriaManager::buscarProductoPorTipo(){
    ProductoArchivo productoArchivo;
    Producto registro;
    std::string buscarTipo;
    int cantidadProductos = productoArchivo.getCantidadRegistros();

    cout<<"Ingrese el nombre de producto que desea buscar: ";
    cin >> buscarTipo;

    for(int i=0; i<cantidadProductos ; i++){

        registro = productoArchivo.leer(i);
        if(registro.getTipoProducto()== buscarTipo){

        cout <<"codigo del producto: " << registro.getCodProducto() << endl;
        cout <<"Nombre de producto: " << registro.getNombreProducto() << endl;
        cout <<"Marca del producto: " << registro.getMarca() << endl;
    }

    }
    return;
}

void FerreteriaManager::modificarPrecioProducto(){
    int idProducto,posicion;
    float nuevoPrecio;
    cout<< "Ingrese el id del producto a modificar:";
    cin >> idProducto;

    ProductoArchivo archivo;
    posicion = archivo.buscarProducto(idProducto);

    if(posicion >=0){
        Producto registro = archivo.leer(posicion);
        cout <<"Precio unitario actual:"<<registro.getPrecioUnitario()<<endl;
        cout<<"Ingrese el nuevo precio unitario:";
        cin >> nuevoPrecio;
        registro.setPrecioUnitario(nuevoPrecio);
        if(archivo.guardarProducto(registro, posicion)){
            cout<<"Registro modificado con exito."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro."<<endl;
        }
    }
    else{
        cout<<"No existe el id del producto."<<endl;
    }

}

                                         ///FUNCIONES PARA PROVEEDORES///
void FerreteriaManager::cargarProveedor(){
    int idProveedor;
    string nombreProveedor, telefono, mail, direccion;
    Proveedor proveedor;
    ProveedorArchivo proveedorArchivo;

    cout << "Ingrese codigo del proveedor: " ;
    cin >> idProveedor;

    cout << "Ingrese nombre del proveedor: " ;
    cin.ignore();
    getline(cin, nombreProveedor);

    cout << "Ingrese un telefono de contacto: ";
    getline(cin, telefono);

    cout << "Ingrese un mail: ";
    getline(cin, mail);

    cout << "Ingrese la direccion del proveedor: ";
    getline(cin, direccion);

  proveedor = Proveedor( idProveedor, nombreProveedor, telefono, mail, direccion);

  if (proveedorArchivo.guardarProveedor(proveedor)){
        cout << "Se guardo correctamente";
    }
    else {
        cout << "Hubo un error al cargar el proveedor.";}
}

void FerreteriaManager::listarCantidadProveedores(){
    ProveedorArchivo proveedorArchivo;
    int cantidadProveedores;

    cantidadProveedores = proveedorArchivo.getCantidadRegistros();

    cout << "Cantidad de proveedores registrados: " << cantidadProveedores << endl;

}

void FerreteriaManager::listarProveedores() {
    ProveedorArchivo proveedorArchivo;
    Proveedor registro;
    int cantidadProveedores =proveedorArchivo.getCantidadRegistros();

    for(int i=0 ; i<cantidadProveedores ; i++ ){

        registro = proveedorArchivo.leer(i);
        cout<< registro.toCSV() << endl;
    }


    FILE* archivo = fopen("proveedores.dat", "rb");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }


}

void FerreteriaManager::buscarProveedorPorID() {
    ProveedorArchivo proveedorArchivo;
    Proveedor registro;
    int buscarCodigo;
    int cantidadProveedores = proveedorArchivo.getCantidadRegistros();

    cout<<"Ingrese el codigo del proveedor que desea buscar: ";
    cin >> buscarCodigo;

    for(int i=0; i<cantidadProveedores ; i++){

        registro = proveedorArchivo.leer(i);
        if(registro.getIdProveedor()== buscarCodigo){

        cout <<"Nombre del proveedor: " << registro.getNombreProveedor() << endl;
        cout <<"Tel de contacto: " << registro.getTelefono() << endl;
        cout <<"Direccion del proveedor: " << registro.getDireccion()<< endl;
    }

}
return;
}

void FerreteriaManager::buscarProveedorPorNombre(){
    ProveedorArchivo proveedorArchivo;
    Proveedor registro;
    std::string buscarNombre;
    int cantidadProveedores =  proveedorArchivo.getCantidadRegistros();

    cout<<"Ingrese el nombre de producto que desea buscar:";
    cin >> buscarNombre;

    for(int i=0; i<cantidadProveedores ; i++){

        registro = proveedorArchivo.leer(i);
        if(registro.getNombreProveedor()== buscarNombre){

        cout <<"codigo del proveedor: " << registro.getIdProveedor() << endl;
        cout <<"Tel de contacto: " << registro.getTelefono() << endl;
        cout <<"Direccion del proveedor: " << registro.getDireccion() << endl;
    }

}

return;
}
void FerreteriaManager::modificarTelefonoProveedor(){
    int idProveedor,posicion;
    string nuevoTelefono;
    cout<< "Ingresar el id del proveedor a modificar:";
    cin >> idProveedor;

    ProveedorArchivo archivo;
    posicion = archivo.buscarProveedor(idProveedor);

    if(posicion >=0){
        Proveedor registro = archivo.leer(posicion);
        cout<<"Ingrese el nuevo numero de telefono:";
        cin >> nuevoTelefono;
        registro.setTelefono(nuevoTelefono);
        if(archivo.guardarProveedor(registro, posicion)){
            cout<<"Registro modificado con exito."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro."<<endl;
        }
    }
    else{
        cout<<"No existe el id del proveedor."<<endl;
    }

}

void FerreteriaManager::modificarDireccionProveedor(){
    int idProveedor,posicion;
    string nuevaDireccion;
    cout<< "Ingresar el id del proveedor a modificar:";
    cin >> idProveedor;

    ProveedorArchivo archivo;
    posicion = archivo.buscarProveedor(idProveedor);

    if(posicion >=0){
        Proveedor registro = archivo.leer(posicion);
        cout<<"Ingrese la nueva direccion del proveedor:";
        cin.ignore();
        getline(cin,nuevaDireccion);
        registro.setDireccion(nuevaDireccion);
        if(archivo.guardarProveedor(registro, posicion)){
            cout<<"Registro modificado con exito."<<endl;
        }
        else{
            cout<<"Hubo un error al modificar el registro."<<endl;
        }
    }
    else{
        cout<<"No existe el id del proveedor."<<endl;
    }

}


                                         ///FUNCIONES PARA VENTAS///

void FerreteriaManager::cargarVenta(){
    int idVenta, codProducto, cantidad;
    float importeTotal, precioUnitario, subtotal;
    string medioPago, pago;
    bool estado=1;
    FerreteriaManager manager;
    Producto producto, prod;
    Fecha fechaVenta;
    Venta venta, reg;
    ProductoArchivo productoArchivo;
    VentaArchivo ventaArchivo;
    DetalleVenta detalleVenta;
    DetalleVentaArchivo detalleVentaArchivo;
    int cantidadProductos = productoArchivo.getCantidadRegistros();


    cout << "Ingrese ID de venta: " ;
    cin >> idVenta;

    while(idVenta<=0 || idVenta>40){
        cout << "ID DE VENTA INVALIDA. VUELVA A INGRESAR ID DE VENTA. " << endl ;
        system("pause");
        system("cls");
        cout << "Ingrese ID de venta: " ;
        cin >> idVenta;
    }

    int posV = ventaArchivo.buscar(idVenta);
        if (posV >=0){
            Venta venV = ventaArchivo.leer(posV);
            if (venV.getIdVenta() == idVenta){
                medioPago = venV.getMedioPago();
                fechaVenta = venV.getFechaVenta();

                cout << "Medio de pago: " << medioPago << endl;
                venV.getFechaVenta().mostrar();
                cout << endl;
            }
        }

        else{
            cout << "Ingrese medio de pago: " ;
            cin.ignore();
            getline(cin, medioPago);
            pago = manager.convertirAMinusculas(medioPago);

        ///validar medio de pago
            while(pago != "efectivo" && pago!= "debito" && pago!= "qr" && pago!= "credito" && pago!= "transferencia"){
                cout << "MEDIO DE PAGO INCORRECTO. VUELVA A INGRESAR MEDIO DE PAGO." << endl ;
                cout << "Medios de pago disponibles: Efectivo - Credito - Debito - Transferencia - QR" << endl;
                system("pause");
                system("cls");
                cout << "Ingrese medio de pago: " ;
                getline(cin, medioPago);
                pago = manager.convertirAMinusculas(medioPago);
            }

            fechaVenta.cargar();
        }

    cout << "Ingrese codigo del producto: " ;
    cin >> codProducto;
        while(codProducto<=0 || codProducto>40){
            cout << "CODIGO INVALIDO. VUELVA A INGRESAR CODIGO DEL PRODUCTO." << endl ;
            system("pause");
            system("cls");
            cout << "Ingrese Codigo: " ;
            cin >> codProducto;
        }

    cout << "Ingrese cantidad: " ;
    cin >> cantidad;
        while(cantidad<=0){
            cout << "CANTIDAD INVALIDA. VUELVA A INGRESAR LA CANTIDAD." << endl ;
            system("pause");
            system("cls");
            cout << "Ingrese Cantidad: " ;
            cin >> cantidad;
        }


    ///descuenta la cantidad vendida del stock
    int pos = productoArchivo.buscarProducto(codProducto);
    producto = productoArchivo.leer(pos);
    int cant = producto.getStock() - cantidad;
    producto.setStock(cant);
    productoArchivo.guardarProducto(producto ,pos);


    /// busca en archivo producto y asigna precio unitario
    for(int i=0; i<cantidadProductos ; i++){
        producto = productoArchivo.leer(i);

        if(producto.getCodProducto() == codProducto){
            precioUnitario = producto.getPrecioUnitario();
        }
    }

    subtotal = precioUnitario * cantidad ;

    importeTotal = subtotal;

    ///Si el ID venta existe, le suma el subtotal al importe total de la venta.
    int posVen = ventaArchivo.buscar(idVenta);
    if (posVen >=0 ){
        Venta ven = ventaArchivo.leer(posVen);
        importeTotal = ven.getImporteTotal() + subtotal;
        ven.setImporteTotal(importeTotal);
        ventaArchivo.guardar(ven, posVen);
    }
    else {
        venta = Venta(idVenta, importeTotal, medioPago, fechaVenta, estado);
        if (ventaArchivo.guardar(venta)){
           ///cout << "Se guardo correctamente " << endl;
        }
        else {
            cout << "Hubo un error al cargar la venta." << endl;
        }
    }


    detalleVenta = DetalleVenta(idVenta, codProducto, precioUnitario, cantidad, subtotal, estado);


    if (detalleVentaArchivo.guardar(detalleVenta)){
        ///cout << "Se guardo correctamente." << endl;
    }

    else {
        cout << "Hubo un error al cargar la venta." << endl;
    }

}

/// ------------------------------------------------------------------------------------------------------------------------

void FerreteriaManager::listarCantidadVentas(){
    VentaArchivo ventaArchivo;
    int cantidadVentas;
    Venta venta;

    cantidadVentas = ventaArchivo.getCantidadRegistros();

    for (int x=0; x<cantidadVentas;x++){
        venta = ventaArchivo.leer(x);

        if(venta.getEstado()==0){
            cantidadVentas--;
        }
    }

        cout << "Cantidad de ventas registradas: " << cantidadVentas << endl;
}

/// ------------------------------------------------------------------------------------------------------------------------

void FerreteriaManager::listarVentas(){
    Fecha fechaVenta;
    DetalleVenta detalleVenta;
    Venta venta;
    DetalleVentaArchivo detalleVentaArchivo;
    VentaArchivo ventaArchivo;
    int cantidadVentas = ventaArchivo.getCantidadRegistros();
    bool bv=0;

    for (int x=0; x<cantidadVentas;x++){
        venta = ventaArchivo.leer(x);

        if(venta.getEstado() == 1){
            cout << "Id Venta: " << venta.getIdVenta();
            cout << " | " ;
            cout << "Medio de pago: " << venta.getMedioPago();
            cout << " | " ;
            venta.getFechaVenta().mostrar();
            cout << " | " ;
            cout << "Importe Total: " << venta.getImporteTotal();
            cout << " | " ;
            cout << endl;
            bv=1;
        }
    }

    if (bv == 0){
        cout << "No hay ventas registradas." << endl ;
    }
}

/// ------------------------------------------------------------------------------------------------------------------------

void FerreteriaManager::listarDetalleVenta(){
    DetalleVentaArchivo detalleVentaArchivo;
    DetalleVenta detalleVenta;
    int idVenta;
    int cantidadVentas = detalleVentaArchivo.getCantidadRegistros();
    bool bd=0;

    cout << "Ingrese ID de venta a listar: ";
    cin >> idVenta;

    for(int i=0; i<cantidadVentas ; i++){
        detalleVenta = detalleVentaArchivo.leer(i);

        if(detalleVenta.getIdVenta() == idVenta && detalleVenta.getEstado()== 1){
            cout << "Id Venta: " << detalleVenta.getIdVenta() << " | " ;
            cout << "Codigo producto: " << detalleVenta.getCodProducto() << " | " ;
            cout << "Precio unitario: " << detalleVenta.getPrecioUnitario() << " | " ;
            cout << "Cantidad: " << detalleVenta.getCantidad() << " | " ;
            cout << "Subtotal: " << detalleVenta.getSubtotal() << " | " << endl;
            bd = 1;
        }
    }

    if(bd==0){
        cout << "No hay ventas registradas con ese ID." << endl;
    }
}

/// ------------------------------------------------------------------------------------------------------------------------

void FerreteriaManager::buscarVentaPorFecha(){
    Fecha fechaVenta;

    fechaVenta.cargar();

}

/// ------------------------------------------------------------------------------------------------------------------------

void FerreteriaManager::buscarVentaPorProducto(){
    int codProducto;
    Venta venta;
    VentaArchivo ventaArchivo;
    DetalleVenta detalleVenta;
    DetalleVentaArchivo detalleVentaArchivo;
    Producto producto;
    ProductoArchivo productoArchivo;
    int cantidadVentas = detalleVentaArchivo.getCantidadRegistros();
    int cantidad[40]{};

    cout << "Ingrese Codigo del producto: ";
    cin >> codProducto;

    while(codProducto<=0 || codProducto>40){
            cout << "CODIGO INVALIDO. VUELVA A INGRESAR CODIGO DEL PRODUCTO." << endl ;
            system("pause");
            system("cls");
            cout << "Ingrese Codigo: " ;
            cin >> codProducto;
    }

    int pos = productoArchivo.buscarProducto(codProducto);
    if(pos >=0){
        producto = productoArchivo.leer(pos);
        cout << "Nombre del producto: " << producto.getNombreProducto() << endl;
        cout << "Tipo producto: " << producto.getTipoProducto() << endl;
        cout << "Marca del producto: " << producto.getMarca();
        cout << "Precio unitario: " << producto.getPrecioUnitario() << endl;
    }

    int poss = detalleVentaArchivo.buscar(codProducto);
    if(poss >=0){
        detalleVenta = detalleVentaArchivo.leer(poss);
            if (detalleVenta.getCodProducto() == codProducto){
                for(int x=0; x<cantidadVentas ; x++){
                cantidad[x] += detalleVenta.getCantidad();
                }
                cout << "Cantidad vendida: " << cantidad[codProducto-1] << endl;
            }
    }
}
/// ------------------------------------------------------------------------------------------------------------------------

void FerreteriaManager::bajaDeVenta(){
    int idVenta;
    VentaArchivo ventaArchivo;
    DetalleVentaArchivo detalleVentaArchivo;
    DetalleVenta detalleVenta;
    Venta venta;
    int cantidadVentas = detalleVentaArchivo.getCantidadRegistros();

    cout << "Ingrese ID de venta a eliminar: " ;
    cin >> idVenta;

        while(idVenta<=0 || idVenta>30){
            cout << "ID DE VENTA INVALIDA. VUELVA A INGRESAR ID DE VENTA. " << endl ;
            system("pause");
            system("cls");
            cout << "Ingrese ID de venta: " ;
            cin >> idVenta;
        }

    int pos = ventaArchivo.buscar(idVenta);

    for (int x=0;x <cantidadVentas;x++){
        detalleVenta = detalleVentaArchivo.leer(x);

        if(detalleVenta.getIdVenta() == idVenta){
            detalleVenta.setEstado(0);
            detalleVentaArchivo.guardar(detalleVenta, x);
        }
    }

    if( pos >=0){
        venta = ventaArchivo.leer(pos);
        venta.setEstado(0);

        if(ventaArchivo.guardar(venta, pos)){
            cout << "Venta eliminada correctamente."<< endl;
            }
        else {
            cout << "Hubo un error al eliminar la venta. Intente nuevamente";
        }
    }

}

/// ------------------------------------------------------------------------------------------------------------------------

std::string FerreteriaManager::convertirAMinusculas(std::string texto) {
    std::transform(texto.begin(), texto.end(), texto.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return texto;
}

                                         ///FUNCIONES PARA COMPRAS///

    void FerreteriaManager::cargarCompra() {
    int idCompra, idProveedor, numeroFactura, cantidadDetalles;
    string tipoFactura;
    float importeTotal = 0, subtotal;
    bool pagado;
    Fecha f; // Fecha de la compra
    CompraArchivo archivoCompra;
    DetalleCompraArchivo archivoDetalles;

    // INGRESO DE DATOS
    cout << "Ingrese ID de la compra: ";
    cin >> idCompra;

    if (idCompra <= 0) {
        cout << "ID de compra invalido. Debe ser un numero positivo." << endl;
        return;
    }

    cout << "Ingrese ID del proveedor: ";
    cin >> idProveedor;

    if (idProveedor <= 0) {
        cout << "ID de proveedor invalido. Debe ser un numero positivo." << endl;
        return;
    }

    // Cargar fecha
    f.cargar();

    cout << "Ingrese tipo de factura (A, B o C): ";
    cin >> tipoFactura;

    // Convertir a mayúsculas
    for (char &c : tipoFactura) {
        c = toupper(c);
    }

    if (tipoFactura != "A" && tipoFactura != "B" && tipoFactura != "C") {
        cout << "Tipo de factura invalido. Debe ser A, B o C." << endl;
        return;
    }

    cout << "Ingrese número de factura: ";
    cin >> numeroFactura;

    if (numeroFactura <= 0) {
        cout << "Número de factura invalido. Debe ser un numero positivo." << endl;
        return;
    }

    cout << "La compra fue pagada (1 = SI, 0 = NO): ";
    cin >> pagado;

    if (pagado != 0 && pagado != 1) {
        cout << "Valor invalido para 'Pagado'. Debe ser 0 o 1." << endl;
        return;
    }

    cout << "Cantidad de productos : ";
    cin >> cantidadDetalles;

    // INGRESO DE DETALLES
    for (int i = 0; i < cantidadDetalles; i++) {
        int codProducto, cantidad;
        float precioUnitario;

        cout << "----- Producto " << (i + 1) << " -----" << endl;

        cout << "Ingrese codigo del producto: ";
        cin >> codProducto;

        cout << "Ingrese precio unitario: ";
        cin >> precioUnitario;

        if (precioUnitario <= 0) {
            cout << "Precio unitario invalido. Debe ser mayor que cero." << endl;
            continue;
        }

        cout << "Ingrese cantidad: ";
        cin >> cantidad;

        if (cantidad <= 0) {
            cout << "Cantidad invalida. Debe ser mayor que cero." << endl;
            continue;
        }

        subtotal = precioUnitario * cantidad;

        // Crear y guardar detalle
        DetalleCompra detalle(idCompra, codProducto, precioUnitario, cantidad);
        importeTotal += detalle.getSubtotal();

        if (archivoDetalles.guardarDetalle(detalle)) {
            cout << "Detalle guardado correctamente." << endl;
        } else {
            cout << "Error al guardar el detalle." << endl;
        }
    }

    // Crear objeto compra con fecha correctamente
    Compra compra(idCompra, idProveedor, f, tipoFactura, numeroFactura, importeTotal, pagado, 1);

    if (archivoCompra.guardarCompra(compra)) {
        cout << "Compra registrada correctamente." << endl;
    } else {
        cout << "Error al registrar la compra." << endl;
    }
}


    void FerreteriaManager::listarCompras() {
    CompraArchivo archivoCompra("compra.dat");
    int cantidad = archivoCompra.getCantidadRegistros();

    if (cantidad == 0) {
        cout << "No hay compras registradas." << endl;
        return;
    }

    cout << "--- LISTADO DE COMPRAS ---" << endl; // Encabezado

    for (int i = 0; i < cantidad; i++) {
        Compra compra = archivoCompra.leer(i);

        cout << "Compra #" << (i + 1) << ":" << std::endl; // Numerar
        cout << "  ID Compra: " << compra.getIdCompra() << endl;
        cout << "  ID Proveedor: " << compra.getIdProveedor() << endl;

        // Imprimir la fecha correctamente
        cout << "  Fecha: " << compra.getDia() << "/" << compra.getMes() << "/" << compra.getAnio() << endl;

        cout << "  Tipo Factura: " << compra.getTipoFactura() << endl;
        cout << "  Nro Factura: " << compra.getNumeroFactura() << endl;
        cout << "  Importe Total: $" << compra.getImporteTotal() << endl;
        cout << "  Pagado: " << (compra.getPagado() ? "SI" : "NO") << endl;
        cout << "------------------------" << endl;
    }
}


void FerreteriaManager::buscarCompraPorFecha() {
    Fecha fechaBuscada;
    cout << "--- BUSCAR COMPRAS POR FECHA ---" << std::endl;
    fechaBuscada.cargar();

    CompraArchivo archivoCompra;
    Compra compra;
    int cantidad = archivoCompra.getCantidadRegistros();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        compra = archivoCompra.leer(i);
        Fecha fechaCompra = compra.getFechaCompra();

        if (fechaCompra.getDia() == fechaBuscada.getDia() &&
            fechaCompra.getMes() == fechaBuscada.getMes() &&
            fechaCompra.getAnio() == fechaBuscada.getAnio()) {

            cout << "------------------------" << endl;
            cout << "ID Compra: " << compra.getIdCompra() << endl;
            cout << "ID Proveedor: " << compra.getIdProveedor() << endl;
            cout << "Fecha: ";
            compra.getFechaCompra().mostrar();
            cout << std::endl;
            cout << "Tipo Factura: " << compra.getTipoFactura() << endl;
            cout << "Numero Factura: " << compra.getNumeroFactura() << endl;
            cout << "Importe Total: $" << compra.getImporteTotal() << endl;
            cout << "Pagado: " << (compra.getPagado() ? "SI" : "NO") << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron compras para la fecha ingresada." << endl;
    }
}

void FerreteriaManager::buscarCompraPorProveedor() {
    CompraArchivo archivoCompra;
    int cantidad = archivoCompra.getCantidadRegistros();
    int idBuscado;
    bool encontrada = false;

    cout << "Ingrese ID del proveedor: ";
    cin >> idBuscado;

    if (cantidad == 0) {
        cout << "No hay compras registradas para ese proveedor." << endl;
        return;
    }

    cout << "--- COMPRAS DEL PROVEEDOR #" << idBuscado << " ---" << endl;

    for (int i = 0; i < cantidad; i++) {
        Compra compra = archivoCompra.leer(i);

        if (compra.getIdProveedor() == idBuscado) {
            encontrada = true;
            cout << "ID Compra: " << compra.getIdCompra() << std::endl;
            cout << "Fecha: ";
            compra.getFechaCompra().mostrar();  // Debe tener bien definida la función mostrar()
            cout << std::endl;
            cout << "Tipo Factura: " << compra.getTipoFactura() << endl;
            cout << "Nro Factura: " << compra.getNumeroFactura() << endl;
            cout << "Importe Total: $" << compra.getImporteTotal() << endl;
            cout << "Pagado: " << (compra.getPagado() ? "SI" : "NO") << endl;
            cout << "-----------------------------" << endl;
        }
    }

    if (!encontrada) {
        std::cout << "No se encontraron compras para ese proveedor." << std::endl;
    }
}

void FerreteriaManager::listarCantidadCompras(){
    CompraArchivo CompraArchivo;
    int cantidadCompras;

    cantidadCompras = CompraArchivo.getCantidadRegistros();

    cout << "Cantidad de compras registradas: " << cantidadCompras << endl;

}

void FerreteriaManager::eliminarCompra() {
    DetalleCompraArchivo archivoDetalle;
    int idCompra;

    cout << "Ingrese ID de compra a eliminar: ";
    cin >> idCompra;

    if (archivoDetalle.eliminar(idCompra)) {
        cout << "Detalles de la compra eliminados correctamente." << endl;//baja logica
    } else {
        cout << "Error al eliminar los detalles." << endl;
    }
}

