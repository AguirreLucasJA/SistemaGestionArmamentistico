#include "Entidad.h"
#include<cstring>

//SETTERS
void Entidad::setUsuario(string usuario)
{
    if(usuario.size() < sizeof(_usuario))
    {
        strcpy(_usuario, usuario.c_str());
    }
}

void Entidad::setClave(string clave)
{
    if(clave.size() < sizeof(_clave))
    {
        strcpy(_clave, clave.c_str());
    }
}

void Entidad::setDescripcion(string descripcion)
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
string Entidad::getUsuario()
{
    return _usuario;
}

string Entidad::getClave()
{
    return _clave;
}

string Entidad::getDescripcion()
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

