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

    void Usuarios();//SUBmenu ADMIN ABML usuarios


private:
    int opcion;

};
