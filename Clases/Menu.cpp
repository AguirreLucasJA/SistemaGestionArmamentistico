#include <iostream>//cout
#include <stdio.h>//printf
#include <windows.h>//HANDLE
#include "rlutil.h"//cls

using namespace std;//std::
using namespace rlutil;//rlutil::

#include "Validar.h"

#include "Menu.h"
#include"NombreUsuario.h"//tablas intermedias
#include"NombreProducto.h"//tablas intermedias
#include "NombreProductoCantidad.h" //tablas intermedias
#include"StockProducto.h"//tablas intermedias

#include "ClasesArchivos/ArchivoAdmin.h"
#include "ClasesArchivos/ArchivoPais.h"
#include"ClasesArchivos/ArchivoNombreUsuario.h"
#include"ClasesArchivos/ArchivoNombreProducto.h"
#include "ClasesArchivos/ArchivoMisil.h"
#include "ClasesArchivos/ArchivoAvion.h"
#include "ClasesArchivos/ArchivoBuque.h"
#include "ClasesArchivos/ArchivoTanque.h"
#include "ClasesArchivos/ArchivoDetalleVenta.h"
#include "ClasesArchivos/ArchivoVenta.h"



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
    system("cls");
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

    bool ingreso = false;

    if (archivoAdmin.buscarXUsuario(usuario) != -1)
    {
        regAdmin = archivoAdmin.leer(archivoAdmin.buscarXUsuario(usuario));

        if (regAdmin.getClave() == clave && regAdmin.getEstado())
        {
            menuPrincipalAdmin();
            ingreso = true;
        }
    }

    if(usuario == "admin" && clave == "admin") // sino se pregunta si se ingresa el admin HARCODEADO PARA 1RA CARGA.
    {
        menuPrincipalAdmin();
        ingreso = true;
    }

    if (archivoPais.buscarXUsuario(usuario) != -1)
    {
        regPais = archivoPais.leer(archivoPais.buscarXUsuario(usuario));

        if (regPais.getClave() == clave && regPais.getEstado())
        {
            menuPrincipalPais(regPais);
            ingreso = true;
        }

    }

    if(ingreso==false)  //si no, nunca se ingreso un admin?
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

        gotoxy (2,9);
        cout << "1 - ADMINISTRADORES";
        gotoxy (2,10);
        cout << "2 - STOCK";
        gotoxy (2,11);
        cout << "3 - PAISES";
        gotoxy (2,12);
        cout << "4 - LISTADOS";
        gotoxy (2,13);
        cout << "5 - REPORTES";
        gotoxy (2,14);
        cout << "0 - SALIR DEL PROGRAMA";
        gotoxy (2,16);
        cout << "INGRESE UNA OPCION: ";

        cin >> opcion;

        switch(opcion)
        {
        case 1:
            menuAdmin();
            break;

        case 2:
            menuStock();
            break;

        case 3:
            menuPaises();
            break;

        case 4:
            menuListados();
            break;

        case 5:
            menuReportes();
            break;

        case 0:
            break;

        default:
            gotoxy (2,19);
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            gotoxy (2,20);
            system("pause");
            break;
        }
    }
}

/// SUBMENU ADMIN
void Menu::menuAdmin()//SUBMENU ABM ADMIN QUE ESTA DENTRO DE LAS OPCIONES DEL MENU PRINCIPAL ADMIN
{
    opcion = -1;

    while(opcion!=0) //si es ==0 vuelve al MENU PRINCIPAL ADMIN
    {

        cabecera();

        gotoxy (2,6);
        cout<<"MENU ADMINISTRADORES";
        gotoxy (2,7);
        cout<<"--------------------";

        gotoxy (2,9);
        cout<<"1 - ALTA DE ADMINISTRADOR";
        gotoxy (2,10);
        cout<<"2 - BAJA DE ADMINISTRADOR";
        gotoxy (2,11);
        cout<<"3 - MODIFICACION DE ADMINISTRADOR";
        gotoxy (2,12);
        cout<<"0 - VOLVER ATRAS";
        gotoxy (2,14);
        cout<<"INGRESE UNA OPCION: ";

        cin>>opcion;


        switch(opcion)
        {
        case 1:
            system("cls");
            altaAdmin();
            system("pause");
            break;
        case 2:
            system("cls");
            eliminarAdmin();
            system("pause");
            break;
        case 3:
            system("cls");
            modificarAdmin();
            system("pause");
            break;

        case 0:
            break;

        default:
            gotoxy (2,17);
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            gotoxy (2,18);
            system("pause");
            break;
        }
    }
}

/// ALTA ADMIN
void Menu::altaAdmin()//CARGAR UN NUEVO ADMIN AL ARCHIVO
{

    int id;
    Admin regAdmin;
    ArchivoAdmin ArchAdmin;
    NombreUsuario regNombreUsuario;
    ArchivoNombreUsuario ArchNombreUsuario;

    id = ArchAdmin.getNuevoId(); //obtiene nuevo ID autonumerico.
    regAdmin.cargar(id);//carga un nuevo regAdmin admin setenadole el ID obtenido
    regNombreUsuario.setUsuario(regAdmin.getUsuario());

    if(ArchAdmin.guardar(regAdmin) && ArchNombreUsuario.guardar(regNombreUsuario)) //lo cargan en archivo admin
    {
        cout << "ALTA EXITOSA..." << endl;

    }
    else
    {
        cout << "NO SE HA PODIDO GRABAR EL REGISTRO.";
    }
}

/// MOSTRAR ADMINS
void Menu::mostrarAdmins(bool ordenadoPorEstado, bool mostrarEliminados)//SE UTILIZA DENTRO DE MODIFICAR/ELIMINAR ADMIN
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

    if(ArchAdmin.leerTodos(vecAdmin,cant))
    {

        if (ordenadoPorEstado)
        {
            ordenarPorEstado(vecAdmin, cant);
        }

        for(int i=0; i<cant; i++)
        {
            if(!mostrarEliminados)
            {
                if(vecAdmin[i].getEstado())//si esta eliminado no lo muestra
                {
                    vecAdmin[i].mostrar();
                    cout << "-----------------------" << endl;
                }
            }
            else
            {
                vecAdmin[i].mostrar();
                cout << "-----------------------" << endl;
            }
        }
    }
    delete [] vecAdmin;
}

/// MODIFICAR ADMIN
void Menu::modificarAdmin()//MODIFICA ADMIN EXISTENTE EN ARCHIVO
{
    Validar validar;
    ArchivoAdmin ArchAdmin;
    Admin reg;
    int id;
    int pos;
    string respuesta;
    float sueldo;
    cin.ignore();//arregla de subMenuAdmin el "cin>>opcion;" sino se saltea el LISTAR ADMINISTRADORES.
    cout << "LISTAR ADMINISTRADORES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarAdmins(false);
    }

    cout << "INGRESE EL ID A MODIFICAR: ";
    cin >> id;
    cin.ignore();//sino esta se saltea "DESEA MODIFICAR ESTE REGISTRO?"
    pos = ArchAdmin.buscarXId(id);

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
            //si le ingresas cualquier otra cosa que no sea s/S RETURN al subMenuAdmin
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

                cout << "ING NUEVO SUELDO: $";
                cin >> sueldo;
                reg.setSueldo(sueldo);

                if(ArchAdmin.guardar(reg,pos))
                {
                    cout << "Se modifico con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo modificar el admin!" << endl;
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
}

/// ELIMINAR ADMIN
void Menu::eliminarAdmin()//ELIMINACION LOGICA DE ADMIN EXISTENTE EN ARCHIVO
{
    int Id;
    int pos;
    Admin reg;
    ArchivoAdmin ArchAdmin;
    string respuesta;
    cin.ignore();//arregla de subMenuAdmin el "cin>>opcion;" sino se saltea el LISTAR USUARIOS.
    cout << "LISTAR ADMINISTRADORES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarAdmins(false);
    }

    cout << "INGRESE EL ID A ELIMINAR: ";
    cin >> Id;
    cin.ignore();//sino se saltea "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): "

    pos = ArchAdmin.buscarXId(Id);

    if(pos != -1)//si encontro el archivo
    {
        reg = ArchAdmin.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();

            cout << "DESEA ELIMINAR ESTE REGISTRO? (s / n): ";
            getline(cin, respuesta);

            //si le ingresas cualquier otra cosa que no sea "s/S" RETURN al SUBmenu USUARIOS
            if(respuesta == "s" || respuesta == "S")//SI eligio eliminar el Admin.
            {
                reg.setEstado(false);

                if(ArchAdmin.guardar(reg, pos))
                {
                    cout << "Se elimino con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo eliminar el admin!" << endl;
                }
            }
            else//NO eligio eliminar el admin.
            {
                cout << "El admin no fue eliminado!" << endl;
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
}

/// SUBMENU PAIS
void Menu::menuPaises()//SUBMENU ABM PAISES QUE ESTA DENTRO DE LAS OPCIONES DEL MENU PRINCIPAL ADMIN
{
    opcion = -1;

    while(opcion!=0)
    {

        cabecera();

        gotoxy (2,6);
        cout<<"MENU PAISES";
        gotoxy (2,7);
        cout<<"-----------";

        gotoxy (2,9);
        cout<<"1 - ALTA DE PAIS";
        gotoxy (2,10);
        cout<<"2 - BAJA DE PAIS";
        gotoxy (2,11);
        cout<<"3 - MODIFICACION DE PAIS";
        gotoxy (2,12);
        cout<<"0 - VOLVER ATRAS";
        gotoxy (2,14);
        cout<<"INGRESE UNA OPCION: ";

        cin>>opcion;

        switch(opcion)
        {

        case 1:
            system("cls");
            altaPais();
            system("pause");
            break;

        case 2:
            system("cls");
            eliminarPais();
            system("pause");
            break;

        case 3:
            system("cls");
            modificarPais();
            system("pause");
            break;

        case 0:
            break;

        default:
            gotoxy (2,17);
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            gotoxy (2,18);
            system("pause");
            break;
        }
    }
}

/// ALTA PAIS
void Menu::altaPais()//CARGA UN NUEVO PAIS AL ARCHIVO
{

    int id;
    Pais regPais;
    ArchivoPais ArchPais;
    NombreUsuario regNombreUsuario;
    ArchivoNombreUsuario ArchNombreUsuario;
    //devuelve la cantidad -1 de los regPais del archivo
    id = ArchPais.getNuevoId(); //obtiene nuevo ID autonumerico.
    regPais.cargar(id);//carga un nuevo regPais pais setenadole el ID obtenido
    regNombreUsuario.setUsuario(regPais.getUsuario());

    if(ArchPais.guardar(regPais)&& ArchNombreUsuario.guardar(regNombreUsuario)) //lo cargan en archivo pais
    {
        cout << "ALTA EXITOSA..." << endl;
    }
    else
    {
        cout << "NO SE HA PODIDO GRABAR EL REGISTRO.";
    }
}

/// MOSTRAR PAIS
void Menu::mostrarPaises(bool ordenadoPorEstado, bool mostrarEliminados)//SE UTILIZA DENTRO DE MODIFICAR/ELIMINAR PAIS
{
    ArchivoPais ArchPais;
    Pais *vecPais = nullptr;//OJO!!! DINAMICO inicializar/verificar/delete corchetes? XQ NOC CUANTOS REGISTROS PUEDEN LLEGAR A SER

    int cant = ArchPais.getCantidadReg();

    vecPais = new Pais[cant];

    //verifico memoria
    if(vecPais == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        system("pause");
        return;
    }

    if(ArchPais.leerTodos(vecPais,cant))
    {

        if (ordenadoPorEstado)
        {
            ordenarPorEstado(vecPais, cant);
        }

        for(int i=0; i<cant; i++)
        {
            if(!mostrarEliminados)
            {
                if(vecPais[i].getEstado())//si esta eliminado no lo muestra
                {
                    vecPais[i].mostrar();
                    cout << "-----------------------" << endl;
                }
            }
            else
            {
                vecPais[i].mostrar();
                cout << "-----------------------" << endl;
            }
        }
    }
    delete [] vecPais;
}

/// MODIFICAR PAIS
void Menu::modificarPais()//MODIFICA PAIS EXISTENTE EN ARCHIVO
{
    Validar validar;
    ArchivoPais ArchPais;
    Pais reg;
    int id;
    int pos;
    string respuesta;
    cin.ignore();//arregla de subMenuPais el "cin>>opcion;" sino se saltea el LISTAR PAISES.
    cout << "LISTAR PAISES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarPaises(false);
    }

    cout << "INGRESE EL ID A MODIFICAR: ";
    cin >> id;
    cin.ignore();//sino esta se saltea "DESEA MODIFICAR ESTE REGISTRO?"
    pos = ArchPais.buscarXId(id);

    if(pos != -1) // SI encontro el pais
    {
        reg = ArchPais.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();
            cout << "DESEA MODIFICAR ESTE REGISTRO? (s / n): ";
            getline(cin, respuesta);
            string clave;
            string descripcion;
            //si le ingresas cualquier otra cosa que no sea s/S RETURN al subMenuAdmin
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

                if(ArchPais.guardar(reg,pos))
                {
                    cout << "Se modifico con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo modificar el pais!" << endl;
                }

            }
            else//NO eligio modificar el pais.
            {
                cout << "El pais no fue modificado" << endl;
            }
        }
        else
        {
            cout << "El pais no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El pais no se encuentra en el sistema." << endl;
    }
}

