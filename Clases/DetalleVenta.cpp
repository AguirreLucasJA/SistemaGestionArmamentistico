#include "DetalleVenta.h"
#include <iostream> //para los cout, cin.
#include<cstring>//para utilizar strcpy
using namespace std; //para no andar escribiendo "std::cout"

DetalleVenta::DetalleVenta()
{

    setIdVenta(-1);
    setIdProducto(-1);
    setCantidad(-1);
    setNombreProducto("S/N");
    setPrecioUnitario(-1);
    setPrecioTotal(-1);
}

//SETTERS
void DetalleVenta::setIdVenta(int idVenta)
{
    _idVenta = idVenta;
}

void DetalleVenta::setIdProducto(int idProducto)
{
    _idProducto = idProducto;
}

void DetalleVenta::setCantidad (int cantidad)
{
    _cantidad = cantidad;
}

void DetalleVenta::setNombreProducto(string nombreProducto)
{
    strcpy(_nombreProducto, nombreProducto.c_str());
}

void DetalleVenta::setPrecioUnitario(long long precioUnitario)
{
    _precioUnitario = precioUnitario;
}

void DetalleVenta::setPrecioTotal(long long precioTotal)
{
    _precioTotal = precioTotal;
}

//GETTERS
int DetalleVenta::getIdVenta()
{
    return _idVenta;
}

int DetalleVenta::getIdProducto()
{
    return _idProducto;
}

int DetalleVenta::getCantidad()
{
    return _cantidad;
}

string DetalleVenta::getNombreProducto()
{
    return _nombreProducto;
}

long long  DetalleVenta::getPrecioUnitario()
{
    return _precioUnitario;
}

long long  DetalleVenta::getPrecioTotal()
{
    return _precioTotal;
}

//METODOS
void DetalleVenta::mostrar()
{
    cout << "----------------------" <<endl;
    //cout << "ID VENTA: " << getIdVenta() << endl;
    cout << "ID PRODUCTO: " << getIdProducto() << endl;
    cout << "CANTIDAD: " << getCantidad() << endl;
    cout << "NOMBRE PRODUCTO:  " << getNombreProducto()<< endl;
    cout << "PRECIO UNITARIO: " << getPrecioUnitario() << endl;
    cout << "PRECIO TOTAL: " << getPrecioTotal()<< endl;
}
