#include "Entidad.h"
#include<cstring>//para utilizar strcpy

//SETTERS
void Entidad::setUsuario(std::string usuario)
{
    if(usuario.size() < sizeof(_usuario))
    {
        strcpy(_usuario, usuario.c_str());//devuelve el puntero que tiene en la heap
    }//copia un puntero char dentro del otro puntero char
}

void Entidad::setClave(std::string clave)
{
    if(clave.size() < sizeof(_clave))
    {
        strcpy(_clave, clave.c_str());
    }
}

void Entidad::setDescripcion(std::string descripcion)
{
    if(descripcion.size() < sizeof(_descripcion))
    {
        strcpy(_descripcion, descripcion.c_str());
    }
}

void Entidad::setTipoUsuario(int tipoUsuario)
{
    _tipoUsuario = tipoUsuario;
}

void Entidad::setEstado(bool estado)
{
    _estado = estado;
}

void Entidad::setId(int id)
{
    _id = id;
}

//GETTERS
std::string Entidad::getUsuario()
{
    return _usuario;
}

std::string Entidad::getClave()
{
    return _clave;
}

std::string Entidad::getDescripcion()
{
    return _descripcion;
}

int Entidad::getTipoUsuario()
{
    return _tipoUsuario;
}

bool Entidad::getEstado()
{
    return _estado;
}

int Entidad::getId()
{
    return _id;
}

