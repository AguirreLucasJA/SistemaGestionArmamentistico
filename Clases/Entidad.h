#pragma once
#include <string>//para poder usar string

class Entidad
{

public:
    Entidad() {};

    void setUsuario(std::string usuario);
    void setClave(std::string clave);
    void setDescripcion(std::string descripcion);
    void setTipoUsuario(int tipoUsuario);
    void setEstado(bool estado);
    void setId(int id);

    std::string getUsuario();
    std::string getClave();
    std::string getDescripcion();
    int getTipoUsuario();
    bool getEstado();
    int getId();

    //virtual void cargar(Entidad &obj); // al poner virtual es sobreescribible
    //virtual void mostrar(const Entidad &obj); // al poner virtual es sobreescribible CONST PARA EVITAR MODIFICARLO

    void cargar(int id, int tipoUsuario);
    void mostrar();

private:
    char _usuario[30];
    char _clave[30];
    char _descripcion[30];
    int _tipoUsuario;
    bool _estado;
    int _id;
};
