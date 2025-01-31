#include "Pais.h"
#include <iostream>//PARA LOS COUT
using namespace std;//PARA NO ANDAR HACIENDO STD::COUT

//SETTERS
void Pais::setDineroCaja(long long dineroCaja)
{
    _dineroCaja = dineroCaja;
}

//GETTERS
long long Pais::getDineroCaja()
{
    return _dineroCaja;
}

//METODOS
//
void Pais::cargar(int id)
{
    Entidad::cargar(id, 1);
    setDineroCaja(0);
}

void Pais::mostrar()
{
    Entidad::mostrar();
    cout << "DINERO EN CAJA: " << getDineroCaja() << endl;
}
