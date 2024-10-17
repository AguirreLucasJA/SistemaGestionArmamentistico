#include "Entidad.h"
#include<cstring>

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
