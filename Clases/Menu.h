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

    void Usuarios();//METODO del SUBmenu ADMIN ABM usuarios
    void altaUsuario();//METODO del SUBmenu ADMIN ABM usuarios
    void modificarUsuario();//METODO del SUBmenu ADMIN ABM usuarios

    void listarUsuarios();


private:
    int opcion;

};
