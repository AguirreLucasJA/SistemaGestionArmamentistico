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

    void listarUsuariosYClientes();//SE USA EN "B", "M" DE USUARIOS/CLIENTES

    void Clientes();//SUBMENU CLIENTES/PAISES DENTRO DE MENU PRINCIPAL ADMIN

	void Stock(); //SUBMENU ADMINISTRADOR DENTRO DEL MENU PRINCIPAL ADMIN STOCK
	void StockMisiles();
	void StockAviones();
	void StockBuques();
	void StockTanques();



private:
    int opcion;

};