/// ELIMINAR PAIS
void Menu::eliminarPais()//ELIMINACION LOGICA DE PAIS EXISTENTE EN ARCHIVO
{
    int Id;
    int pos;
    Pais reg;
    ArchivoPais ArchPais;
    string respuesta;
    cin.ignore();//arregla de subMenuPais el "cin>>opcion;" sino se saltea el LISTAR PAISES.
    cout << "LISTAR PAISES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarPaises(false);
    }

    cout << "INGRESE EL ID A ELIMINAR: ";
    cin >> Id;
    cin.ignore();//sino se saltea "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): "

    pos = ArchPais.buscarXId(Id);

    if(pos != -1)//si encontro el archivo
    {
        reg = ArchPais.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();

            cout << "DESEA ELIMINAR ESTE REGISTRO? (s / n): ";
            getline(cin, respuesta);

            //si le ingresas cualquier otra cosa que no sea "s/S" RETURN al subMenuPais
            if(respuesta == "s" || respuesta == "S")//SI eligio eliminar el pais.
            {
                reg.setEstado(false);

                if(ArchPais.guardar(reg, pos))
                {
                    cout << "Se elimino con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo eliminar el pais!" << endl;
                }
            }
            else//NO eligio eliminar el pais.
            {
                cout << "El pais no fue eliminado!" << endl;
            }
        }
        else
        {
            cout << "El pais no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El pais no se encuentra en el sistema." << endl;
    }
}

/// SUBMENU STOCK
void Menu::menuStock()//SUBMENU ABM STOCK QUE ESTA DENTRO DE LAS OPCIONES DEL MENU PRINCIPAL ADMIN
{
    opcion = -1;

    while(opcion!=0)
    {
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
            subMenuStockMisiles();
            opcion = -1;
            break;

        case 2:
            subMenuStockAviones();
            opcion = -1;
            break;

        case 3:
            subMenuStockBuques();
            opcion = -1;
            break;

        case 4:
            subMenuStockTanques();
            opcion = -1;
            break;

        case 0:
            break;

        default:
            gotoxy (2,21);
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            gotoxy (2,22);
            system("pause");
            break;
        }
    }
}

/// SUBMENU STOCK MISIL
void Menu::subMenuStockMisiles()//SUBMENU ABM MISIL QUE ESTA DENTRO DE LAS OPCIONES DEL MENU STOCK ADMIN
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

        gotoxy(2,9);
        cout << "1 - ALTA MISIL" << endl;
        gotoxy(2,10);
        cout << "2 - BAJA MISIL" << endl;
        gotoxy(2,11);
        cout << "3 - MODIFICAR MISIL" << endl;
        gotoxy(2,12);
        cout << "4 - AGREGAR A STOCK" << endl;
        gotoxy(2,13);
        cout << "0 - VOLVER ATRAS" << endl;
        gotoxy(2,15);
        cout<<"INGRESE UNA OPCION: ";

        cin >> opcion;

        switch (opcion)
        {

        case 1:
            system("cls");
            altaMisil();
            system("pause");
            break;

        case 2:
            system("cls");
            eliminarMisil();
            system("pause");
            break;

        case 3:
            system("cls");
            modificarMisil();
            system("pause");
            break;

        case 4:
            system("cls");
            agregarStockMisil();
            system("pause");
            break;

        case 0:
            break;

        default:
            gotoxy (2,18);
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            gotoxy (2,19);
            system("pause");
            break;
        }
    }
}

/// ALTA MISIL
void Menu::altaMisil()//CARGA UN NUEVO MISIL AL ARCHIVO
{
    int id;
    Misil regMisil;
    ArchivoMisil ArchMisil;
    NombreProducto regNombreProducto;
    ArchivoNombreProducto ArchNombreProducto;

    id = ArchMisil.getNuevoId(); //obtiene nuevo ID autonumerico.
    regMisil.cargar(id);//carga un nuevo regMisil admin setenadole el ID obtenido
    regNombreProducto.setNombre(regMisil.getNombre());

    if(ArchMisil.guardar(regMisil) && ArchNombreProducto.guardar(regNombreProducto)) //lo cargan en archivo
    {
        cout << "ALTA EXITOSA..." << endl;

    }
    else
    {
        cout << "NO SE HA PODIDO GRABAR EL REGISTRO.";
    }
}

/// MOSTRAR MISILES
void Menu::mostrarMisiles(bool ordenadoPorEstado, bool mostrarEliminados)
{
    ArchivoMisil ArchMisil;
    Misil *vecMisil = nullptr;//OJO!!! DINAMICO inicializar/verificar/delete corchetes? XQ NOC CUANTOS REGISTROS PUEDEN LLEGAR A SER

    int cant = ArchMisil.getCantidadReg();

    vecMisil = new Misil[cant];

    //verifico memoria
    if(vecMisil == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        system("pause");
        return;
    }

    if(ArchMisil.leerTodos(vecMisil,cant))
    {

        if (ordenadoPorEstado)
        {
            ordenarPorEstado(vecMisil, cant);
        }

        for(int i=0; i<cant; i++)
        {
            if(!mostrarEliminados)
            {
                if(vecMisil[i].getEstado())//si esta eliminado no lo muestra
                {
                    vecMisil[i].mostrar();
                    cout << "-----------------------" << endl;
                }
            }
            else
            {
                vecMisil[i].mostrar();
                cout << "-----------------------" << endl;
            }
        }
    }
    delete [] vecMisil;
}

/// MODIFICAR MISIL
void Menu::modificarMisil()//MODIFICA MISIL EXISTENTE EN ARCHIVO
{
    Validar validar;
    ArchivoMisil ArchMisil;
    Misil reg;
    int id;
    int pos;
    string respuesta;
    cin.ignore();//arregla de subMenu Misil el "cin>>opcion;" sino se saltea el LISTAR MISILES.
    cout << "LISTAR MISILES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarMisiles(false);
    }

    cout << "INGRESE EL ID A MODIFICAR: ";
    cin >> id;
    cin.ignore();//sino esta se saltea "DESEA MODIFICAR ESTE REGISTRO?"
    pos = ArchMisil.buscarXId(id);

    if(pos != -1) // SI encontro el misil
    {
        reg = ArchMisil.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();
            cout << "DESEA MODIFICAR ESTE REGISTRO? (s / n): ";
            getline(cin, respuesta);
            long long precio;
            string paisOrigen;
            string descripcion;
            //si le ingresas cualquier otra cosa que no sea s/S RETURN al subMenuStock
            if(respuesta == "s" || respuesta == "S")
            {

                cout << "MAX 30 CARACTERES -> ING NUEVO PAIS DE ORIGEN: ";
                getline(cin, paisOrigen);
                while(!validar.esStringValido(paisOrigen,30))
                {
                    cout << "ERROR SOBREPASO LIMITE DE 30 CARACTERES" << endl;
                    system("pause");
                    system("cls");
                    cout << "REINGRESE PAIS DE ORIGEN:";
                    getline(cin, paisOrigen);
                }
                reg.setPaisOrigen(paisOrigen);

                cout << "MAX 100 CARACTERES -> ING NUEVA DESCRIPCION: ";
                getline(cin, descripcion);
                while(!validar.esStringValido(descripcion,100))
                {
                    cout << "ERROR SOBREPASO LIMITE DE 100 CARACTERES" << endl;
                    system("pause");
                    system("cls");
                    cout << "REINGRESE DESCRIPCION:";
                    getline(cin, descripcion);
                }
                reg.setDescripcion(descripcion);

                cout << "ING NUEVO PRECIO: $";
                cin >> precio;
                reg.setPrecio(precio);

                if(ArchMisil.guardar(reg,pos))
                {
                    cout << "Se modifico con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo modificar el misil!" << endl;
                }

            }
            else//NO eligio modificar el misil.
            {
                cout << "El misil no fue modificado" << endl;
            }
        }
        else
        {
            cout << "El misil no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El misil no se encuentra en el sistema." << endl;
    }
}

/// ELIMINAR MISIL
void Menu::eliminarMisil()//ELIMINACION LOGICA DE PAIS EXISTENTE EN ARCHIVO
{
    int Id;
    int pos;
    Misil reg;
    ArchivoMisil ArchMisil;
    string respuesta;
    cin.ignore();//arregla de subMenuMisil el "cin>>opcion;" sino se saltea el LISTAR MISILES.
    cout << "LISTAR MISILES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarMisiles(false);
    }

    cout << "INGRESE EL ID A ELIMINAR: ";
    cin >> Id;
    cin.ignore();//sino se saltea "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): "

    pos = ArchMisil.buscarXId(Id);

    if(pos != -1)//si encontro el archivo
    {
        reg = ArchMisil.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();

            cout << "DESEA ELIMINAR ESTE REGISTRO? (s / n): ";
            getline(cin, respuesta);

            //si le ingresas cualquier otra cosa que no sea "s/S" RETURN al subMenuMisil
            if(respuesta == "s" || respuesta == "S")//SI eligio eliminar el Misil.
            {
                reg.setEstado(false);

                if(ArchMisil.guardar(reg, pos))
                {
                    cout << "Se elimino con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo eliminar el misil!" << endl;
                }
            }
            else//NO eligio eliminar el misil.
            {
                cout << "El misil no fue eliminado!" << endl;
            }
        }
        else
        {
            cout << "El misil no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El misil no se encuentra en el sistema." << endl;
    }
}

/// AGREGAR STOCK MISIL
void Menu::agregarStockMisil()//ACUMULA STOCK DE MISILES
{
    int Id;
    int pos;
    Misil reg;
    ArchivoMisil ArchMisil;
    string respuesta;
    int stock = 0;
    cin.ignore();//arregla de subMenuMisil el "cin>>opcion;" sino se saltea el LISTAR MISILES.
    cout << "LISTAR MISILES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarMisiles(false);
    }

    cout << "INGRESE EL ID A AGREGAR STOCK: ";
    cin >> Id;
    cin.ignore();//sino se saltea "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): "

    system("cls");

    pos = ArchMisil.buscarXId(Id);

    if(pos != -1)//si encontro el archivo
    {
        reg = ArchMisil.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();

            cout << endl << "DESEA AGREGAR STOCK? (s / n): ";
            getline(cin, respuesta);

            //si le ingresas cualquier otra cosa que no sea "s/S" RETURN al subMenuMisil
            if(respuesta == "s" || respuesta == "S")//SI eligio agregar stock al Misil.
            {
                cout << "INGRESE STOCK A AGREGAR: ";
                cin >> stock;

                stock += reg.getStock();
                reg.setStock(stock);

                if(ArchMisil.guardar(reg, pos))
                {
                    cout << "Se agrego stock con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo agregar stock!" << endl;
                }
            }
            else//NO eligio agregar stock al Misil.
            {
                cout << "El stock no fue modificado!" << endl;
            }
        }
        else
        {
            cout << "El misil no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El misil no se encuentra en el sistema." << endl;
    }
}

/// SUBMENU STOCK AVION
void Menu::subMenuStockAviones()//SUBMENU ABM AVION QUE ESTA DENTRO DE LAS OPCIONES DEL MENU STOCK ADMIN
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

        gotoxy (2,9);
        cout << "1 - ALTA DE AVION";
        gotoxy (2,10);
        cout << "2 - BAJA AVION" << endl;
        gotoxy (2,11);
        cout << "3 - MODIFICACION DE AVION";
        gotoxy(2,12);
        cout << "4 - AGREGAR A STOCK" << endl;
        gotoxy(2,13);
        cout << "0 - VOLVER ATRAS" << endl;
        gotoxy(2,15);
        cout<<"INGRESE UNA OPCION: ";

        cin >> opcion;

        switch(opcion)
        {

        case 1:
            system("cls");
            altaAvion();
            system("pause");
            break;

        case 2:
            system("cls");
            eliminarAvion();
            system("pause");
            break;

        case 3:
            system("cls");
            modificarAvion();
            system("pause");
            break;

        case 4:
            system("cls");
            agregarStockAvion();
            system("pause");
            break;

        case 0:
            break;

        default:
            gotoxy (2,18);
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            gotoxy (2,19);
            system("pause");
            break;

        }
    }
}

/// ALTA AVION
void Menu::altaAvion()//CARGA UN NUEVO AVION AL ARCHIVO
{
    int id;
    Avion regAvion;
    ArchivoAvion ArchAvion;
    NombreProducto regNombreProducto;
    ArchivoNombreProducto ArchNombreProducto;

    id = ArchAvion.getNuevoId(); //obtiene nuevo ID autonumerico.
    regAvion.cargar(id);//carga un nuevo regAvion setenadole el ID obtenido
    regNombreProducto.setNombre(regAvion.getNombre());

    if(ArchAvion.guardar(regAvion) && ArchNombreProducto.guardar(regNombreProducto)) //lo carga en archivo
    {
        cout << "ALTA EXITOSA..." << endl;

    }
    else
    {
        cout << "NO SE HA PODIDO GRABAR EL REGISTRO.";
    }
}

