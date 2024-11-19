#include "Avion.h"
#include "Validar.h"
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
int Avion::getVelocidadMax()
{
    return _velocidadMax;
}

int Avion::getCantMisiles()
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
    Validar validar;
    int opcion = 0;
    int velocidadMax;
    int cantMisiles;
    int alcanceOperativo;

    Producto::cargar(id);

    cout << "ING TIPO: " << endl;
    cout << "1- CAZA" << endl;
    cout << "2- BOMBARDERO" << endl;
    cout << "3- CAZA-BOMBARDERO" << endl;
    cout << "OPCION: ";
    cin >> opcion;

    while(!validar.esRangoValido(1, 3, opcion))
    {
        cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
        cout << "OPCION: ";
        cin >> opcion;
    }

    switch(opcion)
    {
    case 1:
        setTipo("CAZA");
        break;
    case 2:
        setTipo("BOMBARDERO");
        break;
    case 3:
        setTipo("CAZA-BOMBARDERO");
        break;
    }

    cout<<"PROPOSITO: " << endl;
    cout << "1- AIRE" << endl;
    cout << "2- TIERRA" << endl;
    cout << "3- AIRE-TIERRA" << endl;
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
        setProposito("AIRE");
        break;
    case 2:
        setProposito("TIERRA");
        break;
    case 3:
        setProposito("AIRE-TIERRA");
        break;
    }

    cout<<"TAMANIO: " << endl;
    cout << "1- CHICO" << endl;
    cout << "2- MEDIANO" << endl;
    cout << "3- GRANDE" << endl;
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
        setTamanio("CHICO");
        break;
    case 2:
        setTamanio("MEDIANO");
        break;
    case 3:
        setTamanio("GRANDE");
        break;
    }

    cout << "ENTRE (800 - 2000)KM/H -> ING VELOCIDAD MAXIMA: ";
    cin >> velocidadMax;

    while(!validar.esRangoValido(800, 2000, velocidadMax))
    {
        cout << "Velocidad ingresada incorrecta, re ingrese..." << endl;
        cout << "ENTRE (800 - 2000)KM/H -> ING VELOCIDAD MAXIMA: ";
        cin >> velocidadMax;
    }

    setVelocidadMax(velocidadMax);

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

    cout<<"MAX 30 -> ING CANTIDAD DE MISILES: ";
    cin>> cantMisiles;

    while(!validar.esRangoValido(0, 30, cantMisiles))
    {
        cout << "Cantidad ingresada incorrecta, re ingrese..." << endl;
        cout << "MAX 30 -> ING CANTIDAD DE MISILES: ";
        cin >> cantMisiles;
    }

    setCantMisiles(cantMisiles);

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

    cout<<"ENTRE (100 - 2000)KM/H -> ING ALCANCE OPERATIVO: ";
    cin>> alcanceOperativo;
    while(!validar.esRangoValido(100, 2000, alcanceOperativo))
    {
        cout << "Alcance operativo incorrecto, re ingrese..." << endl;
        cout<<"ENTRE (100 - 2000)KM/H -> ING ALCANCE OPERATIVO: ";
        cin>> alcanceOperativo;
    }

    setAlcanceOperativo(alcanceOperativo);

}
void Avion::mostrar()
{
    Producto::mostrar();
    cout << "TIPO: " << getTipo() << endl;
    cout << "VELOCIDAD MAXIMA: " << getVelocidadMax() << endl;
    cout << "MANIOBRABILIDAD: " << getManiobrabilidad() << endl;
    cout << "AMETRALLADORA: " << (getAmetralladora() ? "Si" : "No") << endl;

    cout << "PROPOSITO: " << getProposito() << endl;
    cout << "CANTIDAD DE MISILES: " << getCantMisiles() << endl;
    cout << "ALCANCE OPERATIVO: " << getAlcanceOperativo() << endl;
    cout << "TAMANIO: " << getTamanio() << endl;
}


