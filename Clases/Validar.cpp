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

    if(archNombreUsuario.buscarXUsuario(nombreUsuario) == -1)
    {
        return true;
    }

    return false;
}

bool Validar::esRangoValido(int minimo, int maximo, int numero)
{
    if (numero >= minimo && numero <= maximo)
    {
        return true; // El n�mero est� dentro del rango
    }
    else
    {
        return false; // El n�mero est� fuera del rango
    }
}
