#include "Buque.h"
#include "Validar.h"
#include <iostream>//PARA LOS COUT
#include<cstring>//para utilizar strcpy
using namespace std;

//SETTERS
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

//GETTERS
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

//METODOS
void Buque::cargar(int id)
{
    Validar validar;
    int opcion = 0;
    int cantTorretas;
    int velocidadMax;
    int peso;

    Producto::cargar(id);

    cout << "ING TIPO: " << endl;
    cout << "1- MONITOR" << endl;
    cout << "2- CRUZERO - LANZAMISILES" << endl;
    cout << "3- CRUZERO - PORTAVIONES" << endl;
    cout << "4- CRUZERO - ACORAZADO" << endl;
    cout << "5- CRUZERO - LIGERO" << endl;
    cout << "6- DESTRUCTOR" << endl;
    cout << "7- CAZA TORPEDOS" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 7, opcion))
    {
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setTipo("MONITOR");
        break;
    case 2:
        setTipo("CRUZERO - LANZAMISILES");
        break;
    case 3:
        setTipo("CRUZERO - PORTAVIONES");
        break;
    case 4:
        setTipo("CRUZERO - ACORAZADO");
        break;
    case 5:
        setTipo("CRUZERO - LIGERO");
        break;
    case 6:
        setTipo("DESTRUCTOR");
        break;
    case 7:
        setTipo("CAZA TORPEDOS");
        break;
    }

    cout<<"MAX 40 -> ING CANTIDAD DE TORRETAS: ";
    cin>> cantTorretas;

    while(!validar.esRangoValido(0, 40, cantTorretas))
    {
        cout << "Cantidad ingresada incorrecta, re ingrese..." << endl;
        cout<<"MAX 40 -> ING CANTIDAD DE TORRETAS: ";
        cin >> cantTorretas;
    }

    setCantTorretas(cantTorretas);

    cout << "ENTRE (70 - 150)KM/H -> ING VELOCIDAD MAXIMA: ";
    cin >> velocidadMax;

    while(!validar.esRangoValido(70, 150, velocidadMax))
    {
        cout << "Velocidad ingresada incorrecta, re ingrese..." << endl;
        cout << "ENTRE (70 - 150)KM/H -> ING VELOCIDAD MAXIMA: ";
        cin >> velocidadMax;
    }

    setVelocidadMax(velocidadMax);

    cout << "ENTRE (50000 - 80000)TN -> ING PESO: ";
    cin >> peso;

    while(!validar.esRangoValido(50000, 80000, peso))
    {
        cout << "Peso ingresado incorrecto, re ingrese..." << endl;
        cout << "ENTRE (50000 - 80000)TN -> ING PESO: ";
        cin >> peso;
    }

    setPeso(peso);

    cout << "ING BLINDAJE: " << endl;
    cout << "1- ALTO" << endl;
    cout << "2- MEDIO" << endl;
    cout << "3- BAJO" << endl;
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
        setBlindaje("ALTO");
        break;
    case 2:
        setBlindaje("MEDIO");
        break;
    case 3:
        setBlindaje("BAJO");
        break;
    }

    cout << "ING TIPO DE PROPULSION: " << endl;
    cout << "1- CALDERAS" << endl;
    cout << "2- TURBINAS" << endl;
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
        setTipoPropulsion("CALDERAS");
        break;
    case 2:
        setTipoPropulsion("TURBINAS");
        break;
    }

    cout<<"MANIOBRABILIDAD: " << endl;
    cout << "1- ALTA" << endl;
    cout << "2- MEDIA" << endl;
    cout << "3- BAJA" << endl;
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
        setManiobrabilidad("ALTA");
        break;
    case 2:
        setManiobrabilidad("MEDIA");
        break;
    case 3:
        setManiobrabilidad("BAJA");
        break;
    }

    cout<<"AMETRALLADORA: " << endl;
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
void Buque::mostrar()
{
    Producto::mostrar();
    cout << "TIPO: " << getTipo() << endl;
    cout << "VELOCIDAD MAXIMA: " << getVelocidadMax() << endl;
    cout << "MANIOBRABILIDAD: " << getManiobrabilidad() << endl;
    cout << "AMETRALLADORA: " << (getAmetralladora() ? "Si" : "No") << endl;

    cout << "PESO: " << getPeso() << endl;
    cout << "TIPO DE PROPULSION: " << getTipoPropulsion() << endl;

    cout << "CANTIDAD DE TORRETAS: " << getCantTorretas() << endl;
    cout << "BLINDAJE: " << getBlindaje() << endl;
}

