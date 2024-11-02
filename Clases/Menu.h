#pragma once

class Menu
{
public:
    Menu() {};
    void dibujarCuadro(int x1, int y1, int x2, int y2);
    void gotoxy(int x, int y);
    void cabecera();

    bool menuOpcion(); // MENU INGRESO USERS/ADMINS

    void menuPrincipalAdmin();// MENU PRINCIPAL ADMIN

    void menuAdmin();//SUBMENU ADMIN DENTRO DE MENU PRINCIPAL ADMIN
    void altaAdmin();//ABM ADMIN
    void modificarAdmin();//ABM ADMIN
    void eliminarAdmin();//ABM ADMIN

    void listarAdmins();//SE USA EN "BAJA", "MODIFICACION" DE ADMIN
    void listarPaises();//SE USA EN "BAJA", "MODIFICACION" DE PAIS

    void menuPaises();//SUBMENU PAIS DENTRO DE MENU PRINCIPAL ADMIN
    void altaPais();//ABM PAIS
    void modificarPais();//ABM PAIS
    void eliminarPais();//ABM PAIS

	void menuStock(); //SUBMENU STOCK DENTRO DEL MENU PRINCIPAL ADMIN STOCK
	void subMenuStockMisiles();//SUBMENU
	void subMenuStockAviones();//SUBMENU
	void subMenuStockBuques();//SUBMENU
	void subMenuStockTanques();//SUBMENU

	void menuListados(); //SUBMENU LISTADOS DENTRO DEL MENU PRINCIPAL ADMIN STOCK



private:
    int opcion;

};
