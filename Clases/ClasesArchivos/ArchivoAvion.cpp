#include "ArchivoAvion.h"

ArchivoAvion::ArchivoAvion()
{
    _nombreArchivo = "ARCHIVOS/AVION.DAT";////*ACA MODIFICAR EL NOMBRE DEL ARCHIVO*
    _tamReg = sizeof(Avion); ////*ACA MODIFICAR EL TAMA�O DEL REG.*
}

bool ArchivoAvion::guardar(const Avion &registro)
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

bool ArchivoAvion::guardar(const Avion &registro, int pos)
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

int ArchivoAvion::buscarXId(int id)
{
    FILE *pFile;
    Avion registro;
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

int ArchivoAvion::getCantidadReg()
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

Avion ArchivoAvion::leer(int pos)
{
    FILE *pFile;
    Avion registro;

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

bool ArchivoAvion::leerTodos(Avion *vecRegistros, int cantidadReg)
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

int ArchivoAvion::getNuevoId()
{
    FILE *pFile;
    Avion registro;
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
        nuevoId = 1; // Si el archivo est� vac�o / no se pudo leerlo
    }

    fclose(pFile);

    return nuevoId;
}

int ArchivoAvion::buscarXNombre(std::string nombre)
{
    FILE *pFile;
    Avion registro;
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