/// MOSTRAR AVIONES
void Menu::mostrarAviones(bool ordenadoPorEstado, bool mostrarEliminados)
{
    ArchivoAvion ArchAvion;
    Avion *vecAvion = nullptr;//OJO!!! DINAMICO inicializar/verificar/delete corchetes? XQ NOC CUANTOS REGISTROS PUEDEN LLEGAR A SER

    int cant = ArchAvion.getCantidadReg();

    vecAvion = new Avion[cant];

    //verifico memoria
    if(vecAvion == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        system("pause");
        return;
    }

    if(ArchAvion.leerTodos(vecAvion,cant))
    {

        if (ordenadoPorEstado)
        {
            ordenarPorEstado(vecAvion, cant);
        }

        for(int i=0; i<cant; i++)
        {
            if(!mostrarEliminados)
            {
                if(vecAvion[i].getEstado())//si esta eliminado no lo muestra
                {
                    vecAvion[i].mostrar();
                    cout << "-----------------------" << endl;
                }
            }
            else
            {
                vecAvion[i].mostrar();
                cout << "-----------------------" << endl;
            }
        }
    }
    delete [] vecAvion;
}

/// MODIFICAR AVION
void Menu::modificarAvion()//MODIFICA MISIL EXISTENTE EN ARCHIVO
{
    Validar validar;
    ArchivoAvion ArchAvion;
    Avion reg;
    int id;
    int pos;
    string respuesta;
    cin.ignore();//arregla de subMenu Misil el "cin>>opcion;" sino se saltea el LISTAR MISILES.
    cout << "LISTAR AVIONES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarAviones(false);
    }

    cout << "INGRESE EL ID A MODIFICAR: ";
    cin >> id;
    cin.ignore();//sino esta se saltea "DESEA MODIFICAR ESTE REGISTRO?"
    pos = ArchAvion.buscarXId(id);

    if(pos != -1) // SI encontro el avion
    {
        reg = ArchAvion.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();
            cout << "DESEA MODIFICAR ESTE REGISTRO? (s / n): ";
            getline(cin, respuesta);
            long long precio;
            string paisOrigen;
            string descripcion;
            //si le ingresas cualquier otra cosa que no sea s/S RETURN al subMenuStock
            if(respuesta == "s" || respuesta == "S")
            {

                cout << "MAX 30 CARACTERES -> ING NUEVO PAIS DE ORIGEN: ";
                getline(cin, paisOrigen);
                while(!validar.esStringValido(paisOrigen,30))
                {
                    cout << "ERROR SOBREPASO LIMITE DE 30 CARACTERES" << endl;
                    system("pause");
                    system("cls");
                    cout << "REINGRESE PAIS DE ORIGEN:";
                    getline(cin, paisOrigen);
                }
                reg.setPaisOrigen(paisOrigen);

                cout << "MAX 100 CARACTERES -> ING NUEVA DESCRIPCION: ";
                getline(cin, descripcion);
                while(!validar.esStringValido(descripcion,100))
                {
                    cout << "ERROR SOBREPASO LIMITE DE 100 CARACTERES" << endl;
                    system("pause");
                    system("cls");
                    cout << "REINGRESE DESCRIPCION:";
                    getline(cin, descripcion);
                }
                reg.setDescripcion(descripcion);

                cout << "ING NUEVO PRECIO: $";
                cin >> precio;
                reg.setPrecio(precio);

                if(ArchAvion.guardar(reg,pos))
                {
                    cout << "Se modifico con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo modificar el avion!" << endl;
                }

            }
            else//NO eligio modificar el avion.
            {
                cout << "El avion no fue modificado" << endl;
            }
        }
        else
        {
            cout << "El avion no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El avion no se encuentra en el sistema." << endl;
    }
}

/// ELIMINAR AVION
void Menu::eliminarAvion()//ELIMINACION LOGICA DE PAIS EXISTENTE EN ARCHIVO
{
    int Id;
    int pos;
    Avion reg;
    ArchivoAvion ArchAvion;
    string respuesta;
    cin.ignore();//arregla de subMenuMisil el "cin>>opcion;" sino se saltea el LISTAR MISILES.
    cout << "LISTAR AVIONES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarAviones(false);
    }

    cout << "INGRESE EL ID A ELIMINAR: ";
    cin >> Id;
    cin.ignore();//sino se saltea "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): "

    pos = ArchAvion.buscarXId(Id);

    if(pos != -1)//si encontro el archivo
    {
        reg = ArchAvion.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();

            cout << "DESEA ELIMINAR ESTE REGISTRO? (s / n): ";
            getline(cin, respuesta);

            //si le ingresas cualquier otra cosa que no sea "s/S" RETURN al subMenuMisil
            if(respuesta == "s" || respuesta == "S")//SI eligio eliminar el Avion.
            {
                reg.setEstado(false);

                if(ArchAvion.guardar(reg, pos))
                {
                    cout << "Se elimino con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo eliminar el avion!" << endl;
                }
            }
            else//NO eligio eliminar el avion.
            {
                cout << "El avion no fue eliminado!" << endl;
            }
        }
        else
        {
            cout << "El avion no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El avion no se encuentra en el sistema." << endl;
    }
}

/// AGREGAR STOCK AVION
void Menu::agregarStockAvion()//ACUMULA STOCK DE MISILES
{
    int Id;
    int pos;
    Avion reg;
    ArchivoAvion ArchAvion;
    string respuesta;
    int stock = 0;
    cin.ignore();//arregla de subMenuAvion el "cin>>opcion;" sino se saltea el LISTAR MISILES.
    cout << "LISTAR AVIONES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarAviones(false);
    }

    cout << "INGRESE EL ID A AGREGAR STOCK: ";
    cin >> Id;
    cin.ignore();//sino se saltea "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): "

    pos = ArchAvion.buscarXId(Id);

    if(pos != -1)//si encontro el archivo
    {
        reg = ArchAvion.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();

            cout << "DESEA AGREGAR STOCK? (s / n): ";
            getline(cin, respuesta);

            //si le ingresas cualquier otra cosa que no sea "s/S" RETURN al subMenuAvion
            if(respuesta == "s" || respuesta == "S")//SI eligio agregar stock al Avion.
            {
                cout << "INGRESE STOCK A AGREGAR: ";
                cin >> stock;
                stock += reg.getStock();
                reg.setStock(stock);

                if(ArchAvion.guardar(reg, pos))
                {
                    cout << "Se agrego stock con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo agregar stock!" << endl;
                }
            }
            else//NO eligio agregar stock al Avion.
            {
                cout << "El stock no fue modificado!" << endl;
            }
        }
        else
        {
            cout << "El avion no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El avion no se encuentra en el sistema." << endl;
    }
}

/// SUBMENU STOCK BUQUE
void Menu::subMenuStockBuques()//SUBMENU ABM BUQUE QUE ESTA DENTRO DE LAS OPCIONES DEL MENU STOCK ADMIN
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

        gotoxy (2,9);
        cout << "1 - ALTA DE BUQUE";
        gotoxy (2,10);
        cout << "2 - BAJA DE BUQUE" << endl;
        gotoxy (2,11);
        cout << "3 - MODIFICACION DE BUQUE";
        gotoxy(2,12);
        cout << "4 - AGREGAR A STOCK" << endl;
        gotoxy(2,13);
        cout << "0 - VOLVER ATRAS" << endl;
        gotoxy(2,15);
        cout<<"INGRESE UNA OPCION: ";

        cin >> opcion;

        switch(opcion)
        {

        case 1:
            system("cls");
            altaBuque();
            system("pause");
            break;

        case 2:
            system("cls");
            eliminarBuque();
            system("pause");
            break;

        case 3:
            system("cls");
            modificarBuque();
            system("pause");
            break;

        case 4:
            system("cls");
            agregarStockBuque();
            system("pause");
            break;

        case 0:
            break;

        default:
            gotoxy (2,18);
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            gotoxy (2,19);
            system("pause");
            break;
        }
    }
}

/// ALTA BUQUE
void Menu::altaBuque()//CARGA UN NUEVO BUQUE AL ARCHIVO
{
    int id;
    Buque regBuque;
    ArchivoBuque ArchBuque;
    NombreProducto regNombreProducto;
    ArchivoNombreProducto ArchNombreProducto;

    id = ArchBuque.getNuevoId(); //obtiene nuevo ID autonumerico.
    regBuque.cargar(id);//carga un nuevo regBuque setenadole el ID obtenido
    regNombreProducto.setNombre(regBuque.getNombre());

    if(ArchBuque.guardar(regBuque) && ArchNombreProducto.guardar(regNombreProducto)) //lo carga en archivo
    {
        cout << "ALTA EXITOSA..." << endl;

    }
    else
    {
        cout << "NO SE HA PODIDO GRABAR EL REGISTRO.";
    }
}

/// MOSTRAR BUQUES
void Menu::mostrarBuques(bool ordenadoPorEstado, bool mostrarEliminados)
{
    ArchivoBuque ArchBuque;
    Buque *vecBuque = nullptr;//OJO!!! DINAMICO inicializar/verificar/delete corchetes? XQ NOC CUANTOS REGISTROS PUEDEN LLEGAR A SER

    int cant = ArchBuque.getCantidadReg();

    vecBuque = new Buque[cant];

    //verifico memoria
    if(vecBuque == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        system("pause");
        return;
    }

    if(ArchBuque.leerTodos(vecBuque,cant))
    {

        if (ordenadoPorEstado)
        {
            ordenarPorEstado(vecBuque, cant);
        }

        for(int i=0; i<cant; i++)
        {
            if(!mostrarEliminados)
            {
                if(vecBuque[i].getEstado())//si esta eliminado no lo muestra
                {
                    vecBuque[i].mostrar();
                    cout << "-----------------------" << endl;
                }
            }
            else
            {
                vecBuque[i].mostrar();
                cout << "-----------------------" << endl;
            }
        }
    }
    delete [] vecBuque;
}

/// MODIFICAR BUQUE
void Menu::modificarBuque()//MODIFICA BUQUE EXISTENTE EN ARCHIVO
{
    Validar validar;
    ArchivoBuque ArchBuque;
    Buque reg;
    int id;
    int pos;
    string respuesta;
    cin.ignore();//arregla de subMenu Buque el "cin>>opcion;" sino se saltea el LISTAR BUQUES.
    cout << "LISTAR BUQUES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarBuques(false);
    }

    cout << "INGRESE EL ID A MODIFICAR: ";
    cin >> id;
    cin.ignore();//sino esta se saltea "DESEA MODIFICAR ESTE REGISTRO?"
    pos = ArchBuque.buscarXId(id);

    if(pos != -1) // SI encontro el Buque
    {
        reg = ArchBuque.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();
            cout << "DESEA MODIFICAR ESTE REGISTRO? (s / n): ";
            getline(cin, respuesta);
            long long precio;
            string paisOrigen;
            string descripcion;
            //si le ingresas cualquier otra cosa que no sea s/S RETURN al subMenuStock
            if(respuesta == "s" || respuesta == "S")
            {

                cout << "MAX 30 CARACTERES -> ING NUEVO PAIS DE ORIGEN: ";
                getline(cin, paisOrigen);
                while(!validar.esStringValido(paisOrigen,30))
                {
                    cout << "ERROR SOBREPASO LIMITE DE 30 CARACTERES" << endl;
                    system("pause");
                    system("cls");
                    cout << "REINGRESE PAIS DE ORIGEN:";
                    getline(cin, paisOrigen);
                }
                reg.setPaisOrigen(paisOrigen);

                cout << "MAX 100 CARACTERES -> ING NUEVA DESCRIPCION: ";
                getline(cin, descripcion);
                while(!validar.esStringValido(descripcion,100))
                {
                    cout << "ERROR SOBREPASO LIMITE DE 100 CARACTERES" << endl;
                    system("pause");
                    system("cls");
                    cout << "REINGRESE DESCRIPCION:";
                    getline(cin, descripcion);
                }
                reg.setDescripcion(descripcion);

                cout << "ING NUEVO PRECIO: $";
                cin >> precio;
                reg.setPrecio(precio);

                if(ArchBuque.guardar(reg,pos))
                {
                    cout << "Se modifico con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo modificar el buque!" << endl;
                }

            }
            else//NO eligio modificar el buque.
            {
                cout << "El buque no fue modificado" << endl;
            }
        }
        else
        {
            cout << "El buque no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El buque no se encuentra en el sistema." << endl;
    }
}

/// ELIMINAR BUQUE
void Menu::eliminarBuque()//ELIMINACION LOGICA DE BUQUE EXISTENTE EN ARCHIVO
{
    int Id;
    int pos;
    Buque reg;
    ArchivoBuque ArchBuque;
    string respuesta;
    cin.ignore();//arregla de subMenuBuque el "cin>>opcion;" sino se saltea el LISTAR BUQUES.
    cout << "LISTAR BUQUES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarBuques(false);
    }

    cout << "INGRESE EL ID A ELIMINAR: ";
    cin >> Id;
    cin.ignore();//sino se saltea "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): "

    pos = ArchBuque.buscarXId(Id);

    if(pos != -1)//si encontro el archivo
    {
        reg = ArchBuque.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();

            cout << "DESEA ELIMINAR ESTE REGISTRO? (s / n): ";
            getline(cin, respuesta);

            //si le ingresas cualquier otra cosa que no sea "s/S" RETURN al subMenuBuque
            if(respuesta == "s" || respuesta == "S")//SI eligio eliminar el Buque.
            {
                reg.setEstado(false);

                if(ArchBuque.guardar(reg, pos))
                {
                    cout << "Se elimino con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo eliminar el buque!" << endl;
                }
            }
            else//NO eligio eliminar el buque.
            {
                cout << "El buque no fue eliminado!" << endl;
            }
        }
        else
        {
            cout << "El buque no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El buque no se encuentra en el sistema." << endl;
    }
}

