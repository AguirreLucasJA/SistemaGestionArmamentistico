#include <iostream>//cout
#include <stdio.h>//printf
#include <windows.h>//HANDLE
#include "rlutil.h"//cls

using namespace std;//std::
using namespace rlutil;//rlutil::

#include "Validar.h"

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
            Stock();
            break;
        case 3:
            Clientes();
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
        cout<<"MENU USUARIOS ADMINISTRADORES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout<<"1 - ALTA DE ADMINISTRADOR: ";
        gotoxy (2,14);
        cout<<"2 - BAJA DE ADMINISTRADOR: ";
        gotoxy (2,15);
        cout<<"3 - MODIFICACION DE ADMINISTRADOR: ";
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

/// LISTAR USUARIOS/CLIENTES
void Menu::listarUsuariosYClientes()//Se utiliza dentro de MODIFICAR/ELIMINAR USUARIO/CLIENTES
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
    Validar validar;
    ArchivoAdmin ArchAdmin;
    int Id;
    string respuesta;
    cin.ignore();//arregla de menu usuarios el "cin>>opcion;" sino se saltea el LISTAR USUARIOS.
    cout << "LISTAR USUARIOS? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        listarUsuariosYClientes();
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
        while(!validar.esStringValido(clave,30))
        {
            cout << "ERROR SOBREPASO LIMITE DE 30 CARACTERES" << endl;
            system("pause");
            system("cls");
            cout << "REINGRESE CLAVE:";
            getline(cin, clave);
        }
        reg.setClave(clave);

        cout << "MAX 30 CARACTERES -> ING NUEVA DESCRIPCION: ";
        getline(cin, descripcion);
        while(!validar.esStringValido(descripcion,30))
        {
            cout << "ERROR SOBREPASO LIMITE DE 30 CARACTERES" << endl;
            system("pause");
            system("cls");
            cout << "REINGRESE DESCRIPCION:";
            getline(cin, descripcion);
        }
        reg.setDescripcion(descripcion);
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
        listarUsuariosYClientes();
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

/// MENU CLIENTES
void Menu::Clientes()
{
    opcion = -1;

    while(opcion!=0)
    {

        cabecera();

        gotoxy (2,6);
        cout<<"MENU USUARIOS CLIENTES PAISES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout<<"1 - ALTA DE PAIS: ";
        gotoxy (2,14);
        cout<<"2 - BAJA DE PAIS: ";
        gotoxy (2,15);
        cout<<"3 - MODIFICACION DE PAIS: ";
        gotoxy (2,16);
        cout<<"0 - VOLVER ATRAS: ";
        gotoxy (2,17);
        cout<<"->: ";

            cin>>opcion;

        system("cls");

        switch(opcion)
        {

        case 1:
            //altaCliente();
            break;

        case 2:
            //eliminarCliente();
            break;

        case 3:
            //modificarCliente();
            break;

        case 0:
            opcion = 0;
            break;

        default:

            break;
        }
    }

}

/// MENU STOCK
void Menu::Stock(){
    int opcion;

    cabecera();

    gotoxy(30, 6);
    cout << "MENU STOCK";
    gotoxy(30, 8);
    cout << "1 - MISILES";
    gotoxy(30, 10);
    cout << "2 - AVIONES";
    gotoxy(30, 12);
    cout << "3 - BUQUES";
    gotoxy(30, 14);
    cout << "4 - TANQUES";
    gotoxy(30, 16);
    cout << "0 - VOLVER";
    gotoxy(30, 18);
    cout << "INGRESE UNA OPCION: ";
    cin >> opcion;

    switch(opcion) {
        case 1:
            StockMisiles();
            break;

        case 2:
            StockAviones();
            break;

        case 3:
            StockBuques();
            break;

        case 4:
            StockTanques();
            break;

        case 0:
        	return;

            break;

        default:
                cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
                system("pause");
                break;
    }
}


