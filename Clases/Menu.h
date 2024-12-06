#pragma once
#include"Pais.h"
#include"Admin.h"
#include"Misil.h"
#include"Avion.h"
#include"Buque.h"
#include"Tanque.h"
#include "DetalleVenta.h"
#include "Venta.h"
#include "StockProducto.h"


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
    void mostrarTanques(bool ordenadoPorEstado, bool mostrarEliminados = false);

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
    void altaTanque();//ABM TANQUE
    void modificarTanque();//ABM TANQUE
    void eliminarTanque();//ABM TANQUE
    void agregarStockTanque();

    void menuListados();//SUBMENU LISTADOS DENTRO DEL MENU PRINCIPAL ADMIN STOCK
    void listarAdmins();
    void listarPaises();
    void listarMisiles();
    void listarAviones();
    void listarBuques();
    void listarTanques();

    void ordenarPorEstado(Admin *vecAdmin, int cantidad);//ACTIVOS PRIMERO
    void ordenarPorEstado(Pais *vecPais, int cantidad);//ACTIVOS PRIMERO
    void ordenarPorEstado(Misil *vecMisil, int cantidad);//ACTIVOS PRIMERO
    void ordenarPorEstado(Avion *vecAvion, int cantidad);//ACTIVOS PRIMERO
    void ordenarPorEstado(Buque *vecBuque, int cantidad);//ACTIVOS PRIMERO
    void ordenarPorEstado(Tanque *vecTanque, int cantidad);//ACTIVOS PRIMERO

    void menuReportes();//SUBMENU REPORTES DENTRO DEL MENU PRINCIPAL ADMIN STOCK
///-------------------------------------------------------------------------------//
    void menuPrincipalPais(Pais &regPais);//MENU PRINCIPAL PAIS CLIENTE

    void solicitudDeAdquisiciones(Pais &regPais);
    void consultaDinero(Pais &regPais);
    void ingresoDinero(Pais &regPais);
    void comprarMisil (Pais &regPais, int &cantProductosComprados, DetalleVenta *vecDetalleVenta, long long &dineroAcumulado, StockProducto *vecProductosMisil, int tamanioMisil, int posDetalleVenta);

    void confirmarCompra(Pais &regPais, long long dineroAcumulado, DetalleVenta *vecDetalleVenta, int cantProductosAComprar, int cantProductosComprados, StockProducto *vecProductosMisil, StockProducto *vecProductosAvion, StockProducto *vecProductosBuque, StockProducto *vecProductosTanque);
    void comprasRealizadas(Pais &regPais);
private:
    int opcion;
};
