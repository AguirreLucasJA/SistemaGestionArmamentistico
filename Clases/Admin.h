#pragma once

#include "Entidad.h"

class Admin : public Entidad
{
public:
    Admin() {};

    void cargar(int id);
    void mostrar();

private:

};