/// STOCK MISIL
//SUBMENU ABML MISIL QUE ESTA DENTRO DE LAS OPCIONES DEL MENU STOCK ADMIN
void Menu::StockMisiles() {
   // Misil misil; TODO: FALTA HACER****
    //ArchivoMisil ArchMisil; TODO: FALTA HACER****
    char respuesta;
    int opcion;

    while (true) {
        system("cls");
        cabecera();

        gotoxy (2,6);
        cout<<"MENU MISILES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";
        gotoxy(2,13);
        cout << "1 - ALTA MISIL" << endl;
        gotoxy(2,14);
        cout << "2 - LISTAR MISILES" << endl;
        gotoxy(2,15);
        cout << "3 - MODIFICAR MISIL" << endl;
        gotoxy(2,16);
        cout << "4 - AGREGAR A STOCK" << endl;
        gotoxy(2,17);
        cout << "5 - BAJA MISIL" << endl;
        gotoxy(2,18);
        cout << "0 - VOLVER ATRAS" << endl;
        gotoxy(2,19);
        cout << "->: ";
        cin >> opcion;

        switch (opcion) {

            case 1: {
                 cls();
                cabecera();
                gotoxy(29, 5);
                cout << "---------------";
                gotoxy(30, 6);
                cout << "CARGAR MISIL" << endl;
                gotoxy(29, 7);
                cout << "---------------";

				/*
                misil.cargar(); // TODO: FALTA HACER***
                ArchMisil.escribirEnDisco(misil);

                cls();
                cabecera();
                gotoxy(22, 6);
                cout << "MISIL CARGADO EXITOSAMENTE." << endl;
                */
                break;
            }

            case 2: {

                cls();
                cabecera();
                gotoxy(30, 6);
                cout << "LISTAR REGISTROS DE MISILES";
                gotoxy(29, 7);
                cout << "---------------";
				/*
                ArchMisil.listarRegistros(); TODO: FALTA HACER***
                */
                break;
            }

            case 3: {
                cls();
                cabecera();
                gotoxy(29, 5);
                cout << "---------------";
                gotoxy(30, 6);
                cout << "MODIFICAR MISIL";
                gotoxy(29, 7);
                cout << "---------------";
                gotoxy(23, 10);
                cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
                int codigo;
                cin >> codigo;
				/*
                int posicion = ArchMisil.buscarRegistro(codigo);
                misil = ArchMisil.leerRegistro(posicion); TODO: FALTA HACER***

                misil.mostrar();
                system("pause");

                cls();
                cabecera();
                int respuesta;
                cout << "DESEA MODIFICAR ESTE PRODUCTO?(1-SI / 2-NO) ";
                cin >> respuesta;
                if(respuesta==1){
                    misil.cargar();
                    if(ArchMisil.ModificarEnDisco(misil, posicion)){
                        cls();
                        cabecera();
                        cout << "MODIFICACION EXITOSA...";
                        system("pause");
                    } else {
                        cls();
                        cabecera();
                        cout << "NO SE HA PODIDO MODIFICAR...";
                        system("pause");
                    }
                }*/
                break;
            }

            case 4:{

                cls();
                cabecera();

                gotoxy(29, 5);
                cout << "---------------";
                gotoxy(30, 6);
                cout << "AGREGAR STOCK";
                gotoxy(29, 7);
                cout << "---------------";

                gotoxy(23, 10);
                cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
                int codigo;
                cin >> codigo;
				/*
                int posicion = ArchMisil.buscarRegistro(codigo);
                misil = ArchMisil.leerRegistro(posicion); // TODO: FALTA HACER***

                cls();
                cabecera();
                misil.mostrar();
                system("pause");

                cls();
                cabecera();
                int respuesta;
                cout << "DESEA ANIADIR STOCK A ESTE PRODUCTO?(1-SI / 2-NO) ";
                cin >> respuesta;
                if(respuesta==1){
                    cout << "INGRESE LA CANTIDAD: ";
                    int cantidad;
                    cin >> cantidad;
                    misil.setStock((misil.getStock() + cantidad));
                    ArchMisil.modificarStock(misil, posicion);
                    cls();
                    cabecera();
                    misil = ArchMisil.leerRegistro(posicion);
                    misil.mostrar();
                    system("pause");
                } */
                break;

            }

            case 5: {

                    int Id, pos;
                    cls();
                    cabecera();
                    cout << "INGRESE EL ID A BUSCAR: ";
                    cin >> Id;
                    /* //TODO: FALTA HACER***********
                    pos = ArchMisil.buscarRegistro(Id);
                    misil = ArchMisil.leerRegistro(pos);

                    cls();
                    cabecera();
                    misil.mostrar();
                    cout << "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): ";
                    cin >> respuesta;
                    if(respuesta == 's' || respuesta == 'S'){
                        misil.setEstado(false);
                    }
                    else{
                        break;
                    }
                    if(ArchMisil.ModificarEnDisco(misil, pos)){
                        cls();
                        cabecera();
                        cout << "BAJA EXITOSA..." << endl;
                    }
                    else{
                        cls();
                        cabecera();
                        cout << "ERROR, NO SE HA REALIZADO LA BAJA..." << endl;
                    }
                    system("pause");
                    break;
                } */
                break;

            case 0:
                return;

            default:
                cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
                system("pause");
                break;
        }
    }
}
}



