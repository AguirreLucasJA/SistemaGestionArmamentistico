#pragma once
#include"Pais.h"
#include"Admin.h"
#include"Misil.h"
#include"Avion.h"
#include"Buque.h"


class Menu
{
public:
    Menu() {};
    void dibujarCuadro(int x1, int y1, int x2, int y2);
    void gotoxy(int x, int y);
    void cabecera();

    bool menuOpcion();// MENU INGRESO USERS/ADMINS

    void menuPrincipalAdmin();// MENU PRINCIPAL ADMIN

    void menuAdmin();//SUBMENU ADMIN DENTRO DE MENU PRINCIPAL ADMIN
    void altaAdmin();//ABM ADMIN
    void modificarAdmin();//ABM ADMIN
    void eliminarAdmin();//ABM ADMIN

    //MOSTRAR
    void mostrarAdmins(bool ordenadoPorEstado, bool mostrarEliminados = false);//SE USA EN "BAJA", "MODIFICACION" DE ADMIN Y LISTADOS
    void mostrarPaises(bool ordenadoPorEstado, bool mostrarEliminados = false);//SE USA EN "BAJA", "MODIFICACION" DE PAIS Y LISTADOS
    void mostrarMisiles(bool ordenadoPorEstado, bool mostrarEliminados = false);
    void mostrarAviones(bool ordenadoPorEstado, bool mostrarEliminados = false);
    void mostrarBuques(bool ordenadoPorEstado, bool mostrarEliminados = false);

    void menuPaises();//SUBMENU PAIS DENTRO DE MENU PRINCIPAL ADMIN
    void altaPais();//ABM PAIS
    void modificarPais();//ABM PAIS
    void eliminarPais();//ABM PAIS

    void menuStock();//SUBMENU STOCK DENTRO DEL MENU PRINCIPAL ADMIN STOCK

    void subMenuStockMisiles();//SUBMENU ABM MISIL
    void altaMisil();//ABM MISIL
    void modificarMisil();//ABM MISIL
    void eliminarMisil();//ABM MISIL
    void agregarStockMisil();

    void subMenuStockAviones();//SUBMENU ABM AVION
    void altaAvion();//ABM AVION
    void modificarAvion();//ABM AVION
    void eliminarAvion();//ABM AVION
    void agregarStockAvion();

    void subMenuStockBuques();
    void altaBuque();//ABM BUQUE
    void modificarBuque();//ABM BUQUE
    void eliminarBuque();//ABM BUQUE
    void agregarStockBuque();


    void subMenuStockTanques();

    void menuListados();//SUBMENU LISTADOS DENTRO DEL MENU PRINCIPAL ADMIN STOCK
    void listarAdmins();
    void listarPaises();
    void listarMisiles();

    void ordenarPorEstado(Admin *vecAdmin, int cantidad);//ACTIVOS PRIMERO
    void ordenarPorEstado(Pais *vecPais, int cantidad);//ACTIVOS PRIMERO
    void ordenarPorEstado(Misil *vecMisil, int cantidad);//ACTIVOS PRIMERO
    void ordenarPorEstado(Avion *vecAvion, int cantidad);//ACTIVOS PRIMERO
    void ordenarPorEstado(Buque *vecBuque, int cantidad);//ACTIVOS PRIMERO

    void menuReportes();//SUBMENU REPORTES DENTRO DEL MENU PRINCIPAL ADMIN STOCK
///-------------------------------------------------------------------------------//
    void menuPrincipalPais(Pais regPais);//MENU PRINCIPAL PAIS CLIENTE

private:
    int opcion;
};
