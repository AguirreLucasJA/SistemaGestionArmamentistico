#pragma once
#include "Fecha.h"

class Venta
{
public:

    void setId(int id);
    void idCliente(int idCliente);
    void setFecha(Fecha fecha);
    void setCantidadItems (int cantItems);
    void setMontoTotal(long long montoTotal);

    int getId();
    int getIdCliente();
    Fecha getFecha();
    int getCantidadItems();
    long long getMontoTotal();

    void mostrar();

private:
    int _id;
    int _idCliente;
    Fecha _fecha;
    int _cantidadItems;
    long long _montoTotal;
};
