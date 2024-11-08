#pragma once
#include <string>
#include "../UsuarioXId.h"



class ArchivoUsuarioXId
{
public:
    ArchivoUsuarioXId(); //construye con nombre del Archivo y tamaño del REG.
    bool guardar(const UsuarioXId &registro);//Agrega
    bool guardar(const UsuarioXId &registro, int pos);//Modifica en una posicion
    int buscarXId(int id);//busca por id
    int getCantidadReg();//Devuelve cantidad de Registros
    UsuarioXId leer(int pos);//Lee en una posicion
    bool leerTodos(UsuarioXId *vecRegistros, int cantidadReg);//Lee todos
    int getNuevoId();//Devuelve id AUTONUMERICO
    int buscarXUsuario(std::string usuario);//busca por su usuario


private:
    std::string _nombreArchivo;
    int _tamReg;
};
