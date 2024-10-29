#pragma once
#include <string>//para poder usar string
#include "Producto.h"

class Misil : public Producto
{

public:
    Misil() {};

    void setCantCabezasExplosivas(int cantCabezasExplosivas);
    void setVelocidadMax(int velocidadMax);
    void setPeso(int peso);
    void setTipoCombustible(std::string tipoCombustible);
    void setTipoCarga(std::string tipoCarga);
    void setTipoAtaque(std::string tipo);
    void setTipoPropulsion(std::string tipoPropulsion);
    void setTipoGuia(std::string tipoGuia);
    void setHipersonico(bool hipersonico);
    void setEstado(bool estado);

    int getCantCabezasExplosivas();
    int getVelocidadMax();
    int getPeso();
    std::string getTipoCombustible();
    std::string getTipoCarga();
    std::string getTipoAtaque();
    std::string getTipoPropulsion();
    std::string getTipoGuia();
    bool getHipersonico();
    bool getEstado();

    void cargar(int id);
    void mostrar();

private:
    int _cantCabezasExplosivas;
    int _velocidadMax;
    int _peso;
    char _tipoCombustible[30];
    char _tipoCarga[30];
    char _tipoAtaque[30];
    char _tipoPropulsion[30];
    char _tipoGuia[30];
    bool _hipersonico;
    bool _estado;
};
