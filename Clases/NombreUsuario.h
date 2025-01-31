#pragma once
#include <string>//para poder usar string

class NombreUsuario
{

public:
    NombreUsuario() {};

    void setUsuario(std::string usuario);

    std::string getUsuario();

private:
    char _usuario[30];
};