/// AGREGAR STOCK BUQUE
void Menu::agregarStockBuque()//ACUMULA STOCK DE BUQUES
{
    int Id;
    int pos;
    Buque reg;
    ArchivoBuque ArchBuque;
    string respuesta;
    int stock = 0;
    cin.ignore();//arregla de subMenuBuque el "cin>>opcion;" sino se saltea el LISTAR BUQUES.
    cout << "LISTAR BUQUES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarBuques(false);
    }

    cout << "INGRESE EL ID A AGREGAR STOCK: ";
    cin >> Id;
    cin.ignore();//sino se saltea "DESEA AGREGAR STOCK?? (s / n): "

    pos = ArchBuque.buscarXId(Id);

    if(pos != -1)//si encontro el archivo
    {
        reg = ArchBuque.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();

            cout << "DESEA AGREGAR STOCK? (s / n): ";
            getline(cin, respuesta);

            //si le ingresas cualquier otra cosa que no sea "s/S" RETURN al subMenuBuque
            if(respuesta == "s" || respuesta == "S")//SI eligio agregar stock al Buque.
            {
                cout << "INGRESE STOCK A AGREGAR: ";
                cin >> stock;
                stock += reg.getStock();
                reg.setStock(stock);

                if(ArchBuque.guardar(reg, pos))
                {
                    cout << "Se agrego stock con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo agregar stock!" << endl;
                }
            }
            else//NO eligio agregar stock al Buque.
            {
                cout << "El stock no fue modificado!" << endl;
            }
        }
        else
        {
            cout << "El buque no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El buque no se encuentra en el sistema." << endl;
    }
}

/// SUBMENU STOCK TANQUE
void Menu::subMenuStockTanques()//SUBMENU ABM TANQUE QUE ESTA DENTRO DE LAS OPCIONES DEL MENU STOCK ADMIN
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

        gotoxy (2,9);
        cout << "1 - ALTA DE TANQUE";
        gotoxy (2,10);
        cout << "2 - BAJA DE TANQUE" << endl;
        gotoxy (2,11);
        cout << "3 - MODIFICACION DE TANQUE";
        gotoxy(2,12);
        cout << "4 - AGREGAR A STOCK" << endl;
        gotoxy(2,13);
        cout << "0 - VOLVER ATRAS" << endl;
        gotoxy(2,15);
        cout<<"INGRESE UNA OPCION: ";

        cin>>opcion;

        switch(opcion)
        {

        case 1:
            system("cls");
            altaTanque();
            system("pause");
            break;

        case 2:
            system("cls");
            eliminarTanque();
            system("pause");
            break;

        case 3:
            system("cls");
            modificarTanque();
            system("pause");
            break;

        case 4:
            system("cls");
            agregarStockTanque();
            system("pause");
            break;

        case 0:
            break;

        default:
            gotoxy (2,18);
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            gotoxy (2,19);
            system("pause");
            break;
        }
    }
}

/// ALTA TANQUE
void Menu::altaTanque()//CARGA UN NUEVO BUQUE AL ARCHIVO
{
    int id;
    Tanque regTanque;
    ArchivoTanque ArchTanque;
    NombreProducto regNombreProducto;
    ArchivoNombreProducto ArchNombreProducto;

    id = ArchTanque.getNuevoId(); //obtiene nuevo ID autonumerico.
    regTanque.cargar(id);//carga un nuevo regTanque setenadole el ID obtenido
    regNombreProducto.setNombre(regTanque.getNombre());

    if(ArchTanque.guardar(regTanque) && ArchNombreProducto.guardar(regNombreProducto)) //lo carga en archivo
    {
        cout << "ALTA EXITOSA..." << endl;

    }
    else
    {
        cout << "NO SE HA PODIDO GRABAR EL REGISTRO.";
    }
}

/// MOSTRAR TANQUES
void Menu::mostrarTanques(bool ordenadoPorEstado, bool mostrarEliminados)
{
    ArchivoTanque ArchTanque;
    Tanque *vecTanque = nullptr;//OJO!!! DINAMICO inicializar/verificar/delete corchetes? XQ NOC CUANTOS REGISTROS PUEDEN LLEGAR A SER

    int cant = ArchTanque.getCantidadReg();

    vecTanque = new Tanque[cant];

    //verifico memoria
    if(vecTanque == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        system("pause");
        return;
    }

    if(ArchTanque.leerTodos(vecTanque,cant))
    {

        if (ordenadoPorEstado)
        {
            ordenarPorEstado(vecTanque, cant);
        }

        for(int i=0; i<cant; i++)
        {
            if(!mostrarEliminados)
            {
                if(vecTanque[i].getEstado())//si esta eliminado no lo muestra
                {
                    vecTanque[i].mostrar();
                    cout << "-----------------------" << endl;
                }
            }
            else
            {
                vecTanque[i].mostrar();
                cout << "-----------------------" << endl;
            }
        }
    }
    delete [] vecTanque;
}


/// MODIFICAR TANQUE
void Menu::modificarTanque()//MODIFICA TANQUE EXISTENTE EN ARCHIVO
{
    Validar validar;
    ArchivoTanque ArchTanque;
    Tanque reg;
    int id;
    int pos;
    string respuesta;
    cin.ignore();//arregla de subMenu Tanque el "cin>>opcion;" sino se saltea el LISTAR TANQUES.
    cout << "LISTAR TANQUES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarTanques(false);
    }

    cout << "INGRESE EL ID A MODIFICAR: ";
    cin >> id;
    cin.ignore();//sino esta se saltea "DESEA MODIFICAR ESTE REGISTRO?"
    pos = ArchTanque.buscarXId(id);

    if(pos != -1) // SI encontro el Buque
    {
        reg = ArchTanque.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();
            cout << "DESEA MODIFICAR ESTE REGISTRO? (s / n): ";
            getline(cin, respuesta);
            long long precio;
            string paisOrigen;
            string descripcion;
            //si le ingresas cualquier otra cosa que no sea s/S RETURN al subMenuTanque
            if(respuesta == "s" || respuesta == "S")
            {

                cout << "MAX 30 CARACTERES -> ING NUEVO PAIS DE ORIGEN: ";
                getline(cin, paisOrigen);
                while(!validar.esStringValido(paisOrigen,30))
                {
                    cout << "ERROR SOBREPASO LIMITE DE 30 CARACTERES" << endl;
                    system("pause");
                    system("cls");
                    cout << "REINGRESE PAIS DE ORIGEN:";
                    getline(cin, paisOrigen);
                }
                reg.setPaisOrigen(paisOrigen);

                cout << "MAX 100 CARACTERES -> ING NUEVA DESCRIPCION: ";
                getline(cin, descripcion);
                while(!validar.esStringValido(descripcion,100))
                {
                    cout << "ERROR SOBREPASO LIMITE DE 100 CARACTERES" << endl;
                    system("pause");
                    system("cls");
                    cout << "REINGRESE DESCRIPCION:";
                    getline(cin, descripcion);
                }
                reg.setDescripcion(descripcion);

                cout << "ING NUEVO PRECIO: $";
                cin >> precio;
                reg.setPrecio(precio);

                if(ArchTanque.guardar(reg,pos))
                {
                    cout << "Se modifico con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo modificar el tanque!" << endl;
                }

            }
            else//NO eligio modificar el tanque.
            {
                cout << "El tanque no fue modificado" << endl;
            }
        }
        else
        {
            cout << "El tanque no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El tanque no se encuentra en el sistema." << endl;
    }
}

/// ELIMINAR TANQUE
void Menu::eliminarTanque()//ELIMINACION LOGICA DE TANQUE EXISTENTE EN ARCHIVO
{
    int Id;
    int pos;
    Tanque reg;
    ArchivoTanque ArchTanque;
    string respuesta;
    cin.ignore();//arregla de subMenuTanque el "cin>>opcion;" sino se saltea el LISTAR TANQUES.
    cout << "LISTAR TANQUES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarTanques(false);
    }

    cout << "INGRESE EL ID A ELIMINAR: ";
    cin >> Id;
    cin.ignore();//sino se saltea "DESEA DAR DE BAJA ESTE REGISTRO? (s / n): "

    pos = ArchTanque.buscarXId(Id);

    if(pos != -1)//si encontro el archivo
    {
        reg = ArchTanque.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();

            cout << "DESEA ELIMINAR ESTE REGISTRO? (s / n): ";
            getline(cin, respuesta);

            //si le ingresas cualquier otra cosa que no sea "s/S" RETURN al subMenuTanque
            if(respuesta == "s" || respuesta == "S")//SI eligio eliminar el Tanque.
            {
                reg.setEstado(false);

                if(ArchTanque.guardar(reg, pos))
                {
                    cout << "Se elimino con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo eliminar el tanque!" << endl;
                }
            }
            else//NO eligio eliminar el tanque.
            {
                cout << "El tanque no fue eliminado!" << endl;
            }
        }
        else
        {
            cout << "El tanque no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El tanque no se encuentra en el sistema." << endl;
    }
}

/// AGREGAR STOCK TANQUE
void Menu::agregarStockTanque()//ACUMULA STOCK DE TANQUES
{
    int Id;
    int pos;
    Tanque reg;
    ArchivoTanque ArchTanque;
    string respuesta;
    int stock = 0;
    cin.ignore();//arregla de subMenuTanque el "cin>>opcion;" sino se saltea el LISTAR TANQUES.
    cout << "LISTAR TANQUES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarTanques(false);
    }

    cout << "INGRESE EL ID A AGREGAR STOCK: ";
    cin >> Id;
    cin.ignore();//sino se saltea "DESEA AGREGAR STOCK?? (s / n): "

    pos = ArchTanque.buscarXId(Id);

    if(pos != -1)//si encontro el archivo
    {
        reg = ArchTanque.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();

            cout << "DESEA AGREGAR STOCK? (s / n): ";
            getline(cin, respuesta);

            //si le ingresas cualquier otra cosa que no sea "s/S" RETURN al subMenuTanque
            if(respuesta == "s" || respuesta == "S")//SI eligio agregar stock al Tanque.
            {
                cout << "INGRESE STOCK A AGREGAR: ";
                cin >> stock;
                stock += reg.getStock();
                reg.setStock(stock);

                if(ArchTanque.guardar(reg, pos))
                {
                    cout << "Se agrego stock con exito!" << endl;
                }
                else
                {
                    cout << "No se pudo agregar stock!" << endl;
                }
            }
            else//NO eligio agregar stock al Tanque.
            {
                cout << "El stock no fue modificado!" << endl;
            }
        }
        else
        {
            cout << "El tanque no se encuentra en el sistema." << endl;
        }
    }
    else
    {
        cout << "El tanque no se encuentra en el sistema." << endl;
    }
}

/// MENU LISTADOS
void Menu::menuListados()//SUBMENU LISTADOS QUE ESTA DENTRO DE LAS OPCIONES DEL MENU PRINCIPAL ADMIN
{
    opcion = -1;

    while(opcion!=0)
    {
        cabecera();

        gotoxy (2,6);
        cout<<"MENU LISTADOS";
        gotoxy (2,7);
        cout<<"-------------";

        gotoxy (2,9);
        cout << "1 - PAISES";
        gotoxy (2,10);
        cout << "2 - ADMINISTRADORES";
        gotoxy (2,11);
        cout << "3 - MISILES";
        gotoxy (2,12);
        cout << "4 - AVIONES";
        gotoxy (2,13);
        cout << "5 - BUQUES";
        gotoxy (2,14);
        cout << "6 - TANQUES";
        gotoxy (2,15);
        cout << "0 - VOLVER ATRAS";
        gotoxy (2,17);
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;

        switch(opcion)
        {

        case 1:
            system("cls");
            listarPaises();
            system("pause");
            break;

        case 2:
            system("cls");
            listarAdmins();
            system("pause");
            break;

        case 3:
            system("cls");
            listarMisiles();
            system("pause");
            break;

        case 4:
            system("cls");
            listarAviones();
            system("pause");
            break;

        case 5:
            system("cls");
            listarBuques();
            system("pause");
            break;

        case 6:
            system("cls");
            listarTanques();
            system("pause");
            break;

        case 0:
            break;

        default:
            gotoxy (2,20);
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            gotoxy (2,21);
            system("pause");
            break;
        }
    }
}

///LISTAR ARMINISTRADORES
void Menu::listarAdmins()//LISTA LOS ADMINS ORDENADOS Y PREGUNTA SI QUERES VERLOS A TODOS
{
    string respuesta;
    cin.ignore();//arregla de MenuListados el "cin>>opcion;" sino se saltea el LISTAR ADMINISTRADORES ELIMINADOS
    cout << "LISTAR ADMINISTRADORES ELIMINADOS? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarAdmins(true, true);
    }
    else
    {
        mostrarAdmins(false);
    }
}

