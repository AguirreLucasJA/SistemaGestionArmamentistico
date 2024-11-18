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
void Avion::cargar(int id)
{
    int opcion = 0;
    int velocidadMax;

    Producto::cargar(id);

    cout << "ING TIPO: " << endl;
    cout << "1- CAZA" << endl;
    cout << "2- BOMBARDERO" << endl;
    cout << "3- CAZA-BOMBARDERO" << endl;
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
        strcpy(_tipo, "CAZA");
        break;
    case 2:
        strcpy(_tipo, "BOMBARDERO");
        break;
    case 3:
        strcpy(_tipo, "CAZA-BOMBARDERO");
        break;
    }

    cout<<"PROPOSITO: " << endl;
    cout << "1- AIRE" << endl;
    cout << "2- TIERRA" << endl;
    cout << "3- AIRE-TIERRA" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion < 1 || opcion > 3)
    {
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        strcpy(_proposito, "AIRE");
        break;
    case 2:
        strcpy(_proposito, "TIERRA");
        break;
    case 3:
        strcpy(_proposito, "AIRE-TIERRA");
        break;
    }

    cout<<"TAMANIO: " << endl;
    cout << "1- CHICO" << endl;
    cout << "2- MEDIANO" << endl;
    cout << "3- GRANDE" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion < 1 || opcion > 3)
    {
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        strcpy(_tamanio, "CHICO");
        break;
    case 2:
        strcpy(_tamanio, "MEDIANO");
        break;
    case 3:
        strcpy(_tamanio, "GRANDE");
        break;
    }

    cout << "ENTRE (800 - 2000)KM/H -> ING VELOCIDAD MAXIMA: ";
    cin >> velocidadMax;

    while(velocidadMax < 800 || velocidadMax > 2000)
    {
        cout << "Velocidad ingresada incorrecta, re ingrese..." << endl;
        cout << "ENTRE (800 - 2000)KM/H -> ING VELOCIDAD MAXIMA: ";
        cin >> velocidadMax;
    }

    cout<<"MANIOBRABILIDAD: " << endl;
    cout << "1- ALTA" << endl;
    cout << "2- BAJA" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(opcion < 1 || opcion > 2)
    {
        cout << "Opcion incorrecta, re ingrese..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        strcpy(Maniobrabilidad, "ALTA");
        break;
    case 2:
        strcpy(Maniobrabilidad, "BAJA");
        break;
    }
}
//void mostrar();


