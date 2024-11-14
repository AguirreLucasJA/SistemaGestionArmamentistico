#pragma once
#include "Entidad.h"

class Pais : public Entidad
{

public:

    void setDineroCaja(long long _DineroCaja);

    long long getDineroCaja();

    void cargar(/*int _Id*/) override;
    void mostrar() const override;

private:
    long long _dineroCaja;

};
