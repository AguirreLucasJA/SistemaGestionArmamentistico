#include "Misil.h"
#include<cstring>//para utilizar strcpy

//SETTERS
void Misil::setCantCabezasExplosivas(int cantCabezasExplosivas)
{
    _cantCabezasExplosivas = cantCabezasExplosivas;
}

void Misil::setVelocidadMax(int velocidadMax)
{
    _velocidadMax = velocidadMax;
}

void Misil::setPeso(int peso)
{
    _peso = peso;
}

void Misil::setTipoCombustible(std::string tipoCombustible)
{
    strcpy(_tipoCombustible, tipoCombustible.c_str());
}

void Misil::setTipoCarga(std::string tipoCarga)
{
    strcpy(_tipoCarga, tipoCarga.c_str());
}

void Misil::setTipoAtaque(std::string tipoAtaque)
{
    strcpy(_tipoAtaque, tipoAtaque.c_str());
}

void Misil::setTipoPropulsion(std::string tipoPropulsion)
{
    strcpy(_tipoPropulsion, tipoPropulsion.c_str());
}

void Misil::setTipoGuia(std::string tipoGuia)
{
    strcpy(_tipoGuia, tipoGuia.c_str());
}

void Misil::setHipersonico(bool hipersonico) {
    _hipersonico = hipersonico;
}

//GETTERS
//TODO: FALTA HACER

//METODOS
//TODO: FALTA HACER

