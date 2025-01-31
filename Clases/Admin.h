#pragma once

#include "Entidad.h"

class Admin : public Entidad
{
public:

    void setSueldo(float sueldo);

    float getSueldo();

    //void cargar() override;
    //void mostrar() const override;

    void cargar(int id);
    void mostrar();

private:
    float _sueldo;

};
