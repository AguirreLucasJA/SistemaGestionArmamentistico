#pragma once
#include <string>
#include "../Buque.h"



class ArchivoBuque
{
public:
    ArchivoBuque(); //construye con nombre del Archivo y tamaño del REG.
    bool guardar(const Buque &registro);//Agrega un Buque
    bool guardar(const Buque &registro, int pos);//Modifica un Buque en una posicion
    int buscarXId(int id);//busca un Buque por su id
    int getCantidadReg();//Devuelve cantidad de Registros
    Buque leer(int pos);//Lee un Buque en una posicion
    bool leerTodos(Buque *vecRegistros, int cantidadReg);//Lee todos
    int getNuevoId();//Devuelve id AUTONUMERICO
    int buscarXNombre(std::string nombre);

private:
    std::string _nombreArchivo;
    int _tamReg;
};
