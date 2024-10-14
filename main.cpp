#include "Cabeceras.h"

using namespace std;

int main()
{
    Menu sistema;
    bool continuar = true;

    while(continuar)
    {
        continuar = sistema.menuOpcion();// si devuelve falso Se termina el programa.
    }

    return 0;
}
