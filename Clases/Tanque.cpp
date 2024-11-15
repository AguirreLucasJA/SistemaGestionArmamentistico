#include "Tanque.h"
#include <iostream>//PARA LOS COUT
#include<cstring>//para utilizar strcpy
using namespace std;


///SETTERS
void Tanque::setAlcanceOperativo(int alcanceOperativo)
{
    alcanceOperativo = alcanceOperativo;
}
void Tanque::setPeso(int peso)
{
    _peso = peso;
}
void Tanque::setTorretaCalibre(int torretaCalibre)
{
    _torretaCalibre = torretaCalibre;
}
void Tanque::setVelocidad(int velocidad)
{
    _velocidad = velocidad;
}
void Tanque::setAmetralladora(bool ametralladora)
{
    _ametralladora = ametralladora;
}
void Tanque::setTorretaBlindada(bool torretaBlindada)
{
    _torretaBlindada = torretaBlindada;
}
void Tanque::setAntiTanque(bool antiTanque)
{
    _antiTanque = antiTanque;
}
void Tanque::setLargoAlcance(bool largoAlcance)
{
    _largoAlcance = largoAlcance;
}
void Tanque::setOcultamiento(bool ocultamiento)
{
    _ocultamiento = ocultamiento;
}
void Tanque::setRangoVision(std::string rangoVision)
{
    strcpy(_rangoVision, rangoVision.c_str());
}
void Tanque::setTipoBlindaje(std::string tipoBlindaje)
{
    strcpy(_tipoBlindaje, tipoBlindaje.c_str());
}
void Tanque::setMovilidad(std::string movilidad)
{
    strcpy(_movilidad, movilidad.c_str());
}
void Tanque::setPrecision(std::string precision)
{
    strcpy(_precision, precision.c_str());
}

///GETTERS
int Tanque::getAlcanceOperativo()
{
    return _alcanceOperativo;
}
int Tanque::getPeso()
{
    return _peso;
}
int Tanque::getTorretaCalibre()
{
    return _torretaBlindada;
}
int Tanque::getVelocidad()
{
    return _velocidad;
}
bool Tanque::getAmetralladora()
{
    return _ametralladora;
}
bool Tanque::getTorretaBlindada()
{
    return _torretaBlindada;
}
bool Tanque::getAntiTanque()
{
    return _antiTanque;
}
bool Tanque::getLargoAlcance()
{
    return _largoAlcance;
}
bool Tanque::getOcultamiento()
{
    return _ocultamiento;
}
std::string Tanque::getRangoVision()
{
    return _rangoVision;
}
std::string Tanque::getTipoBlindaje()
{
    return _tipoBlindaje;
}
std::string Tanque::getMovilidad()
{
    return _movilidad;
}
std::string Tanque::getPrecision()
{
    return _precision;
}
