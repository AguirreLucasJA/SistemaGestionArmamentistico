#pragma once
#include <string>//para poder usar string

class NombreUsuario
{
public:
    NombreUsuario() {};

    void setUsuario(std::string usuario);
    void setId(int id);

    std::string getUsuario();
    int getId();

private:
    char _usuario[30];
    int _id;
};
