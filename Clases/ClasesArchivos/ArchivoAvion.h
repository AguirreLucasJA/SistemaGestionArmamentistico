#pragma once
#include <string>
#include "../Avion.h"



class ArchivoAvion
{
public:
    ArchivoAvion(); //construye con nombre del Archivo y tamaño del REG.
    bool guardar(const Avion &registro);//Agrega un Avion
    bool guardar(const Avion &registro, int pos);//Modifica un Avion en una posicion
    int buscarXId(int id);//busca un Avion por su id
    int getCantidadReg();//Devuelve cantidad de Registros
    Avion leer(int pos);//Lee un Avion en una posicion
    bool leerTodos(Avion *vecRegistros, int cantidadReg);//Lee todos
    int getNuevoId();//Devuelve id AUTONUMERICO
    int buscarXNombre(std::string nombre);

private:
    std::string _nombreArchivo;
    int _tamReg;
};
