#include "UsuarioXId.h"
#include<cstring>//para utilizar strcpy
using namespace std;//PARA NO ANDAR HACIENDO STD::COUT

//SETTERS
void UsuarioXId::setUsuario(string usuario)
{

    strcpy(_usuario, usuario.c_str());//devuelve el puntero que tiene en la heap

}

void UsuarioXId::setId(int id)
{
    _id = id;
}

//GETTERS
string UsuarioXId::getUsuario()
{
    return _usuario;
}

int UsuarioXId::getId()
{
    return _id;
}
