#pragma once
#include <string>
#include "../Misil.h"



class ArchivoMisil
{
public:
    ArchivoMisil(); //construye con nombre del Archivo y tamaño del REG.
    bool guardar(const Misil &registro);//Agrega un Misil
    bool guardar(const Misil &registro, int pos);//Modifica un Misil en una posicion
    int buscarXId(int id);//busca un Misil por su id
    int getCantidadReg();//Devuelve cantidad de Registros
    Misil leer(int pos);//Lee un Misil en una posicion
    bool leerTodos(Misil *vecRegistros, int cantidadReg);//Lee todos
    int getNuevoId();//Devuelve id AUTONUMERICO
    int buscarXNombre(std::string nombre);


private:
    std::string _nombreArchivo;
    int _tamReg;
};

