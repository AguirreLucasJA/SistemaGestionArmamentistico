#include "NombreProductoCantidad.h"
#include<cstring>//para utilizar strcpy
using namespace std;//PARA NO ANDAR HACIENDO STD::COUT

//SETTERS
void NombreProductoCantidad::setNombre(string nombre)
{
    strcpy(_nombre, nombre.c_str());//devuelve el puntero que tiene en la heap
}

void NombreProductoCantidad::setCantidad (int cantidad)
{
    _cantidad = cantidad;
}


//GETTERS
string NombreProductoCantidad::getNombre()
{
    return _nombre;
}

int NombreProductoCantidad::getCantidad ()
{
    return _cantidad;
}