///LISTAR PAISES
void Menu::listarPaises()//LISTA LOS PAISES ORDENADOS Y PREGUNTA SI QUERES VERLOS A TODOS
{
    string respuesta;
    cin.ignore();//arregla de MenuListados el "cin>>opcion;" sino se saltea el LISTAR PAISES ELIMINADOS
    cout << "LISTAR PAISES ELIMINADOS? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarPaises(true, true);
    }
    else
    {
        mostrarPaises(false);
    }
}

///LISTAR MISILES
void Menu::listarMisiles()//LISTA LOS MISILES ORDENADOS Y PREGUNTA SI QUERES VERLOS A TODOS
{
    string respuesta;
    cin.ignore();//arregla de MenuListados el "cin>>opcion;" sino se saltea el LISTAR MISILES ELIMINADOS
    cout << "LISTAR MISILES ELIMINADOS? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarMisiles(true, true);
    }
    else
    {
        mostrarMisiles(false);
    }
}

///LISTAR AVIONES
void Menu::listarAviones()//LISTA LOS AVIONES ORDENADOS Y PREGUNTA SI QUERES VERLOS A TODOS
{
    string respuesta;
    cin.ignore();//arregla de MenuListados el "cin>>opcion;" sino se saltea el LISTAR AVIONES ELIMINADOS
    cout << "LISTAR AVIONES ELIMINADOS? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarAviones(true, true);
    }
    else
    {
        mostrarAviones(false);
    }
}

///LISTAR BUQUES
void Menu::listarBuques()//LISTA LOS BUQUES ORDENADOS Y PREGUNTA SI QUERES VERLOS A TODOS
{
    string respuesta;
    cin.ignore();//arregla de MenuListados el "cin>>opcion;" sino se saltea el LISTAR BUQUES ELIMINADOS
    cout << "LISTAR BUQUES ELIMINADOS? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarBuques(true, true);
    }
    else
    {
        mostrarBuques(false);
    }
}

///LISTAR TANQUES
void Menu::listarTanques()//LISTA LOS TANQUES ORDENADOS Y PREGUNTA SI QUERES VERLOS A TODOS
{
    string respuesta;
    cin.ignore();//arregla de MenuListados el "cin>>opcion;" sino se saltea el LISTAR TANQUES ELIMINADOS
    cout << "LISTAR TANQUES ELIMINADOS? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarTanques(true, true);
    }
    else
    {
        mostrarTanques(false);
    }
}

///ORDENAR USUARIOS POR ESTADO SOBRECARGA
void Menu::ordenarPorEstado(Admin *vecAdmin, int cantidad)
{
    int i, j;
    int posEstado;

    for(i = 0; i < cantidad - 1; i++)
    {
        posEstado = i;

        for (j = i + 1; j < cantidad; j++)
        {
            if (vecAdmin[j].getEstado() > vecAdmin[posEstado].getEstado())
            {
                posEstado = j;
            }
        }

        if (i != posEstado)
        {
            Admin aux = vecAdmin[i];
            vecAdmin[i] = vecAdmin[posEstado];
            vecAdmin[posEstado] = aux;
        }
    }
}

///ORDENAR USUARIOS POR ESTADO SOBRECARGA
void Menu::ordenarPorEstado(Pais *vecPais, int cantidad)
{
    int i, j;
    int posEstado;

    for(i = 0; i < cantidad - 1; i++)
    {
        posEstado = i;

        for (j = i + 1; j < cantidad; j++)
        {
            if (vecPais[j].getEstado() > vecPais[posEstado].getEstado())
            {
                posEstado = j;
            }
        }

        if (i != posEstado)
        {
            Pais aux = vecPais[i];
            vecPais[i] = vecPais[posEstado];
            vecPais[posEstado] = aux;
        }
    }
}

///ORDENAR PRODUCTOS POR ESTADO SOBRECARGA
void Menu::ordenarPorEstado(Misil *vecMisil, int cantidad)
{
    int i, j;
    int posEstado;

    for(i = 0; i < cantidad - 1; i++)
    {
        posEstado = i;

        for (j = i + 1; j < cantidad; j++)
        {
            if (vecMisil[j].getEstado() > vecMisil[posEstado].getEstado())
            {
                posEstado = j;
            }
        }

        if (i != posEstado)
        {
            Misil aux = vecMisil[i];
            vecMisil[i] = vecMisil[posEstado];
            vecMisil[posEstado] = aux;
        }
    }
}

///ORDENAR PRODUCTOS POR ESTADO SOBRECARGA
void Menu::ordenarPorEstado(Avion *vecAvion, int cantidad)
{
    int i, j;
    int posEstado;

    for(i = 0; i < cantidad - 1; i++)
    {
        posEstado = i;

        for (j = i + 1; j < cantidad; j++)
        {
            if (vecAvion[j].getEstado() > vecAvion[posEstado].getEstado())
            {
                posEstado = j;
            }
        }

        if (i != posEstado)
        {
            Avion aux = vecAvion[i];
            vecAvion[i] = vecAvion[posEstado];
            vecAvion[posEstado] = aux;
        }
    }
}

///ORDENAR PRODUCTOS POR ESTADO SOBRECARGA
void Menu::ordenarPorEstado(Buque *vecBuque, int cantidad)
{
    int i, j;
    int posEstado;

    for(i = 0; i < cantidad - 1; i++)
    {
        posEstado = i;

        for (j = i + 1; j < cantidad; j++)
        {
            if (vecBuque[j].getEstado() > vecBuque[posEstado].getEstado())
            {
                posEstado = j;
            }
        }

        if (i != posEstado)
        {
            Buque aux = vecBuque[i];
            vecBuque[i] = vecBuque[posEstado];
            vecBuque[posEstado] = aux;
        }
    }
}

///ORDENAR PRODUCTOS POR ESTADO SOBRECARGA
void Menu::ordenarPorEstado(Tanque *vecTanque, int cantidad)
{
    int i, j;
    int posEstado;

    for(i = 0; i < cantidad - 1; i++)
    {
        posEstado = i;

        for (j = i + 1; j < cantidad; j++)
        {
            if (vecTanque[j].getEstado() > vecTanque[posEstado].getEstado())
            {
                posEstado = j;
            }
        }

        if (i != posEstado)
        {
            Tanque aux = vecTanque[i];
            vecTanque[i] = vecTanque[posEstado];
            vecTanque[posEstado] = aux;
        }
    }
}

/// MENU REPORTES
void Menu::menuReportes()//SUBMENU REPORTES QUE ESTA DENTRO DE LAS OPCIONES DEL MENU PRINCIPAL ADMIN
{
    opcion = -1;

    while(opcion!=0)
    {
        cabecera();

        gotoxy (2,6);
        cout<<"MENU REPORTES";
        gotoxy (2,7);
        cout<<"-------------";

        gotoxy (2,9);
        cout<<"1 - VER FACTURAS";
        gotoxy (2,10);
        cout<<"2 - BUSCAR FACTURAS POR PAIS";
        gotoxy (2,11);
        cout<<"3 - RANKING DE PAISES";
        gotoxy (2,12);
        cout<<"4 - RANKING DE PRODUCTOS";
        gotoxy (2,13);
        cout<<"0 - MENU ANTERIOR";
        gotoxy (2,15);
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;

        switch(opcion)
        {

        case 1:
            system("cls");
            verFacturas();
            system("pause");
            break;

        case 2:
            system("cls");
            buscarFacturasPais();
            system("pause");
            break;

        case 3:
            system("cls");
            rankingPaises();
            system("pause");
            break;

        case 4:
            system("cls");
            rankingProductos();
            system("pause");
            break;

        case 0:
            break;

        default:
            gotoxy (2,18);
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            gotoxy (2,19);
            system("pause");
            break;
        }
    }
}
/// MOSTRAR FACTURAS
void Menu::verFacturas()
{
    ArchivoVenta archivoVenta;
    int cantRegVenta;
    Venta *vecRegVenta = nullptr;
    int cantRegDetalle;
    ArchivoDetalleVenta archivoDetalle;
    DetalleVenta *vecDetalleVenta = nullptr;
    //int item=0;

    cantRegDetalle = archivoDetalle.getCantidadReg();
    vecDetalleVenta = new DetalleVenta [cantRegDetalle];

    if (vecDetalleVenta == nullptr)
    {
        return;
    }

    cantRegVenta = archivoVenta.getCantidadReg();
    vecRegVenta = new Venta[cantRegVenta];

    if (vecRegVenta == nullptr)
    {
        return;
    }


    cout<< "<< FACTURAS EMITIDAS >> "<<endl;

    archivoDetalle.leerTodos(vecDetalleVenta, cantRegDetalle);

    archivoVenta.leerTodos(vecRegVenta, cantRegVenta);

    for (int i=0; i<cantRegVenta; i++)
    {
        //item=0;
        vecRegVenta[i].mostrar();

        for (int j=0; j<cantRegDetalle; j++)
        {

            if (vecRegVenta[i].getId()== vecDetalleVenta[j].getIdVenta())
            {

                if(vecDetalleVenta[j].getIdProducto()!=-1)
                {
                    //item++;
                    //cout << "----------------------" <<endl;
                    //cout<<"NUMERO ITEM: "<< item<<endl;
                    vecDetalleVenta[j].mostrar();

                }
            }

        }

    }

    delete [] vecRegVenta;
    delete [] vecDetalleVenta;
}

/// BUSCAR FACTURAS POR PAIS
void Menu::buscarFacturasPais()
{
    ArchivoVenta archivoVenta;
    int cantRegVenta;
    Venta *vecRegVenta = nullptr;
    int cantRegDetalle;
    ArchivoDetalleVenta archivoDetalle;
    DetalleVenta *vecDetalleVenta = nullptr;
    string respuesta;
    int posPais;
    Pais regPais;
    ArchivoPais archPais;
    int id;
    int item=0;


    cantRegVenta = archivoVenta.getCantidadReg();
    vecRegVenta = new Venta[cantRegVenta];

    if (vecRegVenta == nullptr)
    {
        return;
    }

    cantRegDetalle = archivoDetalle.getCantidadReg();
    vecDetalleVenta = new DetalleVenta [cantRegDetalle];

    if (vecDetalleVenta == nullptr)
    {
        return;
    }

    archivoVenta.leerTodos(vecRegVenta, cantRegVenta);
    archivoDetalle.leerTodos(vecDetalleVenta, cantRegDetalle);

    cin.ignore();//arregla de subMenuAdmin REPORTES el "cin>>opcion;"
    cout << "LISTAR PAISES? (s / n): ";
    getline(cin, respuesta);

    if(respuesta == "s" || respuesta == "S")
    {
        mostrarPaises(false);
    }

    cout << "INGRESE EL ID DEL PAIS QUE DESEA VER LAS FACTURAS: ";
    cin >> id;
    cin.ignore();//sino esta se saltea "INGRESE EL ID DEL PAIS QUE DESEA VER LAS FACTURAS"
    system ("cls");

    posPais = archPais.buscarXId(id);

    if(posPais != -1) // SI encontro el pais
    {
        regPais = archPais.leer(posPais);

        cout<< "<< COMPRAS REALIZADAS >> CLIENTE : " <<regPais.getUsuario()<<endl;


        for (int i=0; i<cantRegVenta; i++)
        {
            item=0;

            if (regPais.getId()== vecRegVenta[i].getIdCliente())
            {
                vecRegVenta[i].mostrar();


                for (int j=0; j<cantRegDetalle; j++)
                {
                    if(vecRegVenta[i].getId() == vecDetalleVenta[j].getIdVenta())
                    {
                        if(vecDetalleVenta[j].getIdProducto()!=-1)
                        {

                            item++;
                            cout << "----------------------" <<endl;
                            cout<<"NUMERO ITEM: "<< item<<endl;
                            vecDetalleVenta[j].mostrar();
                        }
                    }
                }
            }
        }
    }

    delete[] vecRegVenta;
    delete [] vecDetalleVenta;
}

///ORDENAR DECRECIENTE SOBRECARGADO
void Menu::ordenarDecreciente(long long *vec, string *vecString, int tam)
{
    int i, j;
    long long aux;
    string auxString;

    for(i=0; i<tam-1; i++)
    {

        for(j=i+1; j<tam; j++)
        {

            if(vec[j] > vec[i]) /// DECRECIENTE
            {
                aux = vec[j];
                vec[j] = vec[i];
                vec[i] = aux;

                auxString = vecString[j];
                vecString[j] = vecString[i];
                vecString[i] = auxString;
            }
        }
    }
}

///ORDENAR DECRECIENTE SOBRECARGADO
void Menu::ordenarDecreciente(NombreProductoCantidad *vec, int tam)
{
    int i, j;
    NombreProductoCantidad aux;

    for(i=0; i<tam-1; i++)
    {

        for(j=i+1; j<tam; j++)
        {

            if(vec[j].getCantidad() > vec[i].getCantidad()) /// DECRECIENTE
            {
                aux = vec[j];
                vec[j] = vec[i];
                vec[i] = aux;
            }
        }
    }
}

