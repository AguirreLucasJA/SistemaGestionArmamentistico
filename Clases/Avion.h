#pragma once
#include <string>//para poder usar string
#include "Producto.h"


class Avion : public Producto
{

public:
    Avion() {};

    void setVelocidadMax(int velocidadMax);
    void setCantMisiles(int cantMisiles);
    void setAlcanceOperativo(int alcanceOperativo);
    void setAmetralladora(bool ametralladora);
    void setTipo(std::string tipo);
    void setProposito(std::string proposito);
    void setTamanio(std::string tamanio);
    void setManiobrabilidad(std::string maniobrabilidad);

    int getsetVelocidadMax();
    int getsetCantMisiles();
    int getAlcanceOperativo();
    bool getAmetralladora();
    std::string getTipo();
    std::string getProposito();
    std::string getTamanio();
    std::string getManiobrabilidad();


    //void cargar(int id);
    //void mostrar();

private:
    int _velocidadMax;
    int _cantMisiles;
    int _alcanceOperativo;
    bool _ametralladora;
    char _tipo[30];
    char _proposito[30];
    char _tamanio[30];
    char _maniobrabilidad[30];

};
