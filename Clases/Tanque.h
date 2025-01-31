#pragma once
#include <string>//para poder usar string
#include "Producto.h"

class Tanque : public Producto
{

public:
    Tanque() {};

    void setAlcanceOperativo(int alcanceOperativo);
    void setPeso(int peso);
    void setTorretaCalibre(int torretaCalibre);
    void setVelocidadMax(int velocidad);
    void setAmetralladora(bool ametralladora);
    void setTorretaBlindada(bool torretablindada);
    void setAntiTanque(bool antiTanque);
    void setLargoAlcance(bool largoAlcance);
    void setOcultamiento(bool ocultamiento);
    void setRangoVision(std::string rangoVision);
    void setTipoBlindaje(std::string tipoBlindaje);
    void setMovilidad(std::string movilidad);
    void setPrecision(std::string precision);

    int getAlcanceOperativo();
    int getPeso();
    int getTorretaCalibre();
    int getVelocidad();
    bool getAmetralladora();
    bool getTorretaBlindada();
    bool getAntiTanque();
    bool getLargoAlcance();
    bool getOcultamiento();
    std::string getRangoVision();
    std::string getTipoBlindaje();
    std::string getMovilidad();
    std::string getPrecision();

    void cargar(int id);
    void mostrar();

private:
    int _alcanceOperativo;
    int _peso;
    int _torretaCalibre;
    int _velocidad;
    bool _ametralladora;
    bool _torretaBlindada;
    bool _antiTanque;
    bool _largoAlcance;
    bool _ocultamiento;
    char _rangoVision[30];
    char _tipoBlindaje[30];
    char _movilidad[30];
    char _precision[30];
};
