#include "ArchivoUsuarioXId.h"

ArchivoUsuarioXId::ArchivoUsuarioXId()
{
    _nombreArchivo = "ARCHIVOS/USUARIOXID.DAT";////*ACA MODIFICAR EL NOMBRE DEL ARCHIVO*
    _tamReg = sizeof(UsuarioXId); ////*ACA MODIFICAR EL TAMAÑO DEL REG.*
}

bool ArchivoUsuarioXId::guardar(const UsuarioXId &registro)
{
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if(pFile == nullptr)
    {
        return false;
    }

    result = fwrite(&registro, _tamReg, 1, pFile) == 1;

    fclose(pFile);

    return result;
}

bool ArchivoUsuarioXId::guardar(const UsuarioXId &registro, int pos)
{
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile, _tamReg * pos, SEEK_SET);

    result = fwrite(&registro, _tamReg, 1, pFile) == 1;

    fclose(pFile);

    return result;
}

int ArchivoUsuarioXId::buscarXId(int id)
{
    FILE *pFile;
    UsuarioXId registro;
    int pos = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&registro, _tamReg, 1, pFile)==1)
    {
        if(registro.getId() == id)
        {
            break;
        }
        pos++;
    }

    fclose(pFile);

    if(registro.getId() == id)
    {
        return pos;
    }
    else
    {
        return -1;
    }

}

int ArchivoUsuarioXId::getCantidadReg()
{
    int totalByte;
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);
    totalByte = ftell(pFile);

    fclose(pFile);

    return totalByte / _tamReg; ///CANT TOTAL DE REG SIN DISCRIMINAR LOS ELIMINADOS
}

UsuarioXId ArchivoUsuarioXId::leer(int pos)
{
    FILE *pFile;
    UsuarioXId registro;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr)
    {
        return registro;
    }

    fseek(pFile, _tamReg * pos, SEEK_SET);

    fread(&registro, _tamReg, 1, pFile);

    fclose(pFile);

    return registro;
}

bool ArchivoUsuarioXId::leerTodos(UsuarioXId *vecRegistros, int cantidadReg)
{
    FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr)
    {
        return false;
    }

    result = fread(vecRegistros, _tamReg, cantidadReg, pFile) == cantidadReg;

    fclose(pFile);

    return result;
}

int ArchivoUsuarioXId::getNuevoId()
{
    int nuevoId;

    nuevoId =  getCantidadReg();

    return ++ nuevoId;
}

int ArchivoUsuarioXId::buscarXUsuario(std::string usuario)
{
    FILE *pFile;
    UsuarioXId registro;
    int pos = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&registro, _tamReg, 1, pFile)==1)
    {
        if(registro.getUsuario() == usuario)
        {
            break;
        }
        pos++;
    }

    fclose(pFile);

    if(registro.getUsuario() == usuario)
    {
        return pos;
    }
    else
    {
        return -1;
    }
}

