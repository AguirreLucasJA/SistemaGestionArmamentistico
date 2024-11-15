#include "Buque.h"
#include <iostream>//PARA LOS COUT
#include<cstring>//para utilizar strcpy
using namespace std;


///SETTERS
void Buque::setCantTorretas(int cantTorretas)
{
    _cantTorretas = cantTorretas;
}
void Buque::setVelocidadMax(int velocidadMax)
{
    _velocidadMax = velocidadMax;
}
void Buque::setPeso(int peso)
{
    _peso = peso;
}
void Buque::setTipo(std::string tipo)
{
    strcpy(_tipo, tipo.c_str());
}
void Buque::setBlindaje(std::string blindaje)
{
    strcpy(_blindaje, blindaje.c_str());
}
void Buque::setTipoPropulsion(std::string tipoPropulsion)
{
    strcpy(_tipoPropulsion, tipoPropulsion.c_str());
}
void Buque::setManiobrabilidad(std::string maniobrabilidad)
{
    strcpy(_maniobrabilidad, maniobrabilidad.c_str());
}
void Buque::setAmetralladora(bool ametralladora)
{
    _ametralladora = ametralladora;
}


///GETTERS

int Buque::getCantTorretas()
{
    return _cantTorretas;
}
int Buque::getVelocidadMax()
{
    return _velocidadMax;

}
int Buque::getPeso()
{
    return _peso;

}
std::string Buque::getTipo()
{
    return _tipo;
}
std::string Buque::getBlindaje()
{
    return _blindaje;
}
std::string Buque::getTipoPropulsion()
{
    return _tipoPropulsion;
}
std::string Buque::getManiobrabilidad()
{
    return _maniobrabilidad;
}
bool Buque::getAmetralladoraa()
{
    return _ametralladora;
}
