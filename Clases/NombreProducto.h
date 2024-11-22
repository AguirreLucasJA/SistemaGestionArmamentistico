#pragma once
#include <string>//para poder usar string

class NombreProducto
{

public:
    NombreProducto() {};

    void setNombre(std::string nombre);

    std::string getNombre();

private:
    char _nombre[30];
};