/// STOCK AVION
//SUBMENU ABML AVION QUE ESTA DENTRO DE LAS OPCIONES DEL MENU STOCK ADMIN
void Menu::StockAviones(){
    opcion = -1;
    //Avion avion; //TODO: FALTA HACER***
    //ArchivoAvion ArchAvion; //TODO: FALTA HACER***
    char respuesta;
    int Id, pos;

    while(true){


		system ("cls");
        cabecera();

        gotoxy (2,6);
        cout<<"MENU AVIONES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout<<"1 - ALTA DE AVION: ";
        gotoxy (2,14);
        cout<<"2 - LISTAR AVIONES: ";
        gotoxy (2,15);
        cout<<"3 - MODIFICACION DE AVIONES: ";
        gotoxy(2,16);
        cout << "4 - AGREGAR A STOCK" << endl;
        gotoxy(2,17);
        cout << "5 - BAJA AVIONES" << endl;
        gotoxy(2,18);
        cout << "0 - VOLVER ATRAS" << endl;
        gotoxy(2,19);
        cout << "->: ";
        cin >> opcion;

        //system("cls");

            switch(opcion){

                case 1: {
                	cls();
                cabecera();
                    //avion.cargar();//TODO: FALTA HACER***
                    //ArchAvion.grabarRegistro(avion); //TODO: FALTA HACER***
                    break;
                }

                case 2: {
                	cls();
                cabecera();
                    //ArchAvion.listarRegistros(); //TODO: FALTA HACER***
                    break;
                }

                case 3: {
                	cls();
                cabecera();

                    system("cls");

                    cout << "INGRESE EL ID A BUSCAR: ";
                    cin >> Id;
                    /*pos = ArchAvion.buscarRegistro(Id); //TODO: FALTA HACER***
                    avion = ArchAvion.leerRegistro(pos);
                    avion.mostrar();
                    if(avion.getEstado()==false){
                        cout << "REGISTRO DADO DE BAJA, NO SE PUEDE MODIFICAR..." << endl;
                        system("pause");
                        break;
                    }
                    cout << "DESEA MODIFICAR ESTE REGISTRO? (s / n): ";
                    cin >> respuesta;
                    if(respuesta == 's' || respuesta == 'S'){
                        avion.cargar();
                        if(ArchAvion.modificarRegistro(avion, pos)){
                        cout << "MODIFICACION EXITOSA..." << endl;
                        system("pause");
                        }
                    } else {
                        cout << "ERROR, NO SE HA REALIZADO LA MODIFICACION..." << endl;
                    }

                    system("pause");
                    */

                    break;
                }

                case 4:{
                    cls();
                    cabecera();
                    //Avion avion; //TODO: FALTA HACER***

                    gotoxy(29, 5);
                    cout << "---------------";
                    gotoxy(30, 6);
                    cout << "AGREGAR STOCK";
                    gotoxy(29, 7);
                    cout << "---------------";

                    gotoxy(23, 10);
                    cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
                    int codigo;
                    cin >> codigo;

                    /*int posicion = ArchAvion.buscarRegistro(codigo);  //TODO: FALTA HACER***
                    avion = ArchAvion.leerRegistro(posicion);
                    cls();
                    cabecera();
                    avion.mostrar();
                    system("pause");
                    cls();
                    cabecera();
                    int respuesta;
                    cout << "DESEA ANIADIR STOCK A ESTE PRODUCTO?(1-SI / 2-NO) ";
                    cin >> respuesta;
                    if(respuesta==1){
                        cout << "INGRESE LA CANTIDAD: ";
                        int cantidad;
                        cin >> cantidad;
                        avion.setStock((avion.getStock() + cantidad));
                        ArchAvion.modificarStock(avion, posicion);
                        cls();
                        cabecera();
                        avion = ArchAvion.leerRegistro(posicion);
                        avion.mostrar();
                        system("pause");
                    }
                    */
                    break;

                }

                case 5: {
                	cls();
                cabecera();
                    /*int Id, pos;     //TODO: FALTA HACER***
                    cout << "INGRESE EL ID A BUSCAR: ";
                    cin >> Id;
                    //pos = ArchAvion.buscarRegistro(Id);
                    //avion = ArchAvion.leerRegistro(pos);
                    //avion.mostrar();
                    cout << "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): ";
                    cin >> respuesta;
                    if(respuesta == 's' || respuesta == 'S'){
                        avion.setEstado(false);
                    }
                    else{
                        break;
                    }
                    if(ArchAvion.modificarRegistro(avion, pos)){
                        cout << "BAJA EXITOSA..." << endl;
                        system("pause");
                    }
                    else{
                        cout << "ERROR, NO SE HA REALIZADO LA BAJA..." << endl;
                    }
                    system("pause");
                    */
                    break;
                }

                case 0:
                    return;

                	default:
                cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
                system("pause");

                break;

             }
        }
}


