#pragma once
#include <string>//para poder usar string

class Validar
{
public:
bool esStringValido(std::string cadena, int tam);
bool esNombreUsuarioValido(std::string nombreUsuario);
bool esNombreProductoValido(std::string nombreProducto);
bool esRangoValido(int minimo, int maximo, int numero);

private:

};


