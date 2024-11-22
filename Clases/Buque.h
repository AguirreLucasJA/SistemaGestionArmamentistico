#pragma once
#include <string>//para poder usar string
#include "Producto.h"

class Buque : public Producto
{

public:
    Buque() {};

    void setCantTorretas(int cantTorretas);
    void setVelocidadMax(int velocidadMax);
    void setPeso(int peso);
    void setTipo(std::string tipo);
    void setBlindaje(std::string blindaje);
    void setTipoPropulsion(std::string tipoPropulsion);
    void setManiobrabilidad(std::string maniobrabilidad);
    void setAmetralladora(bool ametralladora);

    int getCantTorretas();
    int getVelocidadMax();
    int getPeso();
    std::string getTipo();
    std::string getBlindaje();
    std::string getTipoPropulsion();
    std::string getManiobrabilidad();
    bool getAmetralladora();

    void cargar(int id);
    void mostrar();

private:
    int _cantTorretas;
    int _velocidadMax;
    int _peso;
    char _tipo[30];
    char _blindaje[30];
    char _tipoPropulsion[30];
    char _maniobrabilidad[30];
    bool _ametralladora;
};
