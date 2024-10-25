#include "Validar.h"
bool Validar::esStringValido(std::string cadena, int tam)
{
    if(cadena.size() < tam)
    {
        return true;
    }
    return false;
}
