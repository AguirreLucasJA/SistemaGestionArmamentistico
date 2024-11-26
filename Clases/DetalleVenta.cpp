#include "DetalleVenta.h"
#include <iostream> //para los cout, cin.
#include<cstring>//para utilizar strcpy
using namespace std; //para no andar escribiendo "std::cout"


//SETTERS
void DetalleVenta::setId (int id)
{
    _id = id;

}
void DetalleVenta::setidProducto (int idProducto)
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


int DetalleVenta::getId ()
{
    return _id;
}

int DetalleVenta::getIdProducto()
{

    return _idProducto;
}

int DetalleVenta::getCantidad()
{
    return _cantidad;
}

/*Fecha Venta::getFecha (){
return _fecha;

}
*/
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
    cout << "ID VENTA: " << getId () << endl;
    cout << "ID PRODUCTO " << getIdProducto () << endl;
    cout <<"CANTIDAD: " << getCantidad() << endl;
    cout << "DESCRIPCIÓN DEL PRODUCTO:  " << getDescripcion()<< endl;
    cout << "PRECIO UNITARIO: " << getPrecioUnitario () << endl;
    cout << "PRECIO TOTAL: " << getPrecioTotal ()<< endl;

}