///RANKING DE PAISES
void Menu::rankingPaises()
{
    ArchivoVenta archVenta;
    Venta regVenta;
    ArchivoPais archPais;
    Pais regPais;
    int cantRegPais;
    int cantRegVenta;

    long long *vecTotalVentasXPais = nullptr;
    string *vecNombrePais = nullptr;

    cantRegPais = archPais.getCantidadReg();
    vecTotalVentasXPais = new long long[cantRegPais];
    vecNombrePais = new string[cantRegPais];

    if (vecTotalVentasXPais == nullptr)
    {
        return;
    }

    if (vecNombrePais == nullptr)
    {
        return;
    }

    for (int i = 0; i < cantRegPais; i++)
    {
        vecTotalVentasXPais[i] = 0;
    }

    cantRegVenta = archVenta.getCantidadReg();

    for(int i=0; i < cantRegVenta; i++)
    {
        regVenta = archVenta.leer(i);

        vecTotalVentasXPais[regVenta.getIdCliente() - 1] += regVenta.getMontoTotal();
    }

    for(int i=0; i < cantRegPais; i++)
    {
        regPais = archPais.leer(i);

        vecNombrePais[regPais.getId() - 1] = regPais.getUsuario();
    }



    ordenarDecreciente(vecTotalVentasXPais, vecNombrePais, cantRegPais);


    cout << "============================================================" << endl;
    cout << "                        RANKING DE PAISES                   " << endl;
    cout << "============================================================" << endl;

    for(int i = 0; i < cantRegPais; i++)
    {

        cout << vecNombrePais[i] << " TOTAL GASTADO: $" << vecTotalVentasXPais[i] << endl;

    }


    delete[] vecTotalVentasXPais;
    delete[] vecNombrePais;
}

void Menu::quitarRepetidos(NombreProductoCantidad *vectorSinProcesar, int cantSinProcesar, NombreProductoCantidad *vectorSinRepetidos, int &cantProcesado)
{
    int i, j;
    cantProcesado = 0; // Inicializamos la cantidad procesada a 0

    for (i = 0; i < cantSinProcesar; i++)
    {
        bool estaRepetido = false;

        // Verificar si vectorSinProcesar[i] est� en vectorSinRepetidos
        for (j = 0; j < cantProcesado; j++)
        {
            if (vectorSinProcesar[i].getNombre() == vectorSinRepetidos[j].getNombre())
            {
                estaRepetido = true;
                break;
            }
        }

        // Si el elemento no est� en vectorSinRepetidos, lo a�adimos
        if (!estaRepetido)
        {
            vectorSinRepetidos[cantProcesado] = vectorSinProcesar[i]; // A�adimos el elemento
            cantProcesado++; // Incrementamos la cantidad de elementos �nicos
        }
    }
}

/// RANKING DE PRODUCTOS

void Menu::rankingProductos()
{
    NombreProductoCantidad *vecNombreProductoCantidadRepetido = nullptr;
    NombreProductoCantidad *vecNombreProductoCantidad = nullptr;
    ArchivoDetalleVenta archDetalleVenta;
    ArchivoMisil archMisil;
    ArchivoAvion archAvion;
    ArchivoBuque archBuque;
    ArchivoTanque archTanque;
    DetalleVenta regDetalleVenta;
    int cantRegProductos = 0;
    int cantRegDetalleVenta;

    cantRegDetalleVenta = archDetalleVenta.getCantidadReg();

    vecNombreProductoCantidadRepetido = new NombreProductoCantidad[cantRegDetalleVenta];

    if (vecNombreProductoCantidadRepetido == nullptr)
    {
        return;
    }

    cantRegProductos += archMisil.getCantidadReg();
    cantRegProductos += archAvion.getCantidadReg();
    cantRegProductos += archBuque.getCantidadReg();
    cantRegProductos += archTanque.getCantidadReg();

    vecNombreProductoCantidad = new NombreProductoCantidad[cantRegProductos];

    if (vecNombreProductoCantidad == nullptr)
    {
        return;
    }


    for(int i = 0; i < cantRegDetalleVenta; i++)
    {
        regDetalleVenta = archDetalleVenta.leer(i);

        vecNombreProductoCantidadRepetido[i].setNombre(regDetalleVenta.getNombreProducto());
        vecNombreProductoCantidadRepetido[i].setCantidad(regDetalleVenta.getCantidad());

    }

    quitarRepetidos(vecNombreProductoCantidadRepetido, cantRegDetalleVenta, vecNombreProductoCantidad, cantRegProductos);


    for(int i = 0; i < cantRegProductos; i++)
    {
        vecNombreProductoCantidad[i].setCantidad(0);
        for(int j = 0; j < cantRegDetalleVenta; j++)
        {
            if (vecNombreProductoCantidad[i].getNombre() == vecNombreProductoCantidadRepetido[j].getNombre())
            {
                vecNombreProductoCantidad[i].setCantidad(vecNombreProductoCantidad[i].getCantidad() + vecNombreProductoCantidadRepetido[j].getCantidad());

            }

        }
    }


    ordenarDecreciente(vecNombreProductoCantidad, cantRegProductos);

    cout << "============================================================" << endl;
    cout << "                      RANKING DE PRODUCTOS                  " << endl;
    cout << "============================================================" << endl;

    for(int i = 0; i < cantRegProductos; i++)
    {
        if(vecNombreProductoCantidad[i].getNombre() != "S/N")
        {
            cout << vecNombreProductoCantidad[i].getNombre() << " CANTIDAD VENDIDOS:" << vecNombreProductoCantidad[i].getCantidad() << endl;
        }
    }

    delete[] vecNombreProductoCantidadRepetido;
    delete[] vecNombreProductoCantidad;
}



/// MENU PRINCIPAL PAIS
void Menu::menuPrincipalPais(Pais &regPais)
{
    int opcion = -1;

    while(opcion!=0)
    {

        cabecera();

        gotoxy (2,6);
        cout << "MENU CLIENTE";
        gotoxy (2,7);
        cout << "------------";

        gotoxy (2,9);
        cout << "1 - SOLICITUD DE ADQUISICIONES";
        gotoxy (2,10);
        cout << "2 - CONSULTA DE DINERO EN CUENTA";
        gotoxy (2,11);
        cout << "3 - INGRESO DE DINERO EN CUENTA";
        gotoxy (2,12);
        cout << "4 - COMPRAS REALIZADAS";
        gotoxy (2,13);
        cout << "0 - SALIR DEL PROGRAMA";
        gotoxy (2,15);
        cout << "INGRESE UNA OPCION: ";

        cin >> opcion;

        switch(opcion)
        {
        case 1:
            system("cls");
            solicitudDeAdquisiciones(regPais);
            system("pause");
            break;

        case 2:
            system("cls");
            consultaDinero(regPais);
            system("pause");
            break;

        case 3:
            system("cls");
            ingresoDinero(regPais);
            system("pause");
            break;

        case 4:
            system("cls");
            comprasRealizadas(regPais);
            system("pause");
            break;

        case 0:
            break;

        default:
            gotoxy (2,18);
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            gotoxy (2,19);
            system("pause");
            break;
        }
    }
}

/// CONSULTA DE DINERO
void Menu::consultaDinero(Pais &regPais)
{

    ArchivoPais archPais;
    Pais registroPais;
    int posicion;

    posicion = archPais.buscarXId(regPais.getId());
    registroPais = archPais.leer(posicion);

    gotoxy (25,1);
    cout<<"-----------------------------";
    cout<<endl;
    gotoxy (28,3);
    cout<<"SALDO ACTUAL: U$D " << registroPais.getDineroCaja() <<endl;
    cout<<endl;
    gotoxy (25,5);
    cout<<"-----------------------------";
    cout<<endl;
    cout<<endl;
}

/// INGRESO DE DINERO
void Menu::ingresoDinero(Pais &regPais)
{

    ArchivoPais archPais;
    long long saldoNuevo = 0;
    Pais registroPais;
    int posicion;

    posicion = archPais.buscarXId(regPais.getId());
    registroPais = archPais.leer(posicion);

    gotoxy (25,1);
    cout<<"-----------------------------";
    cout<<endl;
    gotoxy (28,3);
    cout<<"SALDO: U$D " << registroPais.getDineroCaja() <<endl;
    cout<<endl;
    gotoxy (25,5);
    cout<<"-----------------------------";

    gotoxy (20,8);
    cout<<"MONTO QUE DESEA INGRESAR A SU CUENTA: U$D ";
    cin>> saldoNuevo;
    saldoNuevo += registroPais.getDineroCaja();

    registroPais.setDineroCaja(saldoNuevo);

    gotoxy (28,10);
    cout<<"SALDO ACTUAL: U$D "  << registroPais.getDineroCaja() <<endl;
    cout<<endl;

    cout<<endl;

    archPais.guardar(registroPais,posicion);
}

/// SOLICITUD DE ADQUISICIONES
void Menu::solicitudDeAdquisiciones(Pais &regPais)
{
    long long dineroAcumulado = 0;
    int cantProductosComprados = 0;
    Validar validar;
    int cantProductosAComprar;
    int tamanioMisil;
    int tamanioAvion;
    int tamanioBuque;
    ArchivoMisil archMisil;
    Misil misil;
    ArchivoAvion archAvion;
    Avion avion;
    ArchivoBuque archBuque;
    Buque buque;
    ArchivoTanque archTanque;
    Tanque tanque;
    StockProducto *vecProductosMisil = nullptr;//OJO!!! DINAMICO inicializar/verificar/delete corchetes? XQ NOC CUANTOS REGISTROS PUEDEN LLEGAR A SER
    StockProducto *vecProductosAvion = nullptr;
    StockProducto *vecProductosBuque = nullptr;
    StockProducto *vecProductosTanque = nullptr;
    DetalleVenta *vecDetalleVenta = nullptr;

    cls();
    cabecera();

    gotoxy (22,6);
    cout << "CUANTOS PRODUCTOS VA A COMPRAR: ";
    cin>>cantProductosAComprar;
    cout<<endl;

    while(cantProductosAComprar <= 0)
    {
        cout << "\tCantidad ingresada incorrecta, re ingrese..." << endl;
        cout << endl << "\tCUANTOS PRODUCTOS VA A COMPRAR: ";
        cin>>cantProductosAComprar;
    }

    // HACE UN VECTOR DE (TABLA INTERMEDIA STOCK PRODUCTO) PARA CADA PRODUCTO. GUARDANDO
    // EN CADA POS DEL VECTOR EL ID Y STOCK DE CADA TIPO DE PRODUCTO.

    tamanioMisil = archMisil.getCantidadReg();
    vecProductosMisil = new StockProducto[tamanioMisil];

    //verifico memoria
    if(vecProductosMisil == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        system("pause");
        return;
    }

    for (int i = 0; i < tamanioMisil; i++)
    {
        misil = archMisil.leer(i);
        vecProductosMisil[i].setId(misil.getId());
        vecProductosMisil[i].setStock(misil.getStock());
    }

    /// creacion tabla intermedia para luego utilizarla para verificar stock

    tamanioAvion = archAvion.getCantidadReg();
    vecProductosAvion = new StockProducto[tamanioAvion];

    //verifico memoria
    if(vecProductosAvion == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        system("pause");
        return;
    }

    for (int i = 0; i < tamanioAvion; i++)
    {
        avion = archAvion.leer(i);
        vecProductosAvion[i].setId(avion.getId());
        vecProductosAvion[i].setStock(avion.getStock());
    }

    /// creacion tabla intermedia para luego utilizarla para verificar stock

    tamanioBuque = archBuque.getCantidadReg();
    vecProductosBuque = new StockProducto[tamanioBuque];

    //verifico memoria
    if(vecProductosBuque == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        system("pause");
        return;
    }

    for (int i = 0; i < tamanioBuque; i++)
    {
        buque = archBuque.leer(i);
        vecProductosBuque[i].setId(buque.getId());
        vecProductosBuque[i].setStock(buque.getStock());
    }

    /// creacion tabla intermedia para luego utilizarla para verificar stock

    int tamanioTanque = archTanque.getCantidadReg();
    vecProductosTanque = new StockProducto[tamanioTanque];

    //verifico memoria
    if(vecProductosTanque == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        system("pause");
        return;
    }

    for (int i = 0; i < tamanioTanque; i++)
    {
        tanque = archTanque.leer(i);
        vecProductosTanque[i].setId(tanque.getId());
        vecProductosTanque[i].setStock(tanque.getStock());
    }

    /// DEPENDIENDO DE CUANTOS QUERES COMPRAR ES LA CANTIDAD DE VUELTAS QUE PEGA EL FOR

    vecDetalleVenta = new DetalleVenta[cantProductosAComprar];

    //verifico memoria
    if(vecDetalleVenta == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        system("pause");
        return;
    }

    int posDetalleVenta;

    for(int i = 0; i < cantProductosAComprar; i++)
    {

        posDetalleVenta = i;
        cls();
        cabecera();
        gotoxy (25,6);
        cout << "SELECCIONE SU ARMAMENTO";
        gotoxy (25,8);
        cout << "1 - MISILES";
        gotoxy (25,10);
        cout << "2 - AVIONES";
        gotoxy (25,12);
        cout << "3 - BUQUES";
        gotoxy (25,14);
        cout << "4 - TANQUES";
        gotoxy (25,16);
        cout << "0 - CANCELAR";
        gotoxy (25,18);
        cout << "INGRESE UNA OPCION: ";
        cin >> opcion;

        switch(opcion)
        {

        case 1:
            system("cls");

            //Depende de qu� vuelta est� de la compra directamente le pasa uno dentro del vector.
            //Ese unico objeto de tipo Detalle de Venta se lo pasa como refe para poder actualizarlo dentro del vector.
            comprarMisil(regPais, cantProductosComprados, vecDetalleVenta, dineroAcumulado, vecProductosMisil, tamanioMisil, posDetalleVenta);
            system("pause");
            break;

        case 2:
            system("cls");
            comprarAvion (regPais, cantProductosComprados,vecDetalleVenta, dineroAcumulado, vecProductosAvion, tamanioAvion, posDetalleVenta);
            system("pause");
            break;

        case 3:
            system("cls");
            comprarBuque (regPais, cantProductosComprados, vecDetalleVenta, dineroAcumulado, vecProductosBuque, tamanioBuque, posDetalleVenta);
            system("pause");
            break;

        case 4:
            system("cls");
            comprarTanque (regPais,cantProductosComprados, vecDetalleVenta, dineroAcumulado, vecProductosTanque, tamanioTanque, posDetalleVenta);
            system("pause");
            break;

        case 0:
            delete[] vecDetalleVenta;
            delete[] vecProductosMisil;
            delete[] vecProductosAvion;
            delete[] vecProductosBuque;
            delete[] vecProductosTanque;
            break;

        default:
            gotoxy (2,21);
            cout << "LA OPCION INGRESADA NO ES VALIDA" << endl;
            gotoxy (2,22);
            system("pause");
            break;
        }
    }

//CANTPRODUCTOS COMPRADOS TIENE LA CANTIDAD DE COMPRAS QUE SI SE REALIZARON, CONSULTAMOS QUE AL MENOS UN DETALLE DE VENTA SE HAYA PODIDO EFECTUAR.
    if (cantProductosComprados > 0)
    {

        cls();
        cabecera();

        gotoxy(10,8);
        cout << "CONFIRMAR COMPRA?" << endl;
        gotoxy(10,9);
        cout << "1- SI" << endl;
        gotoxy(10,10);
        cout << "2- NO" << endl;
        gotoxy(10,11);
        cout << "OPCION: ";
        cin >> opcion;

        while(!validar.esRangoValido(1, 2, opcion))
        {
            cout << "Opcion incorrecta, seleccione nuevamente..." << endl;
            cout << "OPCION: ";
            cin >> opcion;
        }

        switch(opcion)
        {
        case 1:
            confirmarCompra(regPais, dineroAcumulado, vecDetalleVenta,cantProductosAComprar, cantProductosComprados, vecProductosMisil, vecProductosAvion, vecProductosBuque, vecProductosTanque);
            delete[] vecDetalleVenta;
            delete[] vecProductosMisil;
            delete[] vecProductosAvion;
            delete[] vecProductosBuque;
            delete[] vecProductosTanque;
            break;
        case 2:
            gotoxy(10,14);
            cout<<"COMPRA CANCELADA"<<endl;
            //system ("pause");
            delete[] vecDetalleVenta;
            delete[] vecProductosMisil;
            delete[] vecProductosAvion;
            delete[] vecProductosBuque;
            delete[] vecProductosTanque;
            break;
        }

    }
    else
    {
        cout<<"COMPRA CANCELADA"<<endl;
    }
}


