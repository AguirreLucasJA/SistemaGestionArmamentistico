#include "ArchivoDetalleVenta.h"

ArchivoDetalleVenta::ArchivoDetalleVenta()
{
    _nombreArchivo = "ARCHIVOS/DETALLEVENTA.DAT";////*ACA MODIFICAR EL NOMBRE DEL ARCHIVO*
    _tamReg = sizeof(DetalleVenta); ////*ACA MODIFICAR EL TAMAÑO DEL REG.*
}

bool ArchivoDetalleVenta::guardar(const DetalleVenta &registro)
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

bool ArchivoDetalleVenta::guardar(const DetalleVenta &registro, int pos)
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

int ArchivoDetalleVenta::buscarXId(int id)
{
    FILE *pFile;
    DetalleVenta registro;
    int pos = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&registro, _tamReg, 1, pFile)==1)
    {
        if(registro.getIdVenta() == id)
        {
            break;
        }
        pos++;
    }

    fclose(pFile);

    if(registro.getIdVenta() == id)
    {
        return pos;
    }
    else
    {
        return -1;
    }

}

int ArchivoDetalleVenta::getCantidadReg()
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

DetalleVenta ArchivoDetalleVenta::leer(int pos)
{
    FILE *pFile;
    DetalleVenta registro;

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

bool ArchivoDetalleVenta::leerTodos(DetalleVenta *vecRegistros, int cantidadReg)
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

bool ArchivoDetalleVenta::grabarRegistros(DetalleVenta *vecRegistros, int cantidadReg)
{
    FILE *pFile;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr)
    {
        return false;
    }

    for (int i = 0; i < cantidadReg; i++)
    {
        if (fwrite(&vecRegistros[i], _tamReg, 1, pFile) != 1)
        {
            fclose(pFile);
            return false;
        }
    }

    fclose(pFile);
    return true;
}

int ArchivoDetalleVenta::buscarXNombreProducto(std::string nombreProducto)
{
    FILE *pFile;
    DetalleVenta registro;
    int pos = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr)
    {
        return -1;
    }

    while(fread(&registro, _tamReg, 1, pFile)==1)
    {
        if(registro.getNombreProducto() == nombreProducto)
        {
            break;
        }
        pos++;
    }

    fclose(pFile);

    if(registro.getNombreProducto() == nombreProducto)
    {
        return pos;
    }
    else
    {
        return -1;
    }
}
