#include "ArchivoMisil.h"

ArchivoMisil::ArchivoMisil()
{
    _nombreArchivo = "ARCHIVOS/MISIL.DAT";////*ACA MODIFICAR EL NOMBRE DEL ARCHIVO*
    _tamReg = sizeof(Misil); ////*ACA MODIFICAR EL TAMAÑO DEL REG.*
}

bool ArchivoMisil::guardar(const Misil &registro)
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

bool ArchivoMisil::guardar(const Misil &registro, int pos)
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

int ArchivoMisil::buscarXId(int id)
{
    FILE *pFile;
    Misil registro;
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

int ArchivoMisil::getCantidadReg()
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

Misil ArchivoMisil::leer(int pos)
{
    FILE *pFile;
    Misil registro;

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

bool ArchivoMisil::leerTodos(Misil *vecRegistros, int cantidadReg)
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

int ArchivoMisil::getNuevoId()
{
    FILE *pFile;
    Misil registro;
    int nuevoId = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr)
    {
        return 1; //si no pudo abrir el archivo
    }

    fseek(pFile, - _tamReg, SEEK_END);

    if (fread(&registro, _tamReg, 1, pFile) == 1)
    {
        nuevoId = registro.getId() +1;
    }

    else
    {
        nuevoId = 1; // Si el archivo está vacío / no se pudo leerlo
    }

    fclose(pFile);

    return nuevoId;
}

int ArchivoMisil::buscarXNombre(std::string nombre)
{
    FILE *pFile;
    Misil registro;
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

