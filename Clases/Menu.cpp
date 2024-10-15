#include <iostream>//cout
#include <stdio.h>//printf
#include <windows.h>//HANDLE
#include "rlutil.h"//cls

using namespace std;//std::
using namespace rlutil;//rlutil::

#include "Menu.h"

/// DIBUJAR RECUADRO
void Menu::dibujarCuadro(int x1, int y1, int x2, int y2){
    int i;

    for(i=x1; i<x2; i++){
        gotoxy(i, y1);
        printf("\304"); // LINEA HORIZONTAL SUPERIOR     //304
        gotoxy(i, y2);
        printf("\304"); // LINEA HORIZONTAL INFERIOR
    }

    for(i=y1; i<y2; i++){
        gotoxy(x1, i);
        printf("\263"); // LINEA VERTICAL IZQUIERDA
        gotoxy(x2, i);
        printf("\263"); // LINEA VERTICAL DERECHA
    }

    gotoxy(x1, y1);
    printf("\332");       //332
    gotoxy(x1, y2);
    printf("\300");        //300
    gotoxy(x2, y1);
    printf("\277");
    gotoxy(x2, y2);
    printf("\331");
}

/// UBICACION
void Menu::gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
/// CABECERA
void Menu::cabecera(){
    cls();//rlutil.h
    system("mode con: cols=80 lines=25"); // DEFINE DIMENSIONES VENTANA PROGRAMA 80 COLUMNAS 25 FILAS
    system("COLOR 70"); // COLOR FONDO y COLOR LETRAS  //70
    dibujarCuadro(0, 0, 78, 24); // DIBUJO CUADRO PRINCIPAL
    dibujarCuadro(1, 1, 77, 3); // DIBUJO CUADRO TITULO
    gotoxy(22, 2);
    cout << "SGA - SISTEMA GESTION ARMAMENTISTICO" << endl;
    gotoxy(29, 3);
    cout << "PROGRAMANDO TU DEFENSA" << endl;
}
/// MENU INGRESO
bool Menu::menuOpcion(){ // MENU INGRESO USERS/ADMINS
    /* -Es lo primero que ejecuta tu programa, si coinciden las credenciales con un ADMIN o PAIS sera al siguiente menu que ejecutara
    -si no es ninguno de los 3 te va a decir "credenciales invalidas"
    -depende si reingresas o no es lo que va a devolver este metodo "true" o "false" y depende lo que retorne va a ejecutar nuevamente este metodo o termina tu programa
    */
    cabecera();

    char user[15];
    char pass[15];

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
    }
