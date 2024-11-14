#include "Validar.h"
#include "ClasesArchivos/ArchivoNombreUsuario.h"
bool Validar::esStringValido(std::string cadena, int tam)
{
    if(cadena.size() < tam)
    {
        return true;
    }
    return false;
}

bool Validar::esUsuarioValido(std::string nombreUsuario)
{
    ArchivoNombreUsuario archNombreUsuario;

    if(archNombreUsuario.buscarXUsuario(nombreUsuario) != -1)
    {
        return true;
    }

    return false;
}