///STOCK BUQUE
//SUBMENU ABML BUQUE QUE ESTA DENTRO DE LAS OPCIONES DEL MENU STOCK ADMIN
void Menu::StockBuques(){
    opcion = -1;
    //Buque buque;  //TODO: FALTA HACER************
    //ArchivoBuque archivoBuque; //TODO: FALTA HACER************
    char respuesta;
    int Id, pos;

    while(true){
		system ("cls");

        cabecera();

        gotoxy (2,6);
        cout<<"MENU BUQUES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout<<"1 - ALTA DE BUQUE";
        gotoxy (2,14);
        cout<<"2 - LISTAR BUQUES";
        gotoxy (2,15);
        cout<<"3 - MODIFICACION DE BUQUE";
        gotoxy(2,16);
        cout << "4 - AGREGAR A STOCK" << endl;
        gotoxy(2,17);
        cout << "5 - BAJA DE BUQUE" << endl;
        gotoxy(2,18);
        cout << "0 - VOLVER ATRAS" << endl;
        gotoxy(2,19);
        cout << "->: ";
        cin >> opcion;


            switch(opcion){

                case 1: {
                	cls();
                	cabecera();
                    /*buque.cargar(); //TODO: FALTA ******
                    archivoBuque.grabarRegistro(buque);//TODO: FALTA ******
                    */
                    break;
                }

                case 2: {
                	cls();
                	cabecera();
                	/*
                    archivoBuque.listarRegistros();//TODO: FALTA ******
                    system("pause");//TODO: FALTA ******
                    */
                    break;
                }

                case 3: {
                	cls();
                	cabecera();
                    cout << "INGRESE EL ID A BUSCAR: ";
                    cin >> Id;
                    /*
                    pos = archivoBuque.buscarRegistro(Id); //TODO: FALTA ******
                    buque =archivoBuque.leerRegistro(pos);
                    buque.mostrar();
                    if(buque.getEstado()==false){
                        cout << "REGISTRO DADO DE BAJA, NO SE PUEDE MODIFICAR..." << endl;
                        system("pause");
                        break;
                    }
                    cout << "DESEA MODIFICAR ESTE REGISTRO? (s / n): ";
                    cin >> respuesta;
                    if(respuesta == 's' || respuesta == 'S'){
                        buque.cargar();
                        if(archivoBuque.modificarRegistro(buque, pos)){
                        cout << "MODIFICACION EXITOSA..." << endl;
                        system("pause");
                        }
                    } else {
                        cout << "ERROR, NO SE HA REALIZADO LA MODIFICACION..." << endl;
                    }

                    system("pause"); */
                    break;
                }

                case 4:{
                    cls();
                    cabecera();
                    //Buque buque; //TODO: FALTA ******

                    gotoxy(29, 5);
                    cout << "---------------";
                    gotoxy(30, 6);
                    cout << "AGREGAR STOCK";
                    gotoxy(29, 7);
                    cout << "---------------";

                    gotoxy(23, 10);
                    cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
                    int codigo;
                    cin >> codigo;

                    //int posicion = archivoBuque.buscarRegistro(codigo); //TODO: FALTA ******
                    /*buque = archivoBuque.leerRegistro(posicion); //TODO: FALTA ******
                    cls();
                    cabecera();
                    buque.mostrar();
                    system("pause");
                    cls();
                    cabecera();
                    int respuesta;
                    cout << "DESEA ANIADIR STOCK A ESTE PRODUCTO?(1-SI / 2-NO) ";
                    cin >> respuesta;
                    if(respuesta==1){
                        cout << "INGRESE LA CANTIDAD: ";
                        int cantidad;
                        cin >> cantidad;
                        buque.setStock((buque.getStock() + cantidad));
                        archivoBuque.modificarStock(buque, posicion);
                        cls();
                        cabecera();
                        buque = archivoBuque.leerRegistro(posicion);
                        buque.mostrar();
                        system("pause");
                    }*/
                    break;

                }

                case 5: {
                	cls();
                cabecera();
                    int Id, pos;
                    cout << "INGRESE EL ID A BUSCAR: ";
                    cin >> Id;
                    /*pos = archivoBuque.buscarRegistro(Id); //TODO: FALTA ******
                    buque = archivoBuque.leerRegistro(pos);
                    buque.mostrar();
                    cout << "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): ";
                    cin >> respuesta;
                    if(respuesta == 's' || respuesta == 'S'){
                        buque.setEstado(false);
                    }
                    else{
                        break;
                    }
                    if(archivoBuque.modificarRegistro(buque, pos)){
                        cout << "BAJA EXITOSA..." << endl;
                        system("pause");
                    }
                    else{
                        cout << "ERROR, NO SE HA REALIZADO LA BAJA..." << endl;
                    }
                    system("pause");*/
                    break;
                }

                case 0:
                    return;
                    break;

                default:
                	cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
                system("pause");
                    break;
             }
        }
}


