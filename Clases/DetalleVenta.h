#pragma once
#include <iostream>//para los cout, cin.
#include<cstring>//para utilizar strcpy


class DetalleVenta
{
public:

    void setId (int id);
    void setidProducto (int idProducto);
    void setCantidad (int cantidad);
    void setDescripcion (std::string descripcion);
    void setPrecioUnitario (long long precioUnitario);
    void setPrecioTotal (long long precioTotal);

    int getId ();
    int getIdProducto();
    int getCantidad();
    std::string getDescripcion();
    long long getPrecioUnitario();
    long long getPrecioTotal();

    void mostrar();

private:
    int _id;
    int _idProducto;
    int _cantidad;
    char _descripcion[50];
    long long _precioUnitario;
    long long _precioTotal;

};

