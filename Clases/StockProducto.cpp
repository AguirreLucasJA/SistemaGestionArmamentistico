#include "StockProducto.h"
#include<cstring>//para utilizar strcpy
using namespace std;//PARA NO ANDAR HACIENDO STD::COUT

//SETTERS
void StockProducto::setId(int id)
{
    _id = id;
}

void StockProducto::setStock(int stock)
{
    _stock = stock;
}

//GETTERS
int StockProducto::getId()
{
    return _id;
}

int StockProducto::getStock()
{
    return _stock;
}
