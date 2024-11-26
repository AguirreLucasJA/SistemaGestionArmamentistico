#include "DetalleVenta.h"
#include <iostream> //para los cout, cin.
#include<cstring>//para utilizar strcpy
using namespace std; //para no andar escribiendo "std::cout"


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

void DetalleVenta::setDescripcion (string descripcion)
{
    strcpy(_descripcion, descripcion.c_str());
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

string DetalleVenta::getDescripcion()
{
    return _descripcion;
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
    cout << "------------------------------------------------------------"<<endl;
    cout << "ID VENTA: " << getIdVenta() << endl;
    cout << "ID PRODUCTO: " << getIdProducto() << endl;
    cout << "CANTIDAD: " << getCantidad() << endl;
    cout << "DESCRIPCION:  " << getDescripcion()<< endl;
    cout << "PRECIO UNITARIO: " << getPrecioUnitario() << endl;
    cout << "PRECIO TOTAL: " << getPrecioTotal()<< endl;
}
