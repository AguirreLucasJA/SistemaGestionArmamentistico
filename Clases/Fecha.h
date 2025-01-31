#pragma once
#include <string>

class Fecha
{

private:
    int _dia;
    int _mes;
    int _anio;

    void validar();

    bool esDiaValido();
    bool esMesValido();
    bool esAnioValido();

    bool esBisiesto();

    void setFechaDefault();
    void setFechaSistema();

    // 6)
    int * crearVectorDiasxMes();
    void AgregarDia();
    void RestarDia();



public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();

    std::string toString();

    //7)
    void AgregarDias(int dias);


};
