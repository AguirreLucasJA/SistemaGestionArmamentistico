#pragma once
#include <string>
#include "../Tanque.h"



class ArchivoTanque
{
public:
    ArchivoTanque(); //construye con nombre del Archivo y tamaño del REG.
    bool guardar(const Tanque &registro);//Agrega un Tanque
    bool guardar(const Tanque &registro, int pos);//Modifica un Tanque en una posicion
    int buscarXId(int id);//busca un Tanque por su id
    int getCantidadReg();//Devuelve cantidad de Registros
    Tanque leer(int pos);//Lee un Tanque en una posicion
    bool leerTodos(Tanque *vecRegistros, int cantidadReg);//Lee todos
    int getNuevoId();//Devuelve id AUTONUMERICO
    int buscarXNombre(std::string nombre);

private:
    std::string _nombreArchivo;
    int _tamReg;
};
