#include "Admin.h"
#include "Validar.h"
#include "ClasesArchivos/ArchivoAdmin.h"
#include <iostream>//para los cout, cin.
using namespace std;//para no andar escribiendo "std::cout"

//SETTERS
void Admin::setSueldo(float sueldo)
{
    _sueldo = sueldo;
}

//GETTERS
float Admin::getSueldo()
{
    return _sueldo;
}

//METODOS
void Admin::cargar()
{

    Validar validar;
    string usuario;
    string clave;
    string descripcion;
    float sueldo;
    ArchivoAdmin ArchAdmin;
    int id;

    id = ArchAdmin.getNuevoId(); //obtiene nuevo ID autonumerico.

    setId(id);//le setea el id autonumerico obtenido

    cout << "CARGANDO ID: " << getId() << endl;//muestra el nuevo id autonumerico

    cout << "MAX 30 CARACTERES -> ING NOMBRE USUARIO: ";
    cin.ignore();// sino se saltea el ingreso del usuario.
    getline(cin, usuario);
    while(!validar.esStringValido(usuario,30) || validar.esUsuarioValido(usuario) || usuario == "admin")
    {

        if(!validar.esStringValido(usuario,30))
        {
            cout << "ERROR SOBREPASO LIMITE DE CARACTERES" << endl;
            system("pause");
            system("cls");
            cout << "MAX 30 CARACTERES -> REINGRESE UN USUARIO DISTINTO:";
            getline(cin, usuario);
        }


        if(validar.esUsuarioValido(usuario) || usuario == "admin")
        {
            cout << "ERROR EL USUARIO YA EXISTE" << endl;
            system("pause");
            system("cls");
            cout << "MAX 30 CARACTERES -> REINGRESE UN USUARIO DISTINTO:";
            getline(cin, usuario);
        }

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

    setTipoUsuario(0);//SETEA EL TIPO DE USUARIO  0=ADMIN /1 = PAIS.
    setEstado(true);// LO PONGO COMO ACTIVO/ NO ELIMINADO.

    cout << "ING SUELDO: $";
    cin >> sueldo;
    setSueldo(sueldo);
}

void Admin::mostrar() const
{
    /*
    Entidad::mostrar();
    cout << "SUELDO: " << getSueldo() << endl;
    */
}


