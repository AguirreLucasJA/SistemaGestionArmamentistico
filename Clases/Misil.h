#pragma once
#include <string>//para poder usar string
#include "Producto.h"

class Misil : public Producto
{

public:
    Misil(){};

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
















};