///COMPRAR MISIL

void Menu::comprarMisil(Pais &regPais, int &cantProductosComprados, DetalleVenta *vecDetalleVenta, long long &dineroAcumulado, StockProducto *vecProductosMisil, int tamanioMisil, int posDetalleVenta)
{
    Misil regMisil;
    ArchivoMisil archMisil;
    Pais registroPais;
    ArchivoPais archPais;
    int posPais;
    string respuesta;
    cin.ignore(); //sino se saltea el listar misiles
    int id;
    int posMisil;
    int cantidad;
    long long totalItem =0;
    bool dinero = false;
    bool stock=false;

    cout << "LISTAR MISILES? (s / n): ";
    getline(cin, respuesta);

    if (respuesta == "s" || respuesta == "S")
    {
        mostrarMisiles(false);
    }

    cout << "INGRESE EL ID DEL MISIL QUE DESEA COMPRAR: ";
    cin>> id;

    cin.ignore();

    system("cls");


    posMisil = archMisil.buscarXId(id);

    if(posMisil != -1) // SI encontro el Misil
    {

        regMisil = archMisil.leer(posMisil);
        posPais = archPais.buscarXId(regPais.getId());
        registroPais = archPais.leer(posPais);


        if (regMisil.getEstado()== true)
        {
            regMisil.mostrar();

            cout << endl;
            cout << "ESTA SEGURO QUE DESEA AGREGAR ESTE MISIL? (s / n): ";
            getline(cin, respuesta);

            if (respuesta == "s" || respuesta == "S")
            {
                cout << endl;
                cout << "ING LA CANTIDAD QUE DESEA: ";
                cin >>cantidad;

                for(int j=0; j<tamanioMisil; j++) //Recorre tabla intermedia
                {

                    if(vecProductosMisil[j].getId() == id)  // Recorre la tabla intermedia buscando ID ingresado de MISIL
                    {
                        totalItem = cantidad * regMisil.getPrecio();
                        //Tenes que tener stock mayor a 0 y adem�s tenes que tener stock suficiente para la cantidad que queres comprar.
                        if ((vecProductosMisil[j].getStock() >= cantidad) && (vecProductosMisil[j].getStock()>0))
                        {
                            stock=true;
                        }
                        else
                        {
                            cout << endl << "NO HAY SUFICIENTE STOCK DEL MISIL " << endl;
                            vecDetalleVenta[posDetalleVenta] = DetalleVenta();
                            stock=false;
                        }

                        if(registroPais.getDineroCaja()- (dineroAcumulado + totalItem) >= 0)
                        {

                            dinero=true;
                        }
                        else
                        {
                            cout << endl << "SALDO INSUFICIENTE PARA REALIZAR LA COMPRA " << endl;
                            vecDetalleVenta[posDetalleVenta] = DetalleVenta();
                            dinero=false;
                        }


                        if (dinero ==true && stock == true)
                        {
                            cantProductosComprados ++;
                            dineroAcumulado += totalItem;
                            vecProductosMisil[j].setStock(vecProductosMisil[j].getStock() - cantidad);
                            vecDetalleVenta[posDetalleVenta].setIdProducto(regMisil.getId());
                            vecDetalleVenta[posDetalleVenta].setCantidad(cantidad);
                            vecDetalleVenta[posDetalleVenta].setNombreProducto(regMisil.getNombre());
                            vecDetalleVenta[posDetalleVenta].setPrecioUnitario(regMisil.getPrecio());
                            vecDetalleVenta[posDetalleVenta].setPrecioTotal(totalItem);
                            cout << "SE AGREGO EL PRODUCTO A LA COMPRA"<< endl;
                            //cout << "DINERO ACUMULADO*" << dineroAcumulado << endl;
                        }


                        break;

                    }

                }
            }
            else
            {
                cout << endl << "EL MISIL NO SE AGREGO A SU COMPRA" << endl;
                vecDetalleVenta[posDetalleVenta] = DetalleVenta();

            }

        }
        else
        {
            cout << "EL MISIL NO SE ENCUENTRA EN EL SISTEMA"<< endl;
            vecDetalleVenta[posDetalleVenta] = DetalleVenta();
        }

    }
    else
    {
        cout << "EL MISIL NO SE ENCUENTRA EN EL SISTEMA"<< endl;
        vecDetalleVenta[posDetalleVenta] = DetalleVenta();
    }

}

///COMPRAR AVION

void Menu::comprarAvion(Pais &regPais, int &cantProductosComprados, DetalleVenta *vecDetalleVenta, long long &dineroAcumulado, StockProducto *vecProductosAvion, int tamanioAvion, int posDetalleVenta)
{
    Avion regAvion;
    ArchivoAvion archAvion;
    Pais registroPais;
    ArchivoPais archPais;
    int posPais;
    string respuesta;
    cin.ignore(); //sino se saltea el listar misiles
    int id;
    int posAvion;
    int cantidad;
    long long totalItem = 0;
    bool dinero = false;
    bool stock=false;

    cout << "LISTAR AVIONES? (s / n): ";
    getline(cin, respuesta);

    if (respuesta == "s" || respuesta == "S")
    {
        mostrarAviones(false);
    }

    cout << "INGRESE EL ID DEL AVION QUE DESEA COMPRAR: ";
    cin>> id;

    cin.ignore();

    system("cls");


    posAvion = archAvion.buscarXId(id);

    if(posAvion != -1) // SI encontro el Avion
    {

        regAvion = archAvion.leer(posAvion);
        posPais = archPais.buscarXId(regPais.getId());
        registroPais = archPais.leer(posPais);


        if (regAvion.getEstado()== true)
        {
            regAvion.mostrar();

            cout << endl;
            cout << "ESTA SEGURO QUE DESEA AGREGAR ESTE AVION? (s / n): ";
            getline(cin, respuesta);

            if (respuesta == "s" || respuesta == "S")
            {
                cout << endl;
                cout << "ING LA CANTIDAD QUE DESEA: ";
                cin >>cantidad;

                for(int j=0; j<tamanioAvion; j++) //Recorre tabla intermedia
                {

                    if(vecProductosAvion[j].getId() == id)  // Recorre la tabla intermedia buscando ID ingresado de MISIL
                    {
                        totalItem = cantidad * regAvion.getPrecio();
                        //Tenes que tener stock mayor a 0 y adem�s tenes que tener stock suficiente para la cantidad que queres comprar.
                        if ((vecProductosAvion[j].getStock() >= cantidad) && (vecProductosAvion[j].getStock()>0))
                        {
                            stock=true;
                        }
                        else
                        {
                            cout << endl << "NO HAY SUFICIENTE STOCK DEL AVION " << endl;
                            vecDetalleVenta[posDetalleVenta] = DetalleVenta();
                            stock=false;
                        }

                        if(registroPais.getDineroCaja()- (dineroAcumulado + totalItem) >= 0)
                        {

                            dinero=true;
                        }
                        else
                        {
                            cout << endl << "SALDO INSUFICIENTE PARA REALIZAR LA COMPRA " << endl;
                            vecDetalleVenta[posDetalleVenta] = DetalleVenta();
                            dinero=false;
                        }


                        if (dinero ==true && stock == true)
                        {
                            cantProductosComprados ++;
                            dineroAcumulado += totalItem;
                            vecProductosAvion[j].setStock(vecProductosAvion[j].getStock() - cantidad);
                            vecDetalleVenta[posDetalleVenta].setIdProducto(regAvion.getId());
                            vecDetalleVenta[posDetalleVenta].setCantidad(cantidad);
                            vecDetalleVenta[posDetalleVenta].setNombreProducto(regAvion.getNombre());
                            vecDetalleVenta[posDetalleVenta].setPrecioUnitario(regAvion.getPrecio());
                            vecDetalleVenta[posDetalleVenta].setPrecioTotal(totalItem);
                            cout << "SE AGREGO EL PRODUCTO A LA COMPRA"<< endl;
                            //cout << "DINERO ACUMULADO*" << dineroAcumulado << endl;
                        }


                        break;

                    }

                }
            }
            else
            {
                cout << endl << "EL AVION NO SE AGREGO A SU COMPRA" << endl;
                vecDetalleVenta[posDetalleVenta] = DetalleVenta();

            }

        }
        else
        {
            cout << "EL AVION NO SE ENCUENTRA EN EL SISTEMA"<< endl;
            vecDetalleVenta[posDetalleVenta] = DetalleVenta();
        }

    }
    else
    {
        cout << "EL AVION NO SE ENCUENTRA EN EL SISTEMA"<< endl;
        vecDetalleVenta[posDetalleVenta] = DetalleVenta();
    }

}

///COMPRAR BUQUE

