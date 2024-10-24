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
bool Menu::menuOpcion()// MENU INGRESO USERS/ADMINS
{
    /* -Es lo primero que ejecuta tu programa, si coinciden las credenciales con un ADMIN o PAIS sera al siguiente menu que ejecutara
    -si no es ninguno de los 3 te va a decir "credenciales invalidas"
    -depende si reingresas o no es lo que va a devolver este metodo "true" o "false" y depende lo que retorne va a ejecutar nuevamente este metodo o termina tu programa
    */
    cabecera();

    ArchivoPais archivoPais;
    Pais regPais;
    Admin regAdmin;
    ArchivoAdmin archivoAdmin;

    string usuario;
    string clave;

    gotoxy (29,6);
    cout<<"INGRESO AL SISTEMA";
    gotoxy (29,7);
    cout<<"------------------";

    gotoxy (20,10);
    cout<<"INGRESE SU USUARIO: ";
    getline(cin, usuario);

    gotoxy (20,12);
    cout<<"INGRESE SU CLAVE: ";
    getline(cin, clave);

    bool ingresoAdmin = false;

    regAdmin = archivoAdmin.buscarNombre(usuario.c_str());//en el archivoAdmin va a buscar el nombre de usuario que ingresaste y te DEVUELVE EL REGISTRO.
    if (regAdmin.getUsuario() == usuario && regAdmin.getClave() == clave) //si tanto el user y pass ingresados coinciden con el regAdmin
    {
        menuPrincipalAdmin();
        ingresoAdmin = true;
    }
    else if(usuario == "admin" && clave == "admin") // sino se pregunta si se ingresa el admin HARCODEADO PARA 1RA CARGA.
    {
        menuPrincipalAdmin();
        ingresoAdmin = true;
    }
    else
    {
        regPais = archivoPais.buscarNombre(usuario.c_str());//en el archivoPais va a buscar el usuario que ingresaste.
    }
    if (regPais.getUsuario() == usuario && regPais.getClave() == clave) //si tanto el user y pass ingresados coinciden con el regPais
    {
        //menuPrincipalPais(regPais); //TODO: FALTA HACER***
    }
    else if(ingresoAdmin==false)  //si no, nunca se ingreso un admin?
    {
        cout << "Credenciales invalidas.";
        getch();//rlutil.h
    }

    int respuesta = -1;

    while(respuesta < 0 || respuesta > 1) //para ver si queres volver a ingresar al sistema.
    {
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
        cin.ignore();
        if(respuesta < 0 || respuesta > 1)//si ingresaste algo distinto q 1 � 0 te pide reingresar opcion
        {
            cout << "Ingreso incorrecto... re ingrese.." << endl;
            getch();//espera precionar tecla para continuar
        }
    }

    if(respuesta == 0)
    {
        return false;// si no quiere reingresar
    }
    else
    {
        return true;// si quiere reingresar
    }

    gotoxy (2,22);
    anykey();//espera una el ingreso de una tecla para continuar
}

/// MENU PRINCIPAL ADMINISTRADOR
void Menu::menuPrincipalAdmin() //MENU ADMIN QUE TE LLEVA AL RESTO DE LOS OTROS SUBMENU.
{
    int opcion = -1;
    while(opcion!=0)
    {

        cabecera();

        gotoxy (2,6);
        cout << "MENU ADMINISTRADOR";
        gotoxy (2,7);
        cout << "------------------";
        gotoxy (2,10);
        cout << "INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout << "1 - USUARIOS: ";
        gotoxy (2,14);
        cout << "2 - STOCK: ";
        gotoxy (2,15);
        cout << "3 - CLIENTES: ";
        gotoxy (2,16);
        cout << "4 - LISTADOS: ";
        gotoxy (2,17);
        cout << "5 - REPORTES: ";
        gotoxy (2,18);
        cout << "0 - SALIR DEL PROGRAMA: ";
        gotoxy (2,19);
        cout << "->: ";

        cin >> opcion;


        switch(opcion)
        {
        case 1:
            Usuarios();
            break;
        case 2:
            //Stock(); //TODO: FALTA HACER***
            break;
        case 3:
            //Clientes(); //TODO: FALTA HACER***
            break;
        case 4:
            //Listados(); //TODO: FALTA HACER***
            break;
        case 5:
            //Reportes(); //TODO: FALTA HACER***
            break;
        case 0:
            break;
        default:
            break;
        }
    }
}

/// MENU USUARIOS
void Menu::Usuarios()//SUBMENU ABML USUARIOS QUE ESTA DENTRO DE LAS OPCIONES DEL MENU PRINCIPAL ADMIN
{
    opcion = -1;

    while(opcion!=0) //si es ==0 vuelve al MENU PRINCIPAL ADMIN
    {

        cabecera();

        gotoxy (2,6);
        cout<<"MENU ADMINISTRADOR USUARIOS";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout<<"1 - ALTA DE USUARIO: ";
        gotoxy (2,14);
        cout<<"2 - BAJA DE USUARIO: ";
        gotoxy (2,15);
        cout<<"3 - MODIFICACION DE USUARIO: ";
        gotoxy (2,16);
        cout<<"0 - VOLVER ATRAS: ";
        gotoxy (2,17);
        cout<<"->: ";

        cin>>opcion;

        system("cls");

        switch(opcion)
        {
        case 1:
            altaUsuario();
            break;
        case 2:
            eliminarUsuario();
            break;
        case 3:
            modificarUsuario();
            break;
        case 0:
            opcion = 0;
            break;
        default:
            break;
        }
    }
}

