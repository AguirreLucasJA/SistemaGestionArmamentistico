#include "Fecha.h"
#include <ctime>

void Fecha::setFechaDefault()
{
    _dia = 1;
    _mes = 1;
    _anio = 2023;
}

void Fecha::setFechaSistema()
{
    time_t timestamp = time(0);
    tm *diaactual = localtime(&timestamp);
    _dia = diaactual->tm_mday;
    _mes = diaactual->tm_mon+1;
    _anio = diaactual->tm_year+1900;
}


Fecha::Fecha()
{
    setFechaSistema();
}

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia  = dia;
    _mes = mes;
    _anio = anio;

    validar();
}

void Fecha::validar()
{
    if(!esMesValido() || !esDiaValido() || !esAnioValido())
    {
        setFechaDefault();
    }
}

bool Fecha::esBisiesto()
{
    return _anio % 4 == 0 && _anio % 100 != 0 || _anio % 400 ==0;
}

bool Fecha::esDiaValido()
{
    int *vec;
    bool esValido = false;
    vec = crearVectorDiasxMes();

    /*int diasxMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (esBisiesto())
    {
        diasxMes[1]++;
    }
    */

    esValido = _dia >= 1 && _dia <= vec[_mes-1];

    delete [] vec;

    return esValido;
}

bool Fecha::esMesValido()
{
    return _mes >= 1 && _mes <= 12;
}

bool Fecha::esAnioValido()
{
    return _anio > 0;
}


int Fecha::getDia()
{
    return _dia;
}

int Fecha::getMes()
{
    return _mes;
}

int Fecha::getAnio()
{
    return _anio;
}

std::string Fecha::toString()
{
    return (_dia <= 9 ? "0" : "") + std::to_string(_dia) + "/" + (_mes <= 9 ? "0" : "") + std::to_string(_mes) + "/" + std::to_string(_anio);
}
/// para interpretar mejor lo del OPERADOR TERNARIO QUE HACE.
/*
std::string Fecha::toString() {
        std::string fechaADevolver;

        if (_dia <= 9) {
            fechaADevolver = "0";
        }
        fechaADevolver += std::to_string(_dia) + "/";

        if (_mes <= 9) {
            fechaADevolver += "0";
        }
        fechaADevolver += std::to_string(_mes) + "/";

        fechaADevolver += std::to_string(_anio);

        return fechaADevolver;
    }
*/

void Fecha::AgregarDia()
{
    _dia++;
    if (!esDiaValido())
    {
        _dia = 1;
        _mes++;
    }
    if (!esMesValido())
    {
        _mes = 1;
        _anio++;
    }
}

int * Fecha::crearVectorDiasxMes()
{
    int *diasxMes = new int [12]; /// = {31,28,31,30,31,30,31,31,30,31,30,31}; NO LO PUEDO INICIALIZAR DE UNA CON ESTOS VALORES. Es correcto como se los asigne? hay una manera mejor?
    diasxMes[0] = 31;
    diasxMes[1] = 28;
    diasxMes[2] = 31;
    diasxMes[3] = 30;
    diasxMes[4] = 31;
    diasxMes[5] = 30;
    diasxMes[6] = 31;
    diasxMes[7] = 31;
    diasxMes[8] = 30;
    diasxMes[9] = 31;
    diasxMes[10] = 30;
    diasxMes[11] = 31;


    if(diasxMes == nullptr)
    {
        exit(-1);
    }
    if (esBisiesto())
    {
        diasxMes[1]++;
    }

    return diasxMes;
}

void Fecha::RestarDia()
{
    int *vec;
    vec = crearVectorDiasxMes();

    _dia--;

    if (!esDiaValido())
    {
        _mes--;

        if (!esMesValido())
        {
            _mes = 12;
            _anio--;
        }
        _dia = vec[_mes - 1];
    }

    delete [] vec;
}

void Fecha::AgregarDias(int dias)
{

    if(dias > 0)
    {
        for(int i = 0; i < dias; i++)
        {
            AgregarDia();
        }
    }
    else if (dias < 0)
    {
        for(int i = 0; i < -dias; i++) //para obtener el valor absoluto de dias;
        {
            RestarDia();
        }

    }
// Si dias es 0, no hacer nada....
}
