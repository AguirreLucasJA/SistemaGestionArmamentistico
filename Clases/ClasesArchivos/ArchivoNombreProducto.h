#pragma once
#include <string>
#include "../NombreProducto.h"



class ArchivoNombreProducto
{
public:
    ArchivoNombreProducto(); //construye con nombre del Archivo y tamaño del REG.
    bool guardar(const NombreProducto &registro);//Agrega
    bool guardar(const NombreProducto &registro, int pos);//Modifica en una posicion
    int getCantidadReg();//Devuelve cantidad de Registros
    bool leerTodos(NombreProducto *vecRegistros, int cantidadReg);//Lee todos
    int buscarXNombre(std::string nombre);//busca por su usuario


private:
    std::string _nombreArchivo;
    int _tamReg;
};
