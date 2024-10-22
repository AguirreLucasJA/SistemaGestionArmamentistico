#pragma once
#include<iostream>//!
#include<string.h>//!
#include"../Pais.h"//!
using namespace std;//!

class ArchivoPais{
    private:
            char Nombre[30];
    public:
            ArchivoPais(const char* n = "ARCHIVOS/PAISES.DAT"){
                strcpy(Nombre, n);
            }
            bool grabarRegistro(Pais reg);
            Pais leerRegistro(int pos);
            Pais buscarNombre(const char *n);
            int buscarRegistro(int Id);
            int contarRegistros();
            bool modificarRegistro(Pais reg, int pos);
            bool listarRegistros();
};

bool ArchivoPais::grabarRegistro(Pais reg){
    FILE *pf;

    pf = fopen(Nombre, "ab");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO: " << Nombre << " EN MODO AB - grabarRegistros()" << endl;
        system("pause");
        return true;
    }

    if(fwrite(&reg, sizeof(reg), 1, pf)){
    }
    else{
        cout << "PROBLEMAS AL GRABAR EL REGISTRO" << endl;
        fclose(pf);
        return true;
    }

    fclose(pf);
    return true;
}

Pais ArchivoPais::leerRegistro(int pos){
    FILE *pf;
    Pais reg;

    pf = fopen(Nombre, "rb");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO: " << Nombre << " EN MODO RB - leerRegistro()" << endl;
        system("pause");
        return reg;
    }

    fseek(pf, sizeof(reg)* pos, 0);
    fread(&reg, sizeof(reg), 1, pf);
    fclose(pf);
    return reg;
}

int ArchivoPais::buscarRegistro(int Id){
    FILE *pf;
    Pais reg;
    int c = 0;

    pf = fopen(Nombre, "rb");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO: " << Nombre << " EN MODO RB - buscarRegistro()" << endl;
        system("pause");
        return -1;
    }

    while(fread(&reg, sizeof(reg), 1, pf)){
        if(reg.getId() == Id){
            return c;
        }
        c++;
    }

    fclose(pf);
    return -1;
}

int ArchivoPais::contarRegistros(){
    FILE *pf;
    Pais reg;
    int regContador = -1, tam;

    pf = fopen(Nombre, "rb");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO EN contarRegistro()" << endl;
        return 0;
    }

    fseek(pf, 0, 2);

    tam = ftell(pf);

    regContador = tam / sizeof(reg);

    fclose(pf);
    return regContador;
}

bool ArchivoPais::modificarRegistro(Pais reg, int pos){
    FILE *pf;

    pf = fopen(Nombre, "rb+");

    if(pf == NULL){
         cout << "NO PUEDE ABRIRSE EL ARCHIVO: " << Nombre << " EN MODO RB+ - modificarRegistro()" << endl;
        system("pause");
        return true;
    }

    fseek(pf, pos*sizeof(reg), 0);

    if(fwrite(&reg, sizeof(reg), 1, pf)){
        cout<<endl;
    }
    else{
        cout << "PROBLEMAS AL MODIFICAR REGISTRO" << endl;
        fclose(pf);
        return true;
    }

    fclose(pf);
    return true;
}

bool ArchivoPais::listarRegistros(){
    FILE *pf;
    Pais reg;

    pf = fopen(Nombre, "rb");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO: " << Nombre << " EN MODO RB - listarRegistros()" << endl;
        system("pause");
        return -1;
    }

    while(fread(&reg, sizeof(reg), 1, pf) == 1){
        if(reg.getEstado() == true){
            reg.mostrar();
        }
    }

    fclose(pf);
    return 1;
}

Pais ArchivoPais::buscarNombre(const char *n){
    FILE *pf;
    Pais reg;
    Pais aux;

    pf = fopen(Nombre, "rb");

    if(pf == NULL){
        cout << "NO PUEDE ABRIRSE EL ARCHIVO: " << Nombre << " EN MODO RB - buscarNombre()" << endl;
        system("pause");
        return reg;
    }

    while(fread(&reg, sizeof(Pais), 1, pf)){
        if(strcmp(reg.getUsuario().c_str(), n) == 0){
            fclose(pf);
            aux.setUsuario(reg.getUsuario());
            aux.setClave(reg.getClave());
            aux.setDescripcion(reg.getDescripcion());
            aux.setTipoUsuario(reg.getTipoUsuario());
            aux.setEstado(reg.getEstado());
            aux.setId(reg.getId());
            aux.setDineroCaja(reg.getDineroCaja());

            return aux;
        }
    }

    fclose(pf);
    return reg;
}
