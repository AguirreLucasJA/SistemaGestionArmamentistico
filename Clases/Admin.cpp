#include "Admin.h"
#include <iostream>//para los cout, cin.
using namespace std;//para no andar escribiendo "std::cout"

//SETTERS
void Admin::setSueldo(float sueldo)
{
    _sueldo = sueldo;
}

//GETTERS
float Admin::getSueldo()
{
    return _sueldo;
}

//METODOS
void Admin::cargar(int id)
{
    float sueldo;

    Entidad::cargar(id, 0);

    cout << "ING SUELDO: $";
    cin >> sueldo;
    setSueldo(sueldo);
}

void Admin::mostrar()
{
    Entidad::mostrar();
    cout << "SUELDO: " << getSueldo() << endl;
}


