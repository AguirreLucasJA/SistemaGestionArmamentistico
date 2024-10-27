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
    void setCodigoUnico(int codigo);
    void setTipoCombustible(std::string tipoCombustible);
    void setTipoCarga(std::string tipoCarga);
    void setTipo(std::string tipo);
    void setTipoPropulsion(std::string tipoPropulsion);
    void setTipoGuia(std::string tipoGuia);
    void setHipersonico(bool hipersonico);
    void setEstado(bool estado);

    int getCantCabezasExplosivas();
    int getVelocidadMax();
    int getPeso();
    int getCodigoUnico();
    std::string getTipoCombustible();
    std::string getTipoCarga();
    std::string getTipo();
    std::string getTipoPropulsion();
    std::string getTipoGuia();
    bool gethipersonico();
    bool getEstado();

    void cargar();
    void mostrar();

private:
    int _cantCabezasExplosivas;
    int _velocidadMax;
    int _peso;
    int _codigoUnico
    char _tipoCombustible[30];
    char _tipoCarga[30];
    char _tipo[30];
    char _tipoPropulsion[30];
    char _tipoGuia[30];
    bool _hipersonico;
    bool _estado;
};
