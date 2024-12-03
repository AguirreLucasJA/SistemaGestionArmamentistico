#include "Venta.h"
#include <iostream> //para los cout, cin.
using namespace std; //para no andar escribiendo "std::cout"

//SETTERS
void Venta::setId(int id)
{
    _id = id;
}

void Venta::setIdCliente (int idCliente)
{
    _idCliente = idCliente;
}

void Venta::setFecha (Fecha fecha)
{
    _fecha = fecha;
}

void Venta::setCantidadItems (int cantItems)
{
    _cantidadItems = cantItems;
}

void Venta::setMontoTotal(long long  montoTotal)
{
    _montoTotal = montoTotal;
}

//GETTERS
int Venta::getId()
{
    return _id;
}

int Venta::getIdCliente()
{
    return _idCliente;
}

Fecha Venta::getFecha()
{
    return _fecha;
}

int Venta::getCantidadItems()
{
    return _cantidadItems;
}

long long Venta::getMontoTotal()
{
    return _montoTotal;
}

//METODOS

void Venta::mostrar()
{

    cout << "------------------------------------------------------------"<<endl;
    cout << "ID: " << getId() << endl;
    cout << "ID CLIENTE: " << getIdCliente() << endl;
    cout << "FECHA: " << getFecha().toString() << endl;
    cout <<"CANTIDAD DE ITEMS: " << getCantidadItems() << endl;
    cout << "MONTO TOTAL: " << getMontoTotal()<< endl;
}
