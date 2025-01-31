#pragma once
#include <string>
#include "../NombreUsuario.h"



class ArchivoNombreUsuario
{
public:
    ArchivoNombreUsuario(); //construye con nombre del Archivo y tamaño del REG.
    bool guardar(const NombreUsuario &registro);//Agrega
    bool guardar(const NombreUsuario &registro, int pos);//Modifica en una posicion
    int getCantidadReg();//Devuelve cantidad de Registros
    bool leerTodos(NombreUsuario *vecRegistros, int cantidadReg);//Lee todos
    int buscarXUsuario(std::string usuario);//busca por su usuario


private:
    std::string _nombreArchivo;
    int _tamReg;
};

