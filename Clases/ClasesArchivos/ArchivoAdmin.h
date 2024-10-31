#pragma once
#include <string>
#include "../Admin.h"



class ArchivoAdmin
{
public:
    ArchivoAdmin(); //construye con nombre del Archivo y tamaño del REG. /
    bool guardar(const Admin &registro);//Agrega un Admin
    bool guardar(const Admin &registro, int pos);//Modifica un Admin en una posicion
    int buscar(int id);//busca un Admin por su id
    int getCantidadReg();//Devuelve cantidad de Registros
    Admin leer(int pos);//Lee un Admin en una posicion
    bool leerTodos(Admin *vecRegistros, int cantidadReg);//Lee todos
    int getNuevoId();//Devuelve id AUTONUMERICO
    Admin buscarXUsuario(std::string usuario);
    //bool buscarClave(std::string clave);

   // bool grabarRegistro(Admin reg);
   // Admin leerRegistro(int pos);
   // int buscarRegistro(int Id);
   // int contarRegistros();
   // bool modificarRegistro(Admin reg, int pos);
   // bool listarRegistros();

private:
    std::string _nombreArchivo;
    int _tamReg;
};

//Admin ArchivoAdmin::buscarNombre(const char *n)
/*{
    FILE *pf;
    Admin reg;
    Admin aux;

    pf = fopen(_nombre, "rb");

    if(pf == NULL)
    {
        cout << "NO PUEDE ABRIRSE EL ARCHIVO: " << _nombre << " EN MODO RB - buscarRegistro()" << endl;
        system("pause");
        return reg;
    }

    while(fread(&reg, sizeof(Admin), 1, pf))
    {
        if((strcmp(reg.getUsuario().c_str(), n) == 0))
        {
            fclose(pf);
            aux.setUsuario(reg.getUsuario());
            aux.setClave(reg.getClave());
            aux.setDescripcion(reg.getDescripcion());
            aux.setTipoUsuario(reg.getTipoUsuario());
            aux.setEstado(reg.getEstado());
            aux.setId(reg.getId());
            return aux;
        }
    }

    fclose(pf);
    return reg;
}*/

//bool ArchivoAdmin::grabarRegistro(Admin reg)
/*{
    FILE *pf;

    pf = fopen(_nombre, "ab");

    if(pf == NULL)
    {
        cout << "NO PUEDE ABRIRSE EL ARCHIVO EN grabarRegistro()" << endl;
        return true;
    }

    if(fwrite(&reg, sizeof(reg), 1, pf))
    {
    }
    else
    {
        cout << "PROBLEMAS AL GRABAR EL REGISTRO" << endl;
        fclose(pf);
        return true;
    }

    fclose(pf);
    return true;
}*/

//Admin ArchivoAdmin::leerRegistro(int pos)
/*{
    FILE *pf;
    Admin reg;

    pf = fopen(_nombre, "rb");

    if(pf == NULL)
    {
        cout << "NO PEUDE ABRIRSE EL ARCHIVO EN leerRegistro()" << endl;
        return reg;
    }

    fseek(pf, sizeof(reg)* pos, 0);
    fread(&reg, sizeof(reg), 1, pf);
    fclose(pf);
    return reg;
}*/

//int ArchivoAdmin::buscarRegistro(int Id)
/*{
    FILE *pf;
    Admin reg;
    int c = 0;

    pf = fopen(_nombre, "rb");

    if(pf == NULL)
    {
        cout << "NO PUEDE ABRIRSE EL ARCHIVO EN leerRegistro()" << endl;
        return -1;
    }

    while(fread(&reg, sizeof(reg), 1, pf))
    {
        if(reg.getId() == Id)
        {
            return c;
        }
        c++;
    }

    fclose(pf);
    return -1;
}*/

//int ArchivoAdmin::contarRegistros()
/*{
    FILE *pf;
    Admin reg;
    //arranca en -1 para indexar.
    int regContador = -1, tam;

    pf = fopen(_nombre, "rb");

    if(pf == NULL)
    {
        cout << "NO PUEDE ABRIRSE EL ARCHIVO EN contarRegistro()" << endl;
        return 0;
    }

    fseek(pf, 0, 2);

    tam = ftell(pf);

    regContador = tam / sizeof(reg);

    fclose(pf);
    return regContador;
}*/

//bool ArchivoAdmin::modificarRegistro(Admin reg, int pos)
/*{
    FILE *pf;

    pf = fopen(_nombre, "rb+");

    if(pf == NULL)
    {
        cout << "NO PEUDE ABRIRSE EL ARCHIVO EN grabarRegistro()" << endl;
        return true;
    }

    fseek(pf, pos*sizeof(reg), 0);

    if(fwrite(&reg, sizeof(reg), 1, pf))
    {
    }
    else
    {
        cout << "PROBLEMAS AL GRABAR EL REGISTRO" << endl;
        fclose(pf);
        return true;
    }

    fclose(pf);
    return true;
}*/

//bool ArchivoAdmin::listarRegistros()
/*{
    FILE *pf;
    Admin reg;

    pf = fopen(_nombre, "rb");

    if(pf == NULL)
    {
        cout << "NO PEUDE ABRIRSE EL ARCHIVO EN leerRegistro()" << endl;
        return -1;
    }

    while(fread(&reg, sizeof(reg), 1, pf) == 1)
    {
        if(reg.getEstado() == true)
        {
            reg.mostrar();
        }
    }

    fclose(pf);
    return 1;
}*/

