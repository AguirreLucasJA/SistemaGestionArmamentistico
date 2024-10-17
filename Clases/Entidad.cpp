#include "Entidad.h"
#include<cstring>

//SETTERS
void Entidad::setUsuario(char* usuario){
    strcpy(_usuario, usuario);
}

void Entidad::setClave(char* clave){
    strcpy(_clave, clave);
}

void Entidad::setDescripcion(char* descripcion){
    strcpy(_descripcion, descripcion);
}

void Entidad::setTipoUsuario(int tipoUsuario){
    _tipoUsuario = tipoUsuario;
}

void Entidad::setEstado(bool estado){
    _estado = estado;
}

void Entidad::setId(int id){
    _id = id;
}

//GETTERS
char* Entidad::getUsuario(){
    return _usuario;
}

char* Entidad::getClave(){
    return _clave;
}

char* Entidad::getDescripcion(){
    return _descripcion;
}

int Entidad::getTipoUsuario(){
    return _tipoUsuario;
}

bool Entidad::getEstado(){
    return _estado;
}

int Entidad::getId(){
    return _id;
}

