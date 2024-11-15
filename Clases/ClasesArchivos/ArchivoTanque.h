#pragma once
#include <string>
#include "../Tanque.h"


class ArchivoTanque
{
public:
    ArchivoTanque(); //construye con nombre del Archivo y tamaño del REG.
    bool guardar(const Tanque &registro);//Agrega un Admin
    bool guardar(const Tanque &registro, int pos);//Modifica un Admin en una posicion
    int buscarXId(int id);//busca un Admin por su id
    int getCantidadReg();//Devuelve cantidad de Registros
    Tanque leer(int pos);//Lee un Admin en una posicion
    bool leerTodos(Tanque *vecRegistros, int cantidadReg);//Lee todos
    int getNuevoId();//Devuelve id AUTONUMERICO
    int buscarXUsuario(std::string usuario);//busca un Admin por su usuario


private:
    std::string _nombreArchivo;
    int _tamReg;
};
