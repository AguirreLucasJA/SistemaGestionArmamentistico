#pragma once
#include <string>
#include "../Venta.h"

class ArchivoVenta
{
public:
    ArchivoVenta(); //construye con nombre del Archivo y tamaño del REG.
    bool guardar(const Venta &registro);//Agrega un Venta
    bool guardar(const Venta &registro, int pos);//Modifica un Venta en una posicion
    int buscarXId(int id);//busca un Venta por su id
    int getCantidadReg();//Devuelve cantidad de Registros
    Venta leer(int pos);//Lee un Venta en una posicion
    bool leerTodos(Venta *vecRegistros, int cantidadReg);//Lee todos
    int getNuevoId();//Devuelve id AUTONUMERICO

private:
    std::string _nombreArchivo;
    int _tamReg;
};
