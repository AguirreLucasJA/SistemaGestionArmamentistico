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
#include"NombreUsuario.h"
#include "Misil.h"

#include "ClasesArchivos/ArchivoAdmin.h"
#include "ClasesArchivos/ArchivoPais.h"
#include"ClasesArchivos/ArchivoNombreUsuario.h"
#include "ClasesArchivos/ArchivoMisil.h"

/// INTERFAZ ICARGABLE
void Menu::cargarObjeto(ICargable &obj)
{
    obj.cargar();
}

/// INTERFAZ IMOSTRABLE
void Menu::mostrarObjeto(IMostrable &obj)
{
    obj.mostrar();
}

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

    bool ingresoAdmin = false;
    //TODO: FALTA HACER SI HAY 2 USUARIOS CON EL MISMO NOMBRE SE QUEDA CON EL PRIMERO Y NO SIGUE FIJANDOSE EN EL RESTO DEL ARCHIVO

    regAdmin = archivoAdmin.leer(archivoAdmin.buscarXUsuario(usuario));
    if (regAdmin.getUsuario() == usuario && regAdmin.getClave() == clave && regAdmin.getEstado())
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
        regPais = archivoPais.leer(archivoPais.buscarXUsuario(usuario));
    }
    if (regPais.getUsuario() == usuario && regPais.getClave() == clave && regPais.getEstado())
    {
        menuPrincipalPais(regPais);
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

    //int id;
    Admin regAdmin;
    ArchivoAdmin ArchAdmin;
    NombreUsuario regNombreUsuario;
    ArchivoNombreUsuario ArchNombreUsuario;

    //id = ArchAdmin.getNuevoId(); //obtiene nuevo ID autonumerico.
    cargarObjeto(regAdmin);
    //regAdmin.cargar(id);//carga un nuevo regAdmin admin setenadole el ID obtenido
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
            //altaPais();
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
/*
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
*/
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
    Misil reg;
    ArchivoMisil ArchMisil;
    //devuelve la cantidad -1 de los reg del archivo
    id = ArchMisil.getNuevoId(); //obtiene nuevo ID autonumerico.
    reg.cargar(id);//carga un nuevo reg Misil setenadole el ID obtenido
    if(ArchMisil.guardar(reg)) //lo cargan en archivo Misil
    {
        cout << "ALTA EXITOSA..." << endl;
    }
    else
    {
        cout << "NO SE HA PODIDO GRABAR EL REGISTRO.";
    }
}

/// MOSTRAR MISILES
void Menu::mostrarMisiles(bool ordenadoPorEstado, bool mostrarEliminados) //TODO::FALTA HACER LA PARTE DE ORDENADO
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

/// AGREGAR STOCK
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

    pos = ArchMisil.buscarXId(Id);

    if(pos != -1)//si encontro el archivo
    {
        reg = ArchMisil.leer(pos);

        if(reg.getEstado())//SI no esta eliminado
        {
            reg.mostrar();

            cout << "DESEA AGREGAR STOCK? (s / n): ";
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
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 2:
            system("cls");
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 3:
            system("cls");
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 4:
            system("cls");
            //TODO:FALTA HACER**
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
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 2:
            system("cls");
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 3:
            system("cls");
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 4:
            system("cls");
            //TODO:FALTA HACER**
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
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 2:
            system("cls");
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 3:
            system("cls");
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 4:
            system("cls");
            //TODO:FALTA HACER**
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
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 5:
            system("cls");
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 6:
            system("cls");
            //TODO:FALTA HACER**
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

///ORDENAR USUARIOS POR ESTADO SOBRECARGA
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
        cout<<"2 - BUSCAR FACTURAS";
        gotoxy (2,11);
        cout<<"3 - RANKING DE CLIENTES";
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
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 2:
            system("cls");
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 3:
            system("cls");
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 4:
            system("cls");
            //TODO:FALTA HACER**
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

/// MENU PRINCIPAL PAIS
void Menu::menuPrincipalPais(Pais regPais)
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
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 2:
            system("cls");
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 3:
            system("cls");
            //TODO:FALTA HACER**
            system("pause");
            break;

        case 4:
            system("cls");
            //TODO:FALTA HACER**
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





