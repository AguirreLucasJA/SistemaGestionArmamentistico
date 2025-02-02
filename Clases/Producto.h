#pragma once
#include <string>//para poder usar string
#include"Fecha.h"

class Producto
{
public:
    Producto() {};

    void setPrecio(long long precio);
    void setEstado(bool estado);
    void setNombre(std::string nombre);
    void setDescripcion(std::string descripcion);
    void setId(int id);
    void setPaisOrigen(std::string paisOrigen);
    void setStock(int stock);
    void setFecha(Fecha fecha);
    void setLote(int lote);

    long long getPrecio();
    bool getEstado();
    std::string getNombre();
    std::string getDescripcion();
    int getId();
    std::string getPaisOrigen();
    int getStock();
    Fecha getFechaAlta();
    int getLote();

    void cargar(int id);
    void mostrar();

private:
    long long _precio;
    bool _estado;
    int _stock;
    int _id;
    char _nombre[30];
    char _paisOrigen[30];
    char _descripcion[100];
    Fecha _fechaAlta;
    int _lote;
};
