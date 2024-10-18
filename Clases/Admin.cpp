#include "Admin.h"
#include <iostream>//para los cout, cin.
#include<cstring>//para las funciones strcpy
using namespace std;//para no andar escribiendo "std::cout"

//METODOS
void Admin::cargar(int id){
    char aux[30];
    //RECORDA ADMIN DERIVA DE ENTIDAD
    Entidad::setId(id);//le setea el id obtenido con la funcion contar registros A LA PROPIEDAD DE ENTIDAD.

    cout << "CARGANDO ID: " << Entidad::getId() << endl;//muestra el nuevo id autonumerico

    cout << "ING NOMBRE USUARIO: ";
    cin >> aux;
    //COMO ADMIN DERIVA DE ENTIDAD hace uso de sus metodos para setear las propiedades de entidad.
    Entidad::setUsuario(aux);

    cout << "ING CLAVE: ";
    cin >> aux;
    Entidad::setClave(aux);

    cout << "ING DESCRPCION: ";
    cin >> aux;
    Entidad::setDescripcion(aux);

    Entidad::setTipoUsuario(0);//SETEO EL TIPO DE USUARIO 0 = ADMINISTRADOR.
    Entidad::setEstado(true);// LO PONGO COMO ACTIVO/ NO ELIMINADO
}

void Admin::mostrar(){
    cout << "USUARIO: " << Entidad::getUsuario() << endl;
    cout << "CLAVE: " << Entidad::getClave() << endl;
    cout << "DESCRIPCION: " << Entidad::getDescripcion() << endl;
    cout << "TIPO DE USUARIO: " << Entidad::getTipoUsuario() << endl;
    cout << "ESTADO: " << Entidad::getEstado() << endl;
    cout << "ID: " << Entidad::getId() << endl;
}
