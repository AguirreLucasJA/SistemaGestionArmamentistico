#include "Misil.h"
#include <iostream>//PARA LOS COUT
#include<cstring>//para utilizar strcpy
using namespace std;

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

void Misil::setHipersonico(bool hipersonico)
{
    _hipersonico = hipersonico;
}

//GETTERS
int Misil::getCantCabezasExplosivas()
{
    return _cantCabezasExplosivas;
}

int Misil::getVelocidadMax()
{
    return _velocidadMax;
}

int Misil::getPeso()
{
    return _peso;
}

std::string Misil::getTipoCombustible()
{
    return _tipoCombustible;
}

std::string Misil::getTipoCarga()
{
    return _tipoCarga;
}

std::string Misil::getTipoAtaque()
{
    return _tipoAtaque;
}

std::string Misil::getTipoPropulsion()
{
    return _tipoPropulsion;
}

std::string Misil::getTipoGuia()
{
    return _tipoGuia;
}

bool Misil::getHipersonico()
{
    return _hipersonico;
}

//METODOS
void Misil::cargar(int id)
{
    int opcion = 0;
    int cantCabezasExplosivas;
    int velocidadMax;
    int peso;
    Producto::cargar(id);

    cout << "ING TIPO DE PROPULSION: " << endl;
    cout << "1- COHETE" << endl;
    cout << "2- REACCION" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion != 1 && opcion != 2)
    {
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        strcpy(_tipoPropulsion, "COHETE");
        break;
    case 2:
        strcpy(_tipoPropulsion, "REACCION");
        break;
    }

    cout << "ING TIPO DE GUIA: " << endl;
    cout << "1- TOTAL" << endl;
    cout << "2- PARCIAL" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion != 1 && opcion != 2)
    {
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        strcpy(_tipoGuia, "TOTAL");
        break;
    case 2:
        strcpy(_tipoGuia, "PARCIAL");
        break;
    }

    cout << "MAX 10 -> ING CANTIDAD DE CABEZAS EXPLOSIVAS: ";
    cin >> cantCabezasExplosivas;

    while(cantCabezasExplosivas > 10 || cantCabezasExplosivas < 0)
    {
        cout << "Cantidad ingresada incorrecta, re ingrese..." << endl;
        cout << "MAX 10 -> ING CANTIDAD DE CABEZAS EXPLOSIVAS: ";
        cin >> cantCabezasExplosivas;
    }
    setCantCabezasExplosivas(cantCabezasExplosivas);

    cout << "ENTRE (100 - 99999)KM/H -> ING VELOCIDAD MAXIMA: ";
    cin >> velocidadMax;

    while(velocidadMax < 100 || velocidadMax > 99999)
    {
        cout << "Velocidad ingresada incorrecta, re ingrese..." << endl;
        cout << "ENTRE (100 - 99999)KM/H -> ING VELOCIDAD MAXIMA: ";
        cin >> velocidadMax;
    }

    setVelocidadMax(velocidadMax);

    cout << "ENTRE (1 - 4)TN -> ING PESO: ";
    cin >> peso;

    while(peso < 0 || peso > 5)
    {
        cout << "Peso ingresado incorrecto, re ingrese..." << endl;
        cout << "ENTRE (1 - 4)TN -> ING PESO: ";
        cin >> peso;
    }

    setPeso(peso);

    cout << "ING TIPO DE COMBUSTIBLE: " << endl;
    cout << "1- SOLIDO" << endl;
    cout << "2- LIQUIDO" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion != 1 && opcion != 2)
    {
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        strcpy(_tipoCombustible, "SOLIDO");
        break;
    case 2:
        strcpy(_tipoCombustible, "LIQUIDO");
        break;
    }

    cout << "ING TIPO DE CARGA: " << endl;
    cout << "1- EXPLOSIVA" << endl;
    cout << "2- NUCLEAR" << endl;
    cout << "3- QUIMICA" << endl;
    cout << "4- BIOLOGICA" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion < 1 || opcion > 4)
    {
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        strcpy(_tipoCarga, "EXPLOSIVA");
        break;
    case 2:
        strcpy(_tipoCarga, "NUCLEAR");
        break;
    case 3:
        strcpy(_tipoCarga, "QUIMICA");
        break;
    case 4:
        strcpy(_tipoCarga, "BIOLOGIA");
        break;

    }

    cout << "ING TIPO DE ATAQUE: " << endl;
    cout << "1- AIRE-AIRE" << endl;
    cout << "2- AIRE-TIERRA" << endl;
    cout << "3- TIERRA-AIRE" << endl;
    cout << "4- TIERRA-TIERRA" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion < 1 || opcion > 4)
    {
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        strcpy(_tipoAtaque, "AIRE-AIRE");
        break;
    case 2:
        strcpy(_tipoAtaque, "AIRE-TIERRA");
        break;
    case 3:
        strcpy(_tipoAtaque, "TIERRA-AIRE");
        break;
    case 4:
        strcpy(_tipoAtaque, "TIERRA-TIERRA");
        break;
    }

    cout << "ES HIPERSONICO: " << endl;
    cout << "1- SI" << endl;
    cout << "2- NO" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion != 1 && opcion != 2)
    {
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        _hipersonico = true;
        break;
    case 2:
        _hipersonico = false;
        break;
    }
    cin.ignore();
}

void Misil::mostrar()
{
    Producto::mostrar();
    cout << "CANTIDAD CABEZAS EXPLOSIVAS: " << _cantCabezasExplosivas << endl;
    cout << "VELOCIDAD MAXIMA: " << _velocidadMax << endl;
    cout << "PESO: " << _peso << endl;
    cout << "TIPO DE COMBUSTIBLE: " << _tipoCombustible << endl;
    cout << "TIPO DE CARGA: " << _tipoCarga << endl;
    cout << "TIPO ATAQUE: " << _tipoAtaque << endl;
    cout << "TIPO DE PROPULSION: " << _tipoPropulsion << endl;
    cout << "TIPO DE GUIA: " << _tipoGuia << endl;
    cout << "HIPERSONICO: " << (_hipersonico ? "Si" : "No") << endl;
}


