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

    regAdmin = archivoAdmin.buscarXUsuario(usuario);//en el archivoAdmin va a buscar el nombre de usuario que ingresaste y te DEVUELVE EL REGISTRO.
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
        if(respuesta < 0 || respuesta > 1)//si ingresaste algo distinto q 1 ó 0 te pide reingresar opcion
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
            Listados();
            break;
        case 5:
            //Reportes(); //TODO: FALTA HACER***
            break;
        case 0:
            break;
        default:
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            system("pause");
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
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            system("pause");
            break;
        }
    }
}

/// ALTA USUARIO
void Menu::altaUsuario()//CARGAR UN NUEVO ADMIN AL ARCHIVO
{

    int id;
    Admin reg;
    ArchivoAdmin ArchAdmin;
    //devuelve la cantidad -1 de los reg del archivo
    id = ArchAdmin.getNuevoId(); //obtiene nuevo ID autonumerico.
    reg.cargar(id);//carga un nuevo reg admin setenadole el ID obtenido
    if(ArchAdmin.guardar(reg)) //lo cargan en archivo admin
    {
        cout << "ALTA EXITOSA..." << endl;
    }
    else
    {
        cout << "NO SE HA PODIDO GRABAR EL REGISTRO.";
    }
    system("pause");
}

/// LISTAR USUARIOS
void Menu::listarUsuarios()//SE UTILIZA DENTRO DE MODIFICAR/ELIMINAR USUARIO
{

    ArchivoAdmin ArchAdmin;
    Admin *vecAdmin = nullptr;//OJO!!! DINAMICO inicializar/verificar/delete corchetes? XQ NOC CUANTOS REGISTROS PUEDEN LLEGAR A SER

    int cant = ArchAdmin.getCantidadReg();

    vecAdmin = new Admin[cant];

    //verifico memoria
    if(vecAdmin == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        system("pause");
        return;
    }

    ArchAdmin.leerTodos(vecAdmin,cant);

    for(int i=0; i<cant; i++)
    {
        if(vecAdmin[i].getEstado())//si esta eliminado no lo muestra
        {
            vecAdmin[i].mostrar();
            cout << "------------------------------" << endl;
        }
    }
    delete [] vecAdmin;
}

/// MODIFICAR USUARIO
void Menu::modificarUsuario()//MODIFICA ADMIN EXISTENTE EN ARCHIVO
{
    Validar validar;
    ArchivoAdmin ArchAdmin;
    Admin reg;
    int id;
    string respuesta;
    cin.ignore();//arregla de menu usuarios el "cin>>opcion;" sino se saltea el LISTAR USUARIOS.
    cout << "LISTAR USUARIOS? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        listarUsuarios();
    }

    cout << "INGRESE EL ID A BUSCAR: ";
    cin >> id;
    cin.ignore();//sino esta se saltea "DESEA MODIFICAR ESTE REGISTRO?"
    int pos = ArchAdmin.buscar(id);

    if(pos != -1) // SI encontro el admin
    {
        reg = ArchAdmin.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();
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

                if(ArchAdmin.guardar(reg,pos))
                {
                    cout << "MODIFICACION EXITOSA..." << endl;
                }
                else
                {
                    cout << "ERROR, NO SE HA REALIZADO LA MODIFICACION..." << endl;
                }

            }
            else//NO eligio modificar el admin.
            {
                cout << "El admin no fue modificado" << endl;
            }
        }
        else
        {
            cout << "El admin no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El admin no se encuentra en el sistema." << endl;
    }
    system("pause");
}

/// ELIMINAR USUARIO
void Menu::eliminarUsuario()//ELIMINACION LOGICA DE ADMIN EXISTENTE EN ARCHIVO
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

    int pos = ArchAdmin.buscar(Id);
    reg = ArchAdmin.leer(pos);
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
    if(ArchAdmin.guardar(reg, pos))
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
void Menu::Clientes()//SUBMENU ABML PAISES QUE ESTA DENTRO DE LAS OPCIONES DEL MENU PRINCIPAL ADMIN
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
            altaCliente();
            break;

        case 2:
            eliminarCliente();
            break;

        case 3:
            modificarCliente();
            break;

        case 0:
            opcion = 0;
            break;

        default:
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            system("pause");
            break;
        }
    }

}

/// ALTA CLIENTE
void Menu::altaCliente()//CARGA UN NUEVO PAIS AL ARCHIVO
{
    int id;
    Pais reg;
    ArchivoPais ArchPais;
    //devuelve la cantidad -1 de los reg del archivo
    id = ArchPais.contarRegistros();//obtiene nuevo ID autonumerico.
    reg.cargar(id);//carga un nuevo reg admin setenadole el ID obtenido
    if(ArchPais.grabarRegistro(reg))
    {
        cout << "ALTA EXITOSA...";
        system("pause");
    }
    else
    {
        cout << "NO SE HA PODIDO GRABAR EL REGISTRO.";
        system("pause");
    }
}

