#include "Avion.h"
#include <iostream>//PARA LOS COUT
#include<cstring>//para utilizar strcpy
using namespace std;

//SETTERS
void Avion::setVelocidadMax(int velocidadMax)
{
    _velocidadMax= velocidadMax;
}

void Avion::setCantMisiles(int cantMisiles)
{
    _cantMisiles = cantMisiles;
}

void Avion::setAlcanceOperativo(int alcanceOperativo)
{
    _alcanceOperativo = alcanceOperativo;
}

void Avion::setAmetralladora(bool ametralladora)
{
    _ametralladora = ametralladora;
}

void Avion::setTipo(std::string tipo)
{
    strcpy(_tipo, tipo.c_str());
}

void Avion::setProposito(std::string proposito)
{
    strcpy(_proposito, proposito.c_str());
}

void Avion::setTamanio(std::string tamanio)
{
    strcpy(_tamanio, tamanio.c_str());
}

void Avion::setManiobrabilidad(std::string maniobrabilidad)
{
    strcpy(_maniobrabilidad, maniobrabilidad.c_str());
}

//GETTERS
int Avion::getsetVelocidadMax()
{
    return _velocidadMax;
}

int Avion::getsetCantMisiles()
{
    return _cantMisiles;
}

int Avion::getAlcanceOperativo()
{
    return _alcanceOperativo;
}

bool Avion::getAmetralladora()
{
    return _ametralladora;
}

std::string Avion::getTipo()
{
    return _tipo;
}

std::string Avion::getProposito()
{
    return _proposito;
}

std::string Avion::getTamanio()
{
    return _tamanio;
}

std::string Avion::getManiobrabilidad()
{
    return _maniobrabilidad;
}

//METODOS
//void cargar(int id);
//void mostrar();


