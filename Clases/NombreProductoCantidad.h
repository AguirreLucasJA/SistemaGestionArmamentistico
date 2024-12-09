#pragma once
#include <string>//para poder usar string

class NombreProductoCantidad
{

public:
    NombreProductoCantidad() {};

    void setNombre(std::string nombre);
    void setCantidad (int cantidad);

    std::string getNombre();
    int getCantidad();

private:
    char _nombre[30];
    int _cantidad;
};
