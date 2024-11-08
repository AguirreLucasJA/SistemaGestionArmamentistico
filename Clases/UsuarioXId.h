#pragma once
#include <string>//para poder usar string

class UsuarioXId
{

public:
    UsuarioXId() {};

    void setId(int id);
    void setUsuario(std::string usuario);

    int getId();
    std::string getUsuario();

private:
    int _id;
    char _usuario[30];
};
