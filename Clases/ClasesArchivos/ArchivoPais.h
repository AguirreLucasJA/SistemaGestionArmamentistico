#pragma once
#include <string>
#include "../Pais.h"



class ArchivoPais
{
public:
    ArchivoPais(); //construye con nombre del Archivo y tamaño del REG.
    bool guardar(const Pais &registro);//Agrega un Pais
    bool guardar(const Pais &registro, int pos);//Modifica un Pais en una posicion
    int buscarXId(int id);//busca un Pais por su id
    int getCantidadReg();//Devuelve cantidad de Registros
    Pais leer(int pos);//Lee un Pais en una posicion
    bool leerTodos(Pais *vecRegistros, int cantidadReg);//Lee todos
    int getNuevoId();//Devuelve id AUTONUMERICO
    int buscarXUsuario(std::string usuario);//busca un Pais por su usuario

private:
    std::string _nombreArchivo;
    int _tamReg;
};
