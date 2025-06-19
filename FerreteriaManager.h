#pragma once
#include <string>


class FerreteriaManager{
private:

public:
    ///PRODUCTOS
    void cargarProducto();
    void listarCantidadProductos();
    void listarProductos();
    void buscarProductoPorCodigo();
    void buscarProductoPorNombre();
    void buscarProductoPorTipo();
    void modificarPrecioProducto();

    ///PROVEEDORES
    void cargarProveedor();
    void listarCantidadProveedores();
    void listarProveedores();
    void buscarProveedorPorID();
    void buscarProveedorPorNombre();
    void modificarTelefonoProveedor();
    void modificarDireccionProveedor();

    ///VENTAS
    void cargarVenta();
    void listarCantidadVentas();
    void listarVentas();
    void listarDetalleVenta();
    void darAltaVenta();
    void buscarVentaPorFecha();
    void buscarVentaPorProducto();
    void bajaDeVenta();
    std::string convertirAMinusculas(std::string medioPago);

    ///COMPRAS

///COMPRAS
    void cargarCompra();
    void mostrarCompras();
    void listarCantidadCompras();
    void listarCompras();
    void buscarCompraPorFecha();
    void buscarCompraPorProveedor();
    void eliminarCompra();

    ///INFORMES
    void totalGastadoPorAnioMes();
    void listarComprasPendientes();
    void productosConStockBajo();
    void listarProductoMenosVendido();
};