/// LISTAR CLIENTE
void Menu::listarClientes()//SE UTILIZA DENTRO DE MODIFICAR/ELIMINAR USUARIO/CLIENTES
{

    ArchivoPais ArchPais;

    int cant = ArchPais.contarRegistros();
    Pais *pais= new Pais[cant];

    if(pais == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        system("pause");
        return;
    }

    for(int i=0; i<cant; i++)
    {
        pais[i] = ArchPais.leerRegistro(i);
    }

    for(int j=0; j<cant; j++)
    {
        if(pais[j].getEstado()==1)//si esta eliminado no lo muestra
        {
            pais[j].mostrar();
            cout << "------------------------------" << endl;
        }
    }
    delete [] pais;
}

/// MODIFICAR CLIENTE
void Menu::modificarCliente()//MODIFICA PAIS EXISTENTE EN ARCHIVO
{

    Validar validar;
    ArchivoPais ArchPais;
    int id;
    string respuesta;
    cin.ignore();//arregla de menu cliente/paise el "cin>>opcion;" sino se saltea el LISTAR USUARIOS.
    cout << "LISTAR USUARIOS? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        listarClientes();
    }

    cout << "INGRESE EL ID A BUSCAR: ";
    cin >> id;
    cin.ignore();//sino esta se saltea "DESEA MODIFICAR ESTE REGISTRO?"
    int pos = ArchPais.buscarRegistro(id);
    Pais reg = ArchPais.leerRegistro(pos);
    reg.mostrar();

    if(reg.getEstado()==false)
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
        cout << "MAX 30 CARACTERES -> INGRESE NUEVA CLAVE: ";
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
    if(ArchPais.modificarRegistro(reg, pos))//lo carga en el archivo y si lo pudo cargar muestra
    {
        cout << "MODIFICACION EXITOSA..." << endl;
    }
    else
    {
        cout << "ERROR, NO SE HA REALIZADO LA MODIFICACION..." << endl;
    }
    system("pause");
}

/// ELIMINAR CLIENTE
void Menu::eliminarCliente()//ELIMINACION LOGICA DE PAIS EXISTENTE EN ARCHIVO
{

    int Id;
    Pais reg;
    ArchivoPais ArchPais;

    string respuesta;
    cin.ignore();//arregla de menu usuarios el "cin>>opcion;" sino se saltea el LISTAR USUARIOS.
    cout << "LISTAR USUARIOS? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        listarClientes();
    }

    cout << "INGRESE EL ID A BUSCAR: ";
    cin >> Id;
    cin.ignore();//sino se saltea "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): "

    int pos = ArchPais.buscarRegistro(Id);
    reg = ArchPais.leerRegistro(pos);
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
    if(ArchPais.modificarRegistro(reg, pos))//lo carga en el archivo y si lo pudo cargar muestra
    {
        cout << "BAJA EXITOSA..." << endl;
    }
    else
    {
        cout << "ERROR, NO SE HA REALIZADO LA BAJA..." << endl;
    }
    system("pause");
}

