#pragma once

class Entidad
{

public:
    Entidad() {};

    void setUsuario(char* usuario);
    void setClave(char* clave);
    void setDescripcion(char* descripcion);
    void setTipoUsuario(int tipoUsuario);
    void setEstado(bool estado);
    void setId(int id);

    char* getUsuario();
    char* getClave();
    char* getDescripcion();
    int getTipoUsuario();
    bool getEstado();
    int getId();

private:
    char _usuario[30];
    char _clave[30];
    char _descripcion[30];
    int _tipoUsuario;
    bool _estado;
    int _id;
};
