#include <iostream>//cout
#include <stdio.h>//printf
#include <windows.h>//HANDLE
#include "rlutil.h"//cls

using namespace std;//std::
using namespace rlutil;//rlutil::

#include "Menu.h"
#include "Admin.h"
#include "Pais.h"

#include "ClasesArchivos/ArchivoAdmin.h"
#include "ClasesArchivos/ArchivoPais.h"



/// DIBUJAR RECUADRO
void Menu::dibujarCuadro(int x1, int y1, int x2, int y2)
{
    int i;

    for(i=x1; i<x2; i++)
    {
        gotoxy(i, y1);
        printf("\304"); // LINEA HORIZONTAL SUPERIOR
        gotoxy(i, y2);
        printf("\304"); // LINEA HORIZONTAL INFERIOR
    }

    for(i=y1; i<y2; i++)
    {
        gotoxy(x1, i);
        printf("\263"); // LINEA VERTICAL IZQUIERDA
        gotoxy(x2, i);
        printf("\263"); // LINEA VERTICAL DERECHA
    }

    gotoxy(x1, y1);
    printf("\332");
    gotoxy(x1, y2);
    printf("\300");
    gotoxy(x2, y1);
    printf("\277");
    gotoxy(x2, y2);
    printf("\331");
}

/// UBICACION
void Menu::gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
/// CABECERA
void Menu::cabecera()
{
    cls();//rlutil.h
    system("mode con: cols=80 lines=25"); // DEFINE DIMENSIONES VENTANA PROGRAMA 80 COLUMNAS 25 FILAS
    system("COLOR 70"); // COLOR FONDO y COLOR LETRAS
    dibujarCuadro(0, 0, 78, 24); // DIBUJO CUADRO PRINCIPAL
    dibujarCuadro(1, 1, 77, 3); // DIBUJO CUADRO TITULO
    gotoxy(22, 2);
    cout << "SGA - SISTEMA GESTION ARMAMENTISTICO" << endl;
    gotoxy(29, 3);
    cout << "PROGRAMANDO TU DEFENSA" << endl;
}
/// MENU INGRESO
bool Menu::menuOpcion()  // MENU INGRESO USERS/ADMINS
{
    /* -Es lo primero que ejecuta tu programa, si coinciden las credenciales con un ADMIN o PAIS sera al siguiente menu que ejecutara
    -si no es ninguno de los 3 te va a decir "credenciales invalidas"
    -depende si reingresas o no es lo que va a devolver este metodo "true" o "false" y depende lo que retorne va a ejecutar nuevamente este metodo o termina tu programa
    */
    cabecera();

    char user[15];
    char pass[15];

    ArchivoPais archivoPais;
    Pais regPais;
    Admin regAdmin;
    ArchivoAdmin archivoAdmin;

    gotoxy (29,6);
    cout<<"INGRESO AL SISTEMA";
    gotoxy (29,7);
    cout<<"------------------";

    gotoxy (20,10);
    cout<<"INGRESE SU USUARIO: ";
    cin>>user;

    gotoxy (20,12);
    cout<<"INGRESE SU CLAVE: ";
    cin>>pass;

    string nombre = user;
    string clave = pass;
    bool ingresoAdmin = false;

    regAdmin = archivoAdmin.buscarNombre(user);//en el archivoAdmin va a buscar el nombre de usuario que ingresaste y te DEVUELVE EL REGISTRO.
    if ((strcmp(regAdmin.getUsuario(), user) == 0)&&(strcmp(regAdmin.getClave(), pass)== 0)) //si tanto el user y pass ingresados coinciden con el regAdmin
    {
        //menuPrincipalAdmin(); FALTA HACER***
        ingresoAdmin = true;
    }
    else if(((nombre == "admin")&&(clave == "admin"))) // sino se pregunta si se ingresa el admin HARCODEADO PARA 1RA CARGA.
    {
        //menuPrincipalAdmin(); FALTA HACER***
        ingresoAdmin = true;
    }
    else
    {
        regPais = archivoPais.buscarNombre(user);//en el archivoPais va a buscar el usuario que ingresaste.
    }
    if ((strcmp(regPais.getUsuario(), user) == 0)&&(strcmp(regPais.getClave(), pass)== 0)) //si tanto el user y pass ingresados coinciden con el regPais
    {
        //menuPrincipalPais(regPais); FALTA HACER***
    }
    else if(ingresoAdmin==false)  //si no, nunca se ingreso un admin?
    {
        gotoxy(2,14);
        cout << "Credenciales invalidas.";
        getch();//rlutil.h
    }

     int respuesta = -1;

     while(respuesta < 0 || respuesta > 1){//para ver si queres volver a ingresar al sistema.
        system("cls");
        cabecera();
        gotoxy (29,6);
        cout<<"REINGRESAR AL SISTEMA?: ";
        gotoxy (29,7);
        cout<<"0. NO";
        gotoxy (29,8);
        cout<<"1. SI";
        gotoxy (29,10);
        cout<<"OPCION: ";
        cin>>respuesta;
        if(respuesta < 0 || respuesta > 1){
            cout << "Ingreso incorrecto... re ingrese.." << endl;
            getch();
        }
    }

    if(respuesta == 0){
        return false;// si no quiere reingresar
    } else{
        return true;// si quiere reingresar
    }

    gotoxy (2,22);
    anykey();//espera una el ingreso de una tecla para continuar
}
