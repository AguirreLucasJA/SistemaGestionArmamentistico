#include "Pais.h"
#include <string>
#include <cstring>//PARA STRCPY
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
void Pais::cargar(int _Id)
{
    char aux[30];
    //RECORDA PAIS DERIVA DE ENTIDAD
    Entidad::setId(_Id);//le setea el id obtenido con la funcion contar registros A LA PROPIEDAD DE ENTIDAD.
    cout << "CARGANDO ID: " << Entidad::getId() << endl;//muestra el nuevo id autonumerico

    cout << "ING NOMBRE CLIENTE PAIS: ";
    cin >> aux;
    //COMO PAIS DERIVA DE ENTIDAD hace uso de sus metodos para setear las propiedades de entidad.
    Entidad::setUsuario(aux);

    cout << "ING CLAVE: ";
    cin >> aux;
    Entidad::setClave(aux);

    cout << "ING DESCRIPCION: ";
    cin >> aux;
    Entidad::setDescripcion(aux);

    Entidad::setTipoUsuario(1);//SETEO EL TIPO DE USUARIO 1 = CLIENTE/PAIS.
    Entidad::setEstado(true);// LO PONGO COMO ACTIVO/ NO ELIMINADO.
    _dineroCaja = 0;//LE ESTABLECE POR DEFECTO 0.
}
