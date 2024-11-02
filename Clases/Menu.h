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

    void subMenuAdmin();//SUBMENU ADMIN DENTRO DE MENU PRINCIPAL ADMIN
    void altaAdmin();//ABM ADMIN
    void modificarAdmin();//ABM ADMIN
    void eliminarAdmin();//ABM ADMIN

    void listarAdmins();//SE USA EN "BAJA", "MODIFICACION" DE ADMIN
    void listarClientes();//SE USA EN "BAJA", "MODIFICACION" DE PAISES

    void Clientes();//SUBMENU CLIENTES/PAISES DENTRO DE MENU PRINCIPAL ADMIN
    void altaCliente();//ABM PAISES
    void modificarCliente();//ABM PAISES
    void eliminarCliente();//ABM PAISES

	void Stock(); //SUBMENU STOCK DENTRO DEL MENU PRINCIPAL ADMIN STOCK
	void StockMisiles();//SUBMENU
	void StockAviones();//SUBMENU
	void StockBuques();//SUBMENU
	void StockTanques();//SUBMENU

	void Listados(); //SUBMENU ADMIN



private:
    int opcion;

};
