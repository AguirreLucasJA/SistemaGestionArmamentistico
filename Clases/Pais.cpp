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
void Pais::cargar(int id)
{
    string usuario;
    string clave;
    string descripcion;
    //RECORDA PAIS DERIVA DE ENTIDAD
    setId(id);//le setea el id obtenido con la funcion contar registros A LA PROPIEDAD DE ENTIDAD.

    cout << "CARGANDO ID: " << getId() << endl;//muestra el nuevo id autonumerico

    cout << "MAX 30 CARACTERES -> ING NOMBRE USUARIO: ";
    cin.ignore();// sino se saltea el ingreso del usuario.
    getline(cin, usuario);
    while(!setUsuario(usuario))
    {
        cout << "ERROR SOBREPASO LIMITE DE 30 CARACTERES" << endl;
        system("pause");
        system("cls");
        cout << "REINGRESE USUARIO:";
        getline(cin, usuario);
    }

    cout << "MAX 30 CARACTERES -> ING CLAVE: ";
    getline(cin, clave);
    while(!setClave(clave))
    {
        cout << "ERROR SOBREPASO LIMITE DE 30 CARACTERES" << endl;
        system("pause");
        system("cls");
        cout << "REINGRESE CLAVE:";
        getline(cin, clave);
    }

    cout << "MAX 30 CARACTERES -> ING DESCRIPCION: ";
    getline(cin, descripcion);
    while(!setDescripcion(descripcion))
    {
        cout << "ERROR SOBREPASO LIMITE DE 30 CARACTERES" << endl;
        system("pause");
        system("cls");
        cout << "REINGRESE DESCRIPCION:";
        getline(cin, descripcion);
    }

    setTipoUsuario(1);//SETEO EL TIPO DE USUARIO 1 = CLIENTE/PAIS.
    setEstado(true);// LO PONGO COMO ACTIVO/ NO ELIMINADO.
    _dineroCaja = 0;//LE ESTABLECE POR DEFECTO 0.
}

void Pais::mostrar()
{
    cout << "USUARIO: " << getUsuario() << endl;
    cout << "CLAVE: " << getClave() << endl;
    cout << "DESCRIPCION: " << getDescripcion() << endl;
    cout << "ESTADO: " << getEstado() << endl;
    cout << "ID: " << getId() << endl;
}
