#pragma once
#include <string>
#include "../Admin.h"

class ArchivoAdmin
{
public:
    ArchivoAdmin(); //construye con nombre del Archivo y tamaño del REG.
    bool guardar(const Admin &registro);//Agrega un Admin
    bool guardar(const Admin &registro, int pos);//Modifica un Admin en una posicion
    int buscarXId(int id);//busca un Admin por su id
    int getCantidadReg();//Devuelve cantidad de Registros
    Admin leer(int pos);//Lee un Admin en una posicion
    bool leerTodos(Admin *vecRegistros, int cantidadReg);//Lee todos
    int getNuevoId();//Devuelve id AUTONUMERICO
    int buscarXUsuario(std::string usuario);//busca un Admin por su usuario


private:
    std::string _nombreArchivo;
    int _tamReg;
};