void Menu::comprarBuque(Pais &regPais, int &cantProductosComprados, DetalleVenta *vecDetalleVenta, long long &dineroAcumulado, StockProducto *vecProductosBuque, int tamanioBuque, int posDetalleVenta)
{
    Buque regBuque;
    ArchivoBuque archBuque;
    Pais registroPais;
    ArchivoPais archPais;
    int posPais;
    string respuesta;
    cin.ignore(); //sino se saltea el listar misiles
    int id;
    int posBuque;
    int cantidad;
    long long totalItem = 0;
    bool dinero = false;
    bool stock=false;

    cout << "LISTAR BUQUE? (s / n): ";
    getline(cin, respuesta);

    if (respuesta == "s" || respuesta == "S")
    {
        mostrarBuques(false);
    }

    cout << "INGRESE EL ID DEL BUQUE QUE DESEA COMPRAR: ";
    cin>> id;

    cin.ignore();

    system("cls");


    posBuque = archBuque.buscarXId(id);

    if(posBuque != -1) // SI encontro el Avion
    {

        regBuque = archBuque.leer(posBuque);
        posPais = archPais.buscarXId(regPais.getId());
        registroPais = archPais.leer(posPais);


        if (regBuque.getEstado()== true)
        {
            regBuque.mostrar();

            cout << endl;
            cout << "ESTA SEGURO QUE DESEA AGREGAR ESTE BUQUE? (s / n): ";
            getline(cin, respuesta);

            if (respuesta == "s" || respuesta == "S")
            {
                cout << endl;
                cout << "ING LA CANTIDAD QUE DESEA: ";
                cin >>cantidad;

                for(int j=0; j<tamanioBuque; j++) //Recorre tabla intermedia
                {

                    if(vecProductosBuque[j].getId() == id)  // Recorre la tabla intermedia buscando ID ingresado de MISIL
                    {
                        totalItem = cantidad * regBuque.getPrecio();
                        //Tenes que tener stock mayor a 0 y adem�s tenes que tener stock suficiente para la cantidad que queres comprar.
                        if ((vecProductosBuque[j].getStock() >= cantidad) && (vecProductosBuque[j].getStock()>0))
                        {
                            stock=true;
                        }
                        else
                        {
                            cout << endl << "NO HAY SUFICIENTE STOCK DEL BUQUE " << endl;
                            vecDetalleVenta[posDetalleVenta] = DetalleVenta();
                            stock=false;
                        }

                        if(registroPais.getDineroCaja()- (dineroAcumulado + totalItem) >= 0)
                        {

                            dinero=true;
                        }
                        else
                        {
                            cout << endl << "SALDO INSUFICIENTE PARA REALIZAR LA COMPRA " << endl;
                            vecDetalleVenta[posDetalleVenta] = DetalleVenta();
                            dinero=false;
                        }


                        if (dinero ==true && stock == true)
                        {
                            cantProductosComprados ++;
                            dineroAcumulado += totalItem;
                            vecProductosBuque[j].setStock(vecProductosBuque[j].getStock() - cantidad);
                            vecDetalleVenta[posDetalleVenta].setIdProducto(regBuque.getId());
                            vecDetalleVenta[posDetalleVenta].setCantidad(cantidad);
                            vecDetalleVenta[posDetalleVenta].setNombreProducto(regBuque.getNombre());
                            vecDetalleVenta[posDetalleVenta].setPrecioUnitario(regBuque.getPrecio());
                            vecDetalleVenta[posDetalleVenta].setPrecioTotal(totalItem);
                            cout << "SE AGREGO EL PRODUCTO A LA COMPRA"<< endl;
                            //cout << "DINERO ACUMULADO*" << dineroAcumulado << endl;
                        }


                        break;

                    }

                }
            }
            else
            {
                cout << endl << "EL BUQUE NO SE AGREGO A SU COMPRA" << endl;
                vecDetalleVenta[posDetalleVenta] = DetalleVenta();

            }

        }
        else
        {
            cout << "EL BUQUE NO SE ENCUENTRA EN EL SISTEMA"<< endl;
            vecDetalleVenta[posDetalleVenta] = DetalleVenta();
        }

    }
    else
    {
        cout << "EL BUQUE NO SE ENCUENTRA EN EL SISTEMA"<< endl;
        vecDetalleVenta[posDetalleVenta] = DetalleVenta();
    }

}

///COMPRAR TANQUE

void Menu::comprarTanque(Pais &regPais, int &cantProductosComprados, DetalleVenta *vecDetalleVenta, long long &dineroAcumulado, StockProducto *vecProductosTanque, int tamanioTanque, int posDetalleVenta)
{
    Tanque regTanque;
    ArchivoTanque archTanque;
    Pais registroPais;
    ArchivoPais archPais;
    int posPais;
    string respuesta;
    cin.ignore(); //sino se saltea el listar misiles
    int id;
    int posTanque;
    int cantidad;
    long long totalItem = 0;
    bool dinero = false;
    bool stock=false;

    cout << "LISTAR TANQUES? (s / n): ";
    getline(cin, respuesta);

    if (respuesta == "s" || respuesta == "S")
    {
        mostrarTanques(false);
    }

    cout << "INGRESE EL ID DEL TANQUE QUE DESEA COMPRAR: ";
    cin>> id;

    cin.ignore();

    system("cls");


    posTanque = archTanque.buscarXId(id);

    if(posTanque != -1) // SI encontro el Avion
    {

        regTanque = archTanque.leer(posTanque);
        posPais = archPais.buscarXId(regPais.getId());
        registroPais = archPais.leer(posPais);


        if (regTanque.getEstado()== true)
        {
            regTanque.mostrar();

            cout << endl;
            cout << "ESTA SEGURO QUE DESEA AGREGAR ESTE TANQUE? (s / n): ";
            getline(cin, respuesta);

            if (respuesta == "s" || respuesta == "S")
            {
                cout << endl;
                cout << "ING LA CANTIDAD QUE DESEA: ";
                cin >>cantidad;

                for(int j=0; j<tamanioTanque; j++) //Recorre tabla intermedia
                {

                    if(vecProductosTanque[j].getId() == id)  // Recorre la tabla intermedia buscando ID ingresado de MISIL
                    {
                        totalItem = cantidad * regTanque.getPrecio();
                        //Tenes que tener stock mayor a 0 y adem�s tenes que tener stock suficiente para la cantidad que queres comprar.
                        if ((vecProductosTanque[j].getStock() >= cantidad) && (vecProductosTanque[j].getStock()>0))
                        {
                            stock=true;
                        }
                        else
                        {
                            cout << endl << "NO HAY SUFICIENTE STOCK DEL TANQUE " << endl;
                            vecDetalleVenta[posDetalleVenta] = DetalleVenta();
                            stock=false;
                        }

                        if(registroPais.getDineroCaja()- (dineroAcumulado + totalItem) >= 0)
                        {

                            dinero=true;
                        }
                        else
                        {
                            cout << endl << "SALDO INSUFICIENTE PARA REALIZAR LA COMPRA " << endl;
                            vecDetalleVenta[posDetalleVenta] = DetalleVenta();
                            dinero=false;
                        }


                        if (dinero ==true && stock == true)
                        {
                            cantProductosComprados ++;
                            dineroAcumulado += totalItem;
                            vecProductosTanque[j].setStock(vecProductosTanque[j].getStock() - cantidad);
                            vecDetalleVenta[posDetalleVenta].setIdProducto(regTanque.getId());
                            vecDetalleVenta[posDetalleVenta].setCantidad(cantidad);
                            vecDetalleVenta[posDetalleVenta].setNombreProducto(regTanque.getNombre());
                            vecDetalleVenta[posDetalleVenta].setPrecioUnitario(regTanque.getPrecio());
                            vecDetalleVenta[posDetalleVenta].setPrecioTotal(totalItem);
                            cout << "SE AGREGO EL PRODUCTO A LA COMPRA"<< endl;
                            //cout << "DINERO ACUMULADO*" << dineroAcumulado << endl;
                        }


                        break;

                    }

                }
            }
            else
            {
                cout << endl << "EL TANQUE NO SE AGREGO A SU COMPRA" << endl;
                vecDetalleVenta[posDetalleVenta] = DetalleVenta();

            }

        }
        else
        {
            cout << "EL TANQUE NO SE ENCUENTRA EN EL SISTEMA"<< endl;
            vecDetalleVenta[posDetalleVenta] = DetalleVenta();
        }

    }
    else
    {
        cout << "EL TANQUE NO SE ENCUENTRA EN EL SISTEMA"<< endl;
        vecDetalleVenta[posDetalleVenta] = DetalleVenta();
    }

}

/// CONFIRMAR COMPRA
void Menu::confirmarCompra(Pais &regPais, long long dineroAcumulado, DetalleVenta *vecDetalleVenta, int cantProductosAComprar, int cantProductosComprados, StockProducto *vecProductosMisil, StockProducto *vecProductosAvion, StockProducto *vecProductosBuque, StockProducto *vecProductosTanque)
{
    int id;
    int cantReg;
    int posReg;
    Pais registroPais;
    Fecha fecha;
    Venta regVenta;
    ArchivoVenta archivoVenta;
    ArchivoDetalleVenta archivoDetalle;
    ArchivoPais archivoPais;
    Misil regMisil;
    ArchivoMisil archivoMisil;
    Avion regAvion;
    ArchivoAvion archivoAvion;
    Buque regBuque;
    ArchivoBuque archivoBuque;
    Tanque regTanque;
    ArchivoTanque archivoTanque;

    if (cantProductosComprados >0)
    {

        id = archivoVenta.getNuevoId();//obtiene nuevo ID autonumerico.

        ///setear regVenta
        regVenta.setId(id);
        regVenta.setIdCliente(regPais.getId());
        regVenta.setFecha(fecha);
        regVenta.setCantidadItems(cantProductosComprados);
        regVenta.setMontoTotal(dineroAcumulado);


        if(archivoVenta.guardar(regVenta))
        {


            /// setear el Id de la Venta en el vector DetalleVentas
            for (int i = 0; i < cantProductosAComprar; ++i)
            {
                //ACA LE ASIGNAMOS AL DETALLE DE VENTA EL ID DE VENTA
                vecDetalleVenta[i].setIdVenta(regVenta.getId());
            }

            ///CON LA FUNCION GRABAR REGISTROS LE PASA EL VECTOR DE DETALLE DE VENTA Y LA CANTIDAD DE PRODUCTOS QUE QUIZO COMPRAR
            ///Y LO GUARDA EN EL ARCHIVO.



            if(archivoDetalle.grabarRegistros(vecDetalleVenta, cantProductosAComprar))
            {

                cantReg = archivoMisil.getCantidadReg();

                for(int i=0; i<cantReg; i++)
                {
                    posReg = archivoMisil.buscarXId(vecProductosMisil[i].getId());
                    regMisil = archivoMisil.leer(posReg);
                    regMisil.setStock(vecProductosMisil[i].getStock());
                    archivoMisil.guardar(regMisil, posReg);
                }

                cantReg = archivoAvion.getCantidadReg();

                for(int i=0; i<cantReg; i++)
                {
                    posReg = archivoAvion.buscarXId(vecProductosAvion[i].getId());
                    regAvion = archivoAvion.leer(posReg);
                    regAvion.setStock(vecProductosAvion[i].getStock());
                    archivoAvion.guardar(regAvion, posReg);
                }

                cantReg = archivoBuque.getCantidadReg();

                for(int i=0; i<cantReg; i++)
                {
                    posReg = archivoBuque.buscarXId(vecProductosBuque[i].getId());
                    regBuque = archivoBuque.leer(posReg);
                    regBuque.setStock(vecProductosBuque[i].getStock());
                    archivoBuque.guardar(regBuque, posReg);
                }

                cantReg = archivoTanque.getCantidadReg();

                for(int i=0; i<cantReg; i++)
                {
                    posReg = archivoTanque.buscarXId(vecProductosTanque[i].getId());
                    regTanque = archivoTanque.leer(posReg);
                    regTanque.setStock(vecProductosTanque[i].getStock());
                    archivoTanque.guardar(regTanque, posReg);
                }

                ///modificacion de dinero en caja del pais
                posReg = archivoPais.buscarXId(regPais.getId());
                registroPais = archivoPais.leer(posReg);

                registroPais.setDineroCaja(registroPais.getDineroCaja() - dineroAcumulado);
                archivoPais.guardar(registroPais,posReg);

                cls();
                cabecera();
                gotoxy(10,8);
                cout << "SE HA GUARDADO SU COMPRA SATISFACTORIAMENTE."<<endl<<endl;


            }
            else
            {
                cls();
                cabecera();
                gotoxy(10,8);
                cout << "LO SENTIMOS, NO HEMOS PODIDO CONFIRMAR SU COMPRA.";
            }

        }
        else
        {
            cls();
            cabecera();
            gotoxy(10,8);
            cout << "LO SENTIMOS, NO HEMOS PODIDO CONFIRMAR SU COMPRA.";
        }
    }
// Ac� llega si la venta NO TIENE DETALLES DE VENTAS COMPRADOS;

}

/// COMPRAS REALIZADAS
void Menu::comprasRealizadas(Pais &regPais)
{
    ArchivoVenta archivoVenta;
    int cantRegVenta;
    Venta *vecRegVenta = nullptr;
    int cantRegDetalle;
    ArchivoDetalleVenta archivoDetalle;
    DetalleVenta *vecDetalleVenta = nullptr;
    //int item=0;

    cantRegVenta = archivoVenta.getCantidadReg();
    vecRegVenta = new Venta[cantRegVenta];

    if (vecRegVenta == nullptr)
    {
        return;
    }

    cantRegDetalle = archivoDetalle.getCantidadReg();
    vecDetalleVenta = new DetalleVenta [cantRegDetalle];

    if (vecDetalleVenta == nullptr)
    {
        return;
    }


    cout<< "<< COMPRAS REALIZADAS >> CLIENTE : " <<regPais.getUsuario()<<endl;

    archivoVenta.leerTodos(vecRegVenta, cantRegVenta);
    archivoDetalle.leerTodos(vecDetalleVenta, cantRegDetalle);

    for (int i=0; i<cantRegVenta; i++)
    {
        //item =0;

        if (regPais.getId()== vecRegVenta[i].getIdCliente())
        {
            vecRegVenta[i].mostrar();


            for (int j=0; j<cantRegDetalle; j++)
            {

                if(vecRegVenta[i].getId() == vecDetalleVenta[j].getIdVenta())
                {
                    if(vecDetalleVenta[j].getIdProducto()!=-1)
                    {
                        //item++;
                        //cout << "----------------------" <<endl;
                        //cout<<"NUMERO ITEM: "<< item<<endl;
                        vecDetalleVenta[j].mostrar();
                    }
                }
            }
        }
    }

    delete[] vecRegVenta;
    delete [] vecDetalleVenta;
}




