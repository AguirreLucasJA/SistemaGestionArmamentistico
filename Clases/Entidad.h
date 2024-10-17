#pragma once

class Entidad
{

public:
    Entidad() {};

    void setUsuario(char* _Usuario);
    void setClave(char* _Clave);
    void setDescripcion(char* _Descripcion);
    void setTipoUsuario(int _tipoUsuario);
    void setEstado(bool _Estado);
    void setId(int _Id);

    char* getUsuario();
    char* getClave();
    char* getDescripcion();
    int getTipoUsuario();
    bool getEstado();
    int getId();

private:
    char Usuario[30];
    char Clave[30];
    char Descripcion[30];
    int TipoUsuario;
    bool Estado;
    int Id;
};
