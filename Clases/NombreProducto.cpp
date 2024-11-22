#include "NombreProducto.h"
#include<cstring>//para utilizar strcpy
using namespace std;//PARA NO ANDAR HACIENDO STD::COUT

//SETTERS
void NombreProducto::setNombre(string nombre)
{

    strcpy(_nombre, nombre.c_str());//devuelve el puntero que tiene en la heap

}

//GETTERS
string NombreProducto::getNombre()
{
    return _nombre;
}

