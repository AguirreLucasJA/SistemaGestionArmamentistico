#pragma once
#include <string>
#include "../DetalleVenta.h"

class ArchivoDetalleVenta
{
public:
    ArchivoDetalleVenta(); //construye con nombre del Archivo y tamaño del REG.
    bool guardar(const DetalleVenta &registro);//Agrega un DetalleVenta
    bool guardar(const DetalleVenta &registro, int pos);//Modifica un DetalleVenta en una posicion
    int buscarXId(int id);//busca un DetalleVenta por su id
    int getCantidadReg();//Devuelve cantidad de Registros
    DetalleVenta leer(int pos);//Lee un DetalleVenta en una posicion
    bool leerTodos(DetalleVenta *vecRegistros, int cantidadReg);//Lee todos
    int buscarXNombreProducto(std::string nombreProducto);//busca un DetalleVenta por su nombreProducto


private:
    std::string _nombreArchivo;
    int _tamReg;
};
