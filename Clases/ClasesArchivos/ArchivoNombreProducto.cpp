#include "ArchivoNombreProducto.h"

ArchivoNombreProducto::ArchivoNombreProducto()
{
    _nombreArchivo = "ARCHIVOS/NOMBREPRODUCTO.DAT";////*ACA MODIFICAR EL NOMBRE DEL ARCHIVO*
    _tamReg = sizeof(NombreProducto); ////*ACA MODIFICAR EL TAMAÑO DEL REG.*
}

bool ArchivoNombreProducto::guardar(const NombreProducto &registro)
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

bool ArchivoNombreProducto::guardar(const NombreProducto &registro, int pos)
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

int ArchivoNombreProducto::getCantidadReg()
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

bool ArchivoNombreProducto::leerTodos(NombreProducto *vecRegistros, int cantidadReg)
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

int ArchivoNombreProducto::buscarXNombre(std::string nombre)
{
    FILE *pFile;
    NombreProducto registro;
    int pos = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&registro, _tamReg, 1, pFile)==1)
    {
        if(registro.getNombre() == nombre)
        {
            break;
        }
        pos++;
    }

    fclose(pFile);

    if(registro.getNombre() == nombre)
    {
        return pos;
    }
    else
    {
        return -1;
    }
}