/// ALTA USUARIO
void Menu::altaUsuario()//carga un nuevo usuario al archivo
{

    int Id;
    Admin reg;
    ArchivoAdmin ArchAdmin;
    //devuelve la cantidad -1 de los reg del archivo
    Id = ArchAdmin.contarRegistros(); //obtiene nuevo ID autonumerico.
    reg.cargar(Id);//carga un nuevo reg admin setenadole el ID obtenido
    if(ArchAdmin.grabarRegistro(reg)) //lo cargan en archivo admin
    {
        cout << "ALTA EXITOSA..." << endl;
        system("pause");
    }
    else
    {
        cout << "NO SE HA PODIDO GRABAR EL REGISTRO.";
        system("pause");
    }
}

/// LISTAR USUARIOS
void Menu::listarUsuarios()//Se utiliza dentro de MODIFICAR/ELIMINAR USUARIO
{

    Admin reg;
    ArchivoAdmin ArchAdmin;

    int cant = ArchAdmin.contarRegistros();
    Admin *admin= new Admin[cant];

    if(admin == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        system("pause");
        return;
    }

    for(int i=0; i<cant; i++)
    {
        admin[i] = ArchAdmin.leerRegistro(i);
    }

    for(int j=0; j<cant; j++)
    {
        if(admin[j].getEstado()==1)//si esta eliminado no lo muestra
        {
            admin[j].mostrar();
            cout << "------------------------------" << endl;

        }
    }
    delete [] admin;
}

/// MODIFICAR USUARIO
void Menu::modificarUsuario()//modifica usuario existente en archivo
{

    ArchivoAdmin ArchAdmin;
    int Id;
    string respuesta;
    cin.ignore();//arregla de menu usuarios el "cin>>opcion;" sino se saltea el LISTAR USUARIOS.
    cout << "LISTAR USUARIOS? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        listarUsuarios();
    }

    cout << "INGRESE EL ID A BUSCAR: ";
    cin >> Id;
    cin.ignore();//sino esta se saltea "DESEA MODIFICAR ESTE REGISTRO?"
    int pos = ArchAdmin.buscarRegistro(Id);
    Admin reg = ArchAdmin.leerRegistro(pos);
    reg.mostrar();
    if(reg.getEstado()== false)
    {
        cout << "REGISTRO DADO DE BAJA, NO SE PUEDE MODIFICAR..." << endl;
        system("pause");
        return;
    }

    cout << "DESEA MODIFICAR ESTE REGISTRO? (s / n): ";
    getline(cin, respuesta);
    string clave;
    string descripcion;
    //si le ingresas cualquier otra cosa que no sea s/S RETURN al SUBmenu USUARIOS
    if(respuesta == "s" || respuesta == "S")
    {
        cout << "MAX 30 CARACTERES -> ING NUEVA CLAVE: ";
        getline(cin, clave);
        while(!reg.setClave(clave))
        {
            cout << "ERROR SOBREPASO LIMITE DE 30 CARACTERES" << endl;
            system("pause");
            system("cls");
            cout << "REINGRESE CLAVE:";
            getline(cin, clave);
        }

        cout << "MAX 30 CARACTERES -> ING NUEVA DESCRIPCION: ";
        getline(cin, descripcion);
        while(!reg.setDescripcion(descripcion))
        {
            cout << "ERROR SOBREPASO LIMITE DE 30 CARACTERES" << endl;
            system("pause");
            system("cls");
            cout << "REINGRESE DESCRIPCION:";
            getline(cin, descripcion);
        }
    }
    else
    {
        return;
    }
    if(ArchAdmin.modificarRegistro(reg, pos)) //lo carga en el archivo y si lo pudo cargar muestra
    {
        cout << "MODIFICACION EXITOSA..." << endl;
    }
    else
    {
        cout << "ERROR, NO SE HA REALIZADO LA MODIFICACION..." << endl;
    }
    system("pause");

}

/// ELIMINAR USUARIO
void Menu::eliminarUsuario()//Eliminacion logica de usuario existente en archivo
{

    int Id;
    ArchivoAdmin ArchAdmin;
    Admin reg;

    string respuesta;
    cin.ignore();//arregla de menu usuarios el "cin>>opcion;" sino se saltea el LISTAR USUARIOS.
    cout << "LISTAR USUARIOS? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        listarUsuarios();
    }

    cout << "INGRESE EL ID A BUSCAR: ";
    cin >> Id;
    cin.ignore();//sino se saltea "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): "

    int pos = ArchAdmin.buscarRegistro(Id);
    reg = ArchAdmin.leerRegistro(pos);
    reg.mostrar();

    //verificar el estado del registro
    if(reg.getEstado()== false)
    {
        cout << "REGISTRO DADO DE BAJA, NO SE PUEDE MODIFICAR..." << endl;
        system("pause");
        return;
    }

    cout << "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        reg.setEstado(false);
    }
    else
    {
        return;
    }
    if(ArchAdmin.modificarRegistro(reg, pos))
    {
        cout << "BAJA EXITOSA..." << endl;
    }
    else
    {
        cout << "ERROR, NO SE HA REALIZADO LA BAJA..." << endl;
    }
    system("pause");
}
