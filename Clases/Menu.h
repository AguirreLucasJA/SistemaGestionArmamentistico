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

    void Usuarios();//SUBMENU USUARIOS DENTRO DE MENU PRINCIPAL ADMIN
    void altaUsuario();//ABM USUARIOS
    void modificarUsuario();//ABM USUARIOS
    void eliminarUsuario();//ABM USUARIOS

    void listarUsuarios();//SE USA EN "BAJA", "MODIFICACION" DE USUARIOS
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



private:
    int opcion;

};
