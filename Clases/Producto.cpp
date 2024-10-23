#include "Producto.h"
#include<cstring>//para utilizar strcpy

//SETTERS
void Producto::setPrecio(long long precio)
{
    _precio = precio;
}

void Producto::setEstado(bool estado)
{
    _estado = estado;
}

void Producto::setStock(int stock)
{
    _stock = stock;
}

void Producto::setId(int id)
{
    _id = id;
}

void Producto::setNombre(std::string nombre)
{
    if(nombre.size() < sizeof(_nombre))
    {
        strcpy(_nombre, nombre.c_str());
        //devuelve el puntero que tiene en la heap."copia un puntero char dentro del otro puntero char"
    }
}

void Producto::setPaisOrigen(std::string paisOrigen)
{
    if(paisOrigen.size() < sizeof(_paisOrigen))
    {
        strcpy(_paisOrigen, paisOrigen.c_str());
    }
}

void Producto::setDescripcion(std::string descripcion)
{
    if(descripcion.size() < sizeof(_descripcion))
    {
        strcpy(_descripcion, descripcion.c_str());
    }
}

//void Producto::setFecha(Fecha fecha){
//    _fechaAlta = fecha;
//}

void Producto::setLote(int lote)
{
    _lote = lote;
}

//GETTERS
long long Producto::getPrecio(){
    return _precio;
}

bool Producto::getEstado(){
    return _estado;
}

int Producto::getStock(){
    return _stock;
}

int Producto::getId(){
    return _id;
}

std::string Producto::getNombre(){
    return _nombre;
}

std::string Producto::getPaisOrigen(){
    return _paisOrigen;
}

std::string Producto::getDescripcion(){
    return _descripcion;
}

//Fecha Producto::getFechaAlta(){
//    return _fechaAlta;
//}

int Producto::getLote(){
    return _lote;
}

//TODO: FALTA CARGAR Y MOSTRAR E INCLUIR A CLASE FECHA.





