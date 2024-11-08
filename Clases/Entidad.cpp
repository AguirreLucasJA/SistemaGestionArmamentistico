#include "Entidad.h"
#include<cstring>//para utilizar strcpy
#include "Validar.h"
#include <iostream>//PARA LOS COUT
using namespace std;//PARA NO ANDAR HACIENDO STD::COUT


//SETTERS
void Entidad::setUsuario(string usuario)
{

    strcpy(_usuario, usuario.c_str());//devuelve el puntero que tiene en la heap

}

void Entidad::setClave(string clave)
{
    strcpy(_clave, clave.c_str());
}

void Entidad::setDescripcion(string descripcion)
{

    strcpy(_descripcion, descripcion.c_str());

}

void Entidad::setTipoUsuario(int tipoUsuario)
{
    _tipoUsuario = tipoUsuario;
}

void Entidad::setEstado(bool estado)
{
    _estado = estado;
}

void Entidad::setId(int id)
{
    _id = id;
}

//GETTERS
string Entidad::getUsuario()
{
    return _usuario;
}

string Entidad::getClave()
{
    return _clave;
}

string Entidad::getDescripcion()
{
    return _descripcion;
}

int Entidad::getTipoUsuario()
{
    return _tipoUsuario;
}

bool Entidad::getEstado()
{
    return _estado;
}

int Entidad::getId()
{
    return _id;
}

//METODOS

void Entidad::cargar(int id, int tipoUsuario)
{
    //TODO: HACER LA CLASE INTERMEDIA + SU CLASE ARCHIVO PARA VALIDAR USUARIO.
    /*ArchivoPais archPais;*/
    Validar validar;
    string usuario;
    string clave;
    string descripcion;

    setId(id);//le setea el id autonumerico obtenido

    cout << "CARGANDO ID: " << getId() << endl;//muestra el nuevo id autonumerico

    cout << "MAX 30 CARACTERES -> ING NOMBRE USUARIO: ";
    cin.ignore();// sino se saltea el ingreso del usuario.
    getline(cin, usuario);
    while(!validar.esStringValido(usuario,30) /*|| archPais.buscarXUsuario(usuario) != -1*/)
    {
        cout << "ERROR AL CARGAR USUARIO" << endl;
        system("pause");
        system("cls");
        cout << "MAX 30 CARACTERES -> REINGRESE UN USUARIO DISTINTO:";
        getline(cin, usuario);
    }
    setUsuario(usuario);

    cout << "MAX 30 CARACTERES -> ING CLAVE: ";
    getline(cin, clave);
    while(!validar.esStringValido(clave,30))
    {
        cout << "ERROR SOBREPASO LIMITE DE 30 CARACTERES" << endl;
        system("pause");
        system("cls");
        cout << "REINGRESE CLAVE:";
        getline(cin, clave);
    }
    setClave(clave);

    cout << "MAX 30 CARACTERES -> ING DESCRIPCION: ";
    getline(cin, descripcion);
    while(!validar.esStringValido(descripcion,30))
    {
        cout << "ERROR SOBREPASO LIMITE DE 30 CARACTERES" << endl;
        system("pause");
        system("cls");
        cout << "REINGRESE DESCRIPCION:";
        getline(cin, descripcion);
    }
    setDescripcion(descripcion);

    setTipoUsuario(tipoUsuario);//SETEA EL TIPO DE USUARIO  0=ADMIN /1 = PAIS.
    setEstado(true);// LO PONGO COMO ACTIVO/ NO ELIMINADO.
}

void Entidad::mostrar()
{
    cout << "ID: " << getId() << endl;
    cout << "USUARIO: " << getUsuario() << endl;
    cout << "CLAVE: " << getClave() << endl;
    cout << "DESCRIPCION: " << getDescripcion() << endl;
    cout << "TIPO DE USUARIO: " << ((getTipoUsuario() == 0) ? "ADMIN" : (getTipoUsuario() == 1 ? "PAIS" : "DESCONOCIDO")) << endl;
    cout << "ESTADO: " << (getEstado() ? "ACTIVO" : "ELIMINADO") << endl;
}