///STOCK TANQUE
//SUBMENU ABML TANQUE QUE ESTA DENTRO DE LAS OPCIONES DEL MENU STOCK ADMIN
void Menu::StockTanques(){
    //Tanque tanque;
    //ArchivoTanque archivoTanque;
    char respuesta;
    int Id, pos, opcion;

    while(true){
			system("cls");
        cabecera();
        gotoxy (2,6);
        cout<<"MENU TANQUES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout<<"1 - ALTA DE TANQUE: ";
        gotoxy (2,14);
        cout<<"2 - LISTAR TANQUES: ";
        gotoxy (2,15);
        cout<<"3 - MODIFICACION DE TANQUES: ";
        gotoxy (2,16);
        cout<<"4 - BAJA DE TANQUE: ";
        gotoxy (2,17);
        cout<<"0 - VOLVER ATRAS: ";
        gotoxy (2,18);
        cout<<"->: ";
        cin>>opcion;



            switch(opcion){

                case 1:{
                	cls();
                	cabecera();
                    //tanque.cargar(); // TODO: FALTA*******
                    //archivoTanque.grabarRegistro(tanque); // TODO: FALTA*******
                    break;
                }

                case 2: {
                	cls();
                	cabecera();
                    //archivoTanque.listarRegistros(); // TODO: FALTA*******
                    break;
                }

                case 3: {
                    cls();
                	cabecera();
                	/*
                    cout << "INGRESE EL ID A BUSCAR: "; // TODO: FALTA*******
                    cin >> Id;
                    pos = archivoTanque.buscarRegistro(Id);
                    tanque = archivoTanque.leerRegistro(pos);
                    tanque.mostrar();
                    if(tanque.getEstado()==false){
                        cout << "REGISTRO DADO DE BAJA, NO SE PUEDE MODIFICAR..." << endl;
                        system("pause");
                        break;
                    }
                    cout << "DESEA MODIFICAR ESTE REGISTRO? (s / n): ";
                    cin >> respuesta;
                    if(respuesta == 's' || respuesta == 'S'){
                        tanque.cargar();
                        if(archivoTanque.modificarRegistro(tanque, pos)){
                        cout << "MODIFICACION EXITOSA..." << endl;
                        system("pause");
                        }
                    } else {
                        cout << "ERROR, NO SE HA REALIZADO LA MODIFICACION..." << endl;
                    }
                    system("pause");
                    */
                    break;
                }

                case 4: {
                    cls();
                    cabecera();
                    //Tanque tanque; // TODO: FALTA*******

                    gotoxy(29, 5);
                    cout << "---------------";
                    gotoxy(30, 6);
                    cout << "AGREGAR STOCK";
                    gotoxy(29, 7);
                    cout << "---------------";

                    gotoxy(23, 10);
                    cout << "INGRESE EL CODIGO DEL PRODUCTO: ";
                    int codigo;
                    cin >> codigo;
					/*
                    int posicion = archivoTanque.buscarRegistro(codigo);  // TODO: FALTA*******
                    tanque = archivoTanque.leerRegistro(posicion);
                    cls();
                    cabecera();
                    tanque.mostrar();
                    system("pause");
                    cls();
                    cabecera();
                    int respuesta;
                    cout << "DESEA ANIADIR STOCK A ESTE PRODUCTO?(1-SI / 2-NO) ";
                    cin >> respuesta;
                    if(respuesta==1){
                        cout << "INGRESE LA CANTIDAD: ";
                        int cantidad;
                        cin >> cantidad;
                        tanque.setStock((tanque.getStock() + cantidad));
                        archivoTanque.modificarStock(tanque, posicion);
                        cls();
                        cabecera();
                        tanque = archivoTanque.leerRegistro(posicion);
                        tanque.mostrar();
                        system("pause");
                    }
                    */
                    break;
                }

                case 5: {
                	cls();
                	cabecera();
                	/*
                    int Id, pos;                                      // TODO: FALTA*******
                    cout << "INGRESE EL ID A BUSCAR: ";
                    cin >> Id;
                    pos = archivoTanque.buscarRegistro(Id);
                    tanque = archivoTanque.leerRegistro(pos);
                    tanque.mostrar();
                    cout << "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): ";
                    cin >> respuesta;
                    if(respuesta == 's' || respuesta == 'S'){
                        tanque.setEstado(false);
                    }
                    else{
                        break;
                    }
                    if(archivoTanque.modificarRegistro(tanque, pos)){
                        cout << "BAJA EXITOSA..." << endl;
                        system("pause");
                    }
                    else{
                        cout << "ERROR, NO SE HA REALIZADO LA BAJA..." << endl;
                    }
                    system("pause");
                    */
                    break;
                }

                case 0:
                    return;
                    break;

                default:
                	cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
                system("pause");
                    break;
             }
        }
}


