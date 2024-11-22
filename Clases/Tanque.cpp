#include "Tanque.h"
#include "Validar.h"
#include <iostream>//PARA LOS COUT
#include<cstring>//para utilizar strcpy
using namespace std;

//SETTERS
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

void Tanque::setVelocidadMax(int velocidad)
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

//METODOS
void Tanque::cargar(int id)
{
    Validar validar;
    int opcion = 0;
    int velocidadMax;
    int torretaCalibre;
    int peso;
    int alcanceOperativo;

    Producto::cargar(id);

    cout << "ING TIPO DE BLINDAJE: " << endl;
    cout << "1- BAJO" << endl;
    cout << "2- MEDIO" << endl;
    cout << "3- ALTO" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 3, opcion))
    {
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setTipoBlindaje("BAJO");
        break;
    case 2:
        setTipoBlindaje("MEDIO");
        break;
    case 3:
        setTipoBlindaje("ALTO");
        break;
    }

    cout<<"ING MOVILIDAD: " << endl;
    cout << "1- ALTA" << endl;
    cout << "2- BAJA" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 2, opcion))
    {
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setMovilidad("ALTA");
        break;
    case 2:
        setMovilidad("BAJA");
        break;
    }

    cout<<"ING OCULTAMIENTO: " << endl;
    cout << "1- SI" << endl;
    cout << "2- NO" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 2, opcion))
    {
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setOcultamiento(true);
        break;
    case 2:
        setOcultamiento(false);
        break;
    }

    cout<<"ING RANGO DE VISION: " << endl;
    cout << "1- BAJO" << endl;
    cout << "2- MEDIO" << endl;
    cout << "3- ALTO" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 3, opcion))
    {
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setRangoVision("BAJO");
        break;
    case 2:
        setRangoVision("MEDIO");
        break;
    case 3:
        setRangoVision("ALTO");
        break;
    }

    cout<<"ING LARGO ALCANCE: " << endl;
    cout << "1- SI" << endl;
    cout << "2- NO" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 2, opcion))
    {
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setLargoAlcance(true);
        break;
    case 2:
        setLargoAlcance(false);
        break;
    }

    cout<<"ING PRESICION: " << endl;
    cout << "1- BAJO" << endl;
    cout << "2- MEDIO" << endl;
    cout << "3- ALTO" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 3, opcion))
    {
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setPrecision("BAJO");
        break;
    case 2:
        setPrecision("MEDIO");
        break;
    case 3:
        setPrecision("ALTO");
        break;
    }

    cout<<"ING ANTITANQUE: " << endl;
    cout << "1- SI" << endl;
    cout << "2- NO" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 2, opcion))
    {
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setAntiTanque(true);
        break;
    case 2:
        setAntiTanque(false);
        break;
    }

    cout << "ENTRE (80 - 140)KM/H -> ING VELOCIDAD MAXIMA: ";
    cin >> velocidadMax;

    while(!validar.esRangoValido(80, 140, velocidadMax))
    {
        cout << "Velocidad ingresada incorrecta, re ingrese..." << endl;
        cout << "ENTRE (80 - 140)KM/H -> ING VELOCIDAD MAXIMA: ";
        cin >> velocidadMax;
    }

    setVelocidadMax(velocidadMax);

    cout<<"ING TORRETA BLINDADA: " << endl;
    cout << "1- SI" << endl;
    cout << "2- NO" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 2, opcion))
    {
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setTorretaBlindada(true);
        break;
    case 2:
        setTorretaBlindada(false);
        break;
    }

    cout << "ENTRE (105 - 135)MM -> ING CALIBRE DE TORRETA: ";
    cin >> torretaCalibre;

    while(!validar.esRangoValido(105, 135, torretaCalibre))
    {
        cout << "Velocidad ingresada incorrecta, re ingrese..." << endl;
        cout << "ENTRE (105 - 135)MM -> ING CALIBRE DE TORRETA: ";
        cin >> torretaCalibre;
    }

    setTorretaCalibre(torretaCalibre);

    cout << "ENTRE (40 - 80)TN -> ING PESO: ";
    cin >> peso;

    while(!validar.esRangoValido(40, 80, peso))
    {
        cout << "Peso ingresado incorrecto, re ingrese..." << endl;
        cout << "ENTRE (40 - 80)TN -> ING PESO: ";
        cin >> peso;
    }

    setPeso(peso);

    cout<<"ENTRE (50 - 150)KM -> ING ALCANCE OPERATIVO: ";
    cin>> alcanceOperativo;
    while(!validar.esRangoValido(50, 150, alcanceOperativo))
    {
        cout << "Alcance operativo incorrecto, re ingrese..." << endl;
        cout<<"ENTRE (50 - 150)KM -> ING ALCANCE OPERATIVO: ";
        cin>> alcanceOperativo;
    }

    setAlcanceOperativo(alcanceOperativo);

    cout<<"ING AMETRALLADORA: " << endl;
    cout << "1- SI" << endl;
    cout << "2- NO" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 2, opcion))
    {
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setAmetralladora(true);
        break;
    case 2:
        setAmetralladora(false);
        break;
    }
}

void Tanque::mostrar()
{
    Producto::mostrar();
    cout << "TIPO DE BLINDAJE: " << getTipoBlindaje() << endl;
    cout << "MOVILIDAD: " << getMovilidad() << endl;
    cout << "OCULTAMIENTO: " << (getOcultamiento() ? "Si" : "No") << endl;
    cout << "RANGO DE VISION: " << getRangoVision() << endl;
    cout << "LARGO ALCANCE: " << (getLargoAlcance() ? "Si" : "No") << endl;
    cout << "PRESICION: " << getPrecision() << endl;
    cout << "ANTITANQUE: " << (getAntiTanque() ? "Si" : "No") << endl;
    cout << "VELOCIDAD MAXIMA: " << getVelocidad() << endl;
    cout << "TORRETA BLINDADA: " << (getTorretaBlindada() ? "Si" : "No") << endl;
    cout << "CALIBRE DE TORRETA: " << getTorretaCalibre() << endl;
    cout << "PESO: " << getPeso() << endl;
    cout << "ALCANCE OPERATIVO: " << getAlcanceOperativo() << endl;
    cout << "AMETRALLADORA: " << getAmetralladora() << endl;
}
