#pragma once
#include <string>//para poder usar string
//#include"Fecha.h"//TODO:FALTA HACERLA

class Producto
{
public:
    Producto() {};

    void setPrecio(long long precio);
    void setEstado(bool estado);
    bool setNombre(std::string nombre);
    bool setDescripcion(std::string descripcion);
    void setId(int id);
    bool setPaisOrigen(std::string paisOrigen);
    void setStock(int stock);
    //void setFecha(Fecha fecha);
    void setLote(int lote);

    long long getPrecio();
    bool getEstado();
    std::string getNombre();
    std::string getDescripcion();
    int getId();
    std::string getPaisOrigen();
    int getStock();
    //Fecha getFechaAlta();
    int getLote();

    void cargar();
    void mostrar();

private:
    long long _precio;
    bool _estado;
    int _stock;
    int _id;
    char _nombre[30];
    char _paisOrigen[30];
    char _descripcion[100];
    //Fecha _fechaAlta;
    int _lote;
};