/// MENU STOCK
void Menu::Stock()//SUBMENU ABML STOCK QUE ESTA DENTRO DE LAS OPCIONES DEL MENU PRINCIPAL ADMIN
{
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

    switch(opcion)
    {
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
void Menu::StockMisiles()//SUBMENU ABML MISIL QUE ESTA DENTRO DE LAS OPCIONES DEL MENU STOCK ADMIN
{
    opcion = -1;

    while(opcion!=0)
    {
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
        cout << "2 - MODIFICAR MISIL" << endl;
        gotoxy(2,15);
        cout << "3 - AGREGAR A STOCK" << endl;
        gotoxy(2,16);
        cout << "4 - BAJA MISIL" << endl;
        gotoxy(2,17);
        cout << "0 - VOLVER ATRAS" << endl;
        gotoxy(2,18);
        cout << "->: ";

        cin >> opcion;

        switch (opcion)
        {

        case 1:
            //TODO:FALTA HACER**
            break;

        case 2:
            //TODO:FALTA HACER**
            break;

        case 3:
            //TODO:FALTA HACER**
            break;

        case 4:
            //TODO:FALTA HACER**
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

/// STOCK AVION
void Menu::StockAviones()//SUBMENU ABML AVION QUE ESTA DENTRO DE LAS OPCIONES DEL MENU STOCK ADMIN
{
    opcion = -1;

    while(opcion!=0)
    {


        system ("cls");
        cabecera();

        gotoxy (2,6);
        cout<<"MENU AVIONES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout << "1 - ALTA DE AVION: ";
        gotoxy (2,14);
        cout << "2 - MODIFICACION DE AVIONES: ";
        gotoxy (2,15);
        cout << "3 - AGREGAR A STOCK" << endl;
        gotoxy(2,16);
        cout << "4 - BAJA AVIONES" << endl;
        gotoxy(2,17);
        cout << "0 - VOLVER ATRAS" << endl;
        gotoxy(2,18);
        cout << "->: ";

        cin >> opcion;


        switch(opcion)
        {

        case 1:
            //TODO:FALTA HACER**
            break;


        case 2:
            //TODO:FALTA HACER**
            break;


        case 3:
            //TODO:FALTA HACER**
            break;

        case 4:
            //TODO:FALTA HACER**
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

///STOCK BUQUE
void Menu::StockBuques()//SUBMENU ABML BUQUE QUE ESTA DENTRO DE LAS OPCIONES DEL MENU STOCK ADMIN
{
    opcion = -1;

    while(opcion!=0)
    {
        system ("cls");

        cabecera();

        gotoxy (2,6);
        cout<<"MENU BUQUES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout << "1 - ALTA DE BUQUE";
        gotoxy (2,14);
        cout << "2 - MODIFICACION DE BUQUE";
        gotoxy (2,15);
        cout << "3 - AGREGAR A STOCK" << endl;
        gotoxy(2,16);
        cout << "4 - BAJA DE BUQUE" << endl;
        gotoxy(2,17);
        cout << "0 - VOLVER ATRAS" << endl;
        gotoxy(2,18);
        cout << "->: ";

        cin >> opcion;


        switch(opcion)
        {

        case 1:
            //TODO:FALTA HACER**
            break;

        case 2:
            //TODO:FALTA HACER**
            break;

        case 3:
            //TODO:FALTA HACER**
            break;

        case 4:
            //TODO:FALTA HACER**
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
}

///STOCK TANQUE
void Menu::StockTanques()//SUBMENU ABML TANQUE QUE ESTA DENTRO DE LAS OPCIONES DEL MENU STOCK ADMIN
{
    opcion = -1;

    while(opcion!=0)
    {
        system("cls");
        cabecera();
        gotoxy (2,6);
        cout<<"MENU TANQUES";
        gotoxy (2,7);
        cout<<"------------------";
        gotoxy (2,10);
        cout<<"INGRESE UNA OPCION: ";

        gotoxy (2,13);
        cout << "1 - ALTA DE TANQUE";
        gotoxy (2,14);
        cout << "2 - MODIFICACION DE TANQUE";
        gotoxy (2,15);
        cout << "3 - AGREGAR A STOCK" << endl;
        gotoxy(2,16);
        cout << "4 - BAJA DE TANQUE" << endl;
        gotoxy(2,17);
        cout << "0 - VOLVER ATRAS" << endl;
        gotoxy(2,18);
        cout << "->: ";

        cin>>opcion;



        switch(opcion)
        {

        case 1:
            //TODO:FALTA HACER**
            break;

        case 2:
            //TODO:FALTA HACER**
            break;

        case 3:
            //TODO:FALTA HACER**
            break;

        case 4:
            //TODO:FALTA HACER**
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
}


/// MENU LISTADOS
void Menu::Listados()//SUBMENU LISTADOS QUE ESTA DENTRO DE LAS OPCIONES DEL MENU PRINCIPAL ADMIN
{

    int opcion;
    opcion = -1;

    while(opcion!=0)
    {
        system("cls");
        cabecera();
        gotoxy(30, 6);
        cout << "MENU LISTADOS";
        gotoxy(30, 8);
        cout << "1 - CLIENTES(PAISES)";
        gotoxy(30, 10);
        cout << "2 - PRODUCTOS";
        gotoxy(30, 12);
        cout << "3 - ADMINISTRADORES";
        gotoxy(30, 14);
        cout << "0 - VOLVER";
        gotoxy(30, 18);
        cout << "INGRESE UNA OPCION: ";
        cin >> opcion;

        switch(opcion)
        {
        case 1: //TODO: FALTA HACER************

            break;

        case 2: //TODO: FALTA HACER************

            break;

        case 3: //TODO: FALTA HACER************

            break;

        case 4: //TODO: FALTA HACER************

            break;

        case 0: //TODO: FALTA HACER************
            return;
            break;

        default:
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            system("pause");
            break;
        }
    }
}





