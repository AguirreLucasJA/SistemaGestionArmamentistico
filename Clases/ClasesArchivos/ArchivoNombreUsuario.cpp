#include "ArchivoNombreUsuario.h"

ArchivoNombreUsuario::ArchivoNombreUsuario()
{
    _nombreArchivo = "ARCHIVOS/NOMBREUSUARIO.DAT";////*ACA MODIFICAR EL NOMBRE DEL ARCHIVO*
    _tamReg = sizeof(NombreUsuario); ////*ACA MODIFICAR EL TAMAÑO DEL REG.*
}

bool ArchivoNombreUsuario::guardar(const NombreUsuario &registro)
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

bool ArchivoNombreUsuario::guardar(const NombreUsuario &registro, int pos)
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

int ArchivoNombreUsuario::getCantidadReg()
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

bool ArchivoNombreUsuario::leerTodos(NombreUsuario *vecRegistros, int cantidadReg)
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

int ArchivoNombreUsuario::buscarXUsuario(std::string usuario)
{
    FILE *pFile;
    NombreUsuario registro;
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
