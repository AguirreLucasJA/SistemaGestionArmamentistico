#include "Producto.h"
#include "Validar.h"
#include <iostream>//para los cout, cin.
#include<cstring>//para utilizar strcpy
using namespace std;//para no andar escribiendo "std::cout"

//SETTERS
void Producto::setPrecio(long long precio)
{
    _precio = precio;
}

void Producto::setEstado(bool estado)
{
    _estado = estado;
}

void Producto::setStock(int stock)
{
    _stock = stock;
}

void Producto::setId(int id)
{
    _id = id;
}

void Producto::setNombre(string nombre)
{
    strcpy(_nombre, nombre.c_str());
}

void Producto::setPaisOrigen(string paisOrigen)
{
    strcpy(_paisOrigen, paisOrigen.c_str());
}

void Producto::setDescripcion(string descripcion)
{

    strcpy(_descripcion, descripcion.c_str());

}

void Producto::setFecha(Fecha fecha)
{
    _fechaAlta = fecha;
}

void Producto::setLote(int lote)
{
    _lote = lote;
}

//GETTERS
long long Producto::getPrecio()
{
    return _precio;
}

bool Producto::getEstado()
{
    return _estado;
}

int Producto::getStock()
{
    return _stock;
}

int Producto::getId()
{
    return _id;
}

string Producto::getNombre()
{
    return _nombre;
}

string Producto::getPaisOrigen()
{
    return _paisOrigen;
}

string Producto::getDescripcion()
{
    return _descripcion;
}

Fecha Producto::getFechaAlta()
{
    return _fechaAlta;
}

int Producto::getLote()
{
    return _lote;
}

//METODOS
void Producto::cargar(int id) //le pasas el id autonumerico
{
    Fecha fechaAlta;
    Validar validar;
    string nombre;
    string paisOrigen;
    string descripcion;
    long long precio;
    int stock;
    int lote;

    setId(id);//le setea el id obtenido con la funcion contar registros de la Clase Archivo del Producto
    cout << "CARGANDO ID: " << getId() << endl;//muestra el nuevo id autonumerico

    cout<<"MAX 30 CARACTERES -> ING NOMBRE: ";
    cin.ignore();// sino se saltea el ingreso.
    getline(cin, nombre);

    while(!validar.esStringValido(nombre,30) || !validar.esNombreProductoValido(nombre))
    {

       if(!validar.esStringValido(nombre,30))
        {
            cout << "ERROR SOBREPASO LIMITE DE CARACTERES" << endl;
            system("pause");
            system("cls");
            cout << "MAX 30 CARACTERES -> REINGRESE UN USUARIO DISTINTO:";
            getline(cin, nombre);
        }


        if(!validar.esNombreProductoValido(nombre))
        {
            cout << "ERROR EL USUARIO YA EXISTE" << endl;
            system("pause");
            system("cls");
            cout << "MAX 30 CARACTERES -> REINGRESE UN USUARIO DISTINTO:";
            getline(cin, nombre);
        }

    }

    setNombre(nombre);

    cout<<"ING PRECIO: u$d ";
    cin>> precio;
    setPrecio(precio);

    cout<<"ING STOCK: ";
    cin>> stock;
    setStock(stock);

    cout<<"ING LOTE: ";
    cin>> lote;
    setLote(lote);

    cin.ignore();
    cout<<"MAX 30 CARACTERES -> ING PAIS DE ORIGEN: ";
    getline(cin, paisOrigen);

    while(!validar.esStringValido(paisOrigen,30))
    {
        cout << "ERROR SOBREPASO LIMITE DE 30 CARACTERES" << endl;
        system("pause");
        system("cls");
        cout << "REINGRESE PAIS DE ORIGEN:";
        getline(cin, paisOrigen);
    }
    setPaisOrigen(paisOrigen);

    cout<<"MAX 30 CARACTERES -> ING DESCRIPCION: ";
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

    setFecha(fechaAlta);
    setEstado(true);

}

void Producto::mostrar()
{
    cout << "ID: " << getId() << endl;
    cout << "NOMBRE: " << getNombre() << endl;
    cout << "DESCRIPCION: " << getDescripcion() << endl;
    cout << "PAIS DE ORIGEN: " << getPaisOrigen() << endl;
    cout << "STOCK: " << getStock() << endl;
    cout << "PRECIO: u$d " << getPrecio() << endl;
    cout << "LOTE: " << getLote() << endl;
    cout << "FECHA ALTA: " << getFechaAlta().toString() << endl;
    cout << "ESTADO: " << (getEstado() ? "ACTIVO" : "ELIMINADO") << endl;
}




