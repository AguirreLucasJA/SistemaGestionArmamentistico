#include "ArchivoPais.h"

ArchivoPais::ArchivoPais()
{
    _nombreArchivo = "ARCHIVOS/PAIS.DAT";////*ACA MODIFICAR EL NOMBRE DEL ARCHIVO*
    _tamReg = sizeof(Pais); ////*ACA MODIFICAR EL TAMAÑO DEL REG.*
}

bool ArchivoPais::guardar(const Pais &registro)
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

bool ArchivoPais::guardar(const Pais &registro, int pos)
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

int ArchivoPais::buscarXId(int id)
{
    FILE *pFile;
    Pais registro;
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

int ArchivoPais::getCantidadReg()
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

Pais ArchivoPais::leer(int pos)
{
    FILE *pFile;
    Pais registro;

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

bool ArchivoPais::leerTodos(Pais *vecRegistros, int cantidadReg)
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

int ArchivoPais::getNuevoId()
{
    int cantidadReg = getCantidadReg();

    if(cantidadReg>0)
    {
        return leer(cantidadReg-1).getId()+1;
    }
    else
    {
        return 0; ///*ACA MODIFICAR CON QUE NUMERO DE CODIGO EMPEZAR EL AUTONUMERICO*
    }
}

int ArchivoPais::buscarXUsuario(std::string usuario)
{
    FILE *pFile;
    Pais registro;
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
