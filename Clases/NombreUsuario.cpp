#include "NombreUsuario.h"
#include<cstring>//para utilizar strcpy
using namespace std;//PARA NO ANDAR HACIENDO STD::COUT

//SETTERS
void NombreUsuario::setUsuario(string usuario)
{

    strcpy(_usuario, usuario.c_str());//devuelve el puntero que tiene en la heap

}

//GETTERS
string NombreUsuario::getUsuario()
{
    return _usuario;
}

