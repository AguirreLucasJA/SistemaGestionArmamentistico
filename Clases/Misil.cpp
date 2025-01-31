#include "Misil.h"
#include "Validar.h"
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
    Validar validar;
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

    while(!validar.esRangoValido(1, 2, opcion))
    {
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setTipoPropulsion("COHETE");
        break;
    case 2:
        setTipoPropulsion("REACCION");
        break;
    }

    cout << "ING TIPO DE GUIA: " << endl;
    cout << "1- TOTAL" << endl;
    cout << "2- PARCIAL" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 2, opcion))
    {
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setTipoGuia("TOTAL");
        break;
    case 2:
        setTipoGuia("PARCIAL");
        break;
    }

    cout << "MAX 10 -> ING CANTIDAD DE CABEZAS EXPLOSIVAS: ";
    cin >> cantCabezasExplosivas;
    while(!validar.esRangoValido(0, 10, cantCabezasExplosivas))
    {
        cout << "Cantidad ingresada incorrecta, re ingrese..." << endl;
        cout << "MAX 10 -> ING CANTIDAD DE CABEZAS EXPLOSIVAS: ";
        cin >> cantCabezasExplosivas;
    }
    setCantCabezasExplosivas(cantCabezasExplosivas);

    cout << "ENTRE (100 - 99999)KM/H -> ING VELOCIDAD MAXIMA: ";
    cin >> velocidadMax;

    while(!validar.esRangoValido(100, 99999, velocidadMax))
    {
        cout << "Velocidad ingresada incorrecta, re ingrese..." << endl;
        cout << "ENTRE (100 - 99999)KM/H -> ING VELOCIDAD MAXIMA: ";
        cin >> velocidadMax;
    }

    setVelocidadMax(velocidadMax);

    cout << "ENTRE (1 - 4)TN -> ING PESO: ";
    cin >> peso;

    while(!validar.esRangoValido(1, 4, peso))
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

    while(!validar.esRangoValido(1, 2, opcion))
    {
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setTipoCombustible("SOLIDO");
        break;
    case 2:
        setTipoCombustible("LIQUIDO");
        break;
    }

    cout << "ING TIPO DE CARGA: " << endl;
    cout << "1- EXPLOSIVA" << endl;
    cout << "2- NUCLEAR" << endl;
    cout << "3- QUIMICA" << endl;
    cout << "4- BIOLOGICA" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 4, opcion))
    {
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setTipoCarga("EXPLOSIVA");
        break;
    case 2:
        setTipoCarga("NUCLEAR");
        break;
    case 3:
        setTipoCarga("QUIMICA");
        break;
    case 4:
        setTipoCarga("BIOLOGIA");
        break;

    }

    cout << "ING TIPO DE ATAQUE: " << endl;
    cout << "1- AIRE-AIRE" << endl;
    cout << "2- AIRE-TIERRA" << endl;
    cout << "3- TIERRA-AIRE" << endl;
    cout << "4- TIERRA-TIERRA" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 4, opcion))
    {
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setTipoAtaque("AIRE-AIRE");
        break;
    case 2:
        setTipoAtaque("AIRE-TIERRA");
        break;
    case 3:
        setTipoAtaque("TIERRA-AIRE");
        break;
    case 4:
        setTipoAtaque("TIERRA-TIERRA");
        break;
    }

    cout << "ING HIPERSONICO: " << endl;
    cout << "1- SI" << endl;
    cout << "2- NO" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 2, opcion))
    {
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setHipersonico(true);
        break;
    case 2:
        setHipersonico(false);
        break;
    }
    cin.ignore();
}

void Misil::mostrar()
{
    Producto::mostrar();
    cout << "PESO: " << getPeso() << endl;
    cout << "TIPO DE PROPULSION: " << getTipoPropulsion() << endl;
    cout << "CANTIDAD CABEZAS EXPLOSIVAS: " << getCantCabezasExplosivas() << endl;
    cout << "VELOCIDAD MAXIMA: " << getVelocidadMax() << endl;
    cout << "TIPO DE COMBUSTIBLE: " << getTipoCombustible() << endl;
    cout << "TIPO DE CARGA: " << getTipoCarga() << endl;
    cout << "TIPO ATAQUE: " << getTipoAtaque() << endl;
    cout << "TIPO DE GUIA: " << getTipoGuia() << endl;
    cout << "HIPERSONICO: " << (getHipersonico() ? "Si" : "No") << endl;
}


