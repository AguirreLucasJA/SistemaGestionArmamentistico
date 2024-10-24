#include "Admin.h"
#include <iostream>//para los cout, cin.
#include<cstring>//para las funciones strcpy
using namespace std;//para no andar escribiendo "std::cout"

//METODOS
void Admin::cargar(int id)
{
    string usuario;
    string clave;
    string descripcion;
    //RECORDA ADMIN DERIVA DE ENTIDAD
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

    setTipoUsuario(0);//SETEO EL TIPO DE USUARIO 0 = ADMINISTRADOR.
    setEstado(true);// LO PONGO COMO ACTIVO/ NO ELIMINADO
}

void Admin::mostrar()
{
    cout << "USUARIO: " << getUsuario() << endl;
    cout << "CLAVE: " << getClave() << endl;
    cout << "DESCRIPCION: " << getDescripcion() << endl;
    cout << "TIPO DE USUARIO: " << getTipoUsuario() << endl;
    cout << "ESTADO: " << getEstado() << endl;
    cout << "ID: " << getId() << endl;
}
