#pragma once

#include<iostream>
#include<ctime>
using namespace std;

class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha(int d=0, int m=0, int a=0) {
        if (d == 0 && m == 0 && a == 0) {
            time_t t = time(0);
            struct tm *now = localtime(&t);
            dia = now->tm_mday;
            mes = now->tm_mon + 1;
            anio = now->tm_year + 1900;
        } else {
            dia = d;
            mes = m;
            anio = a;
        }
    }

    void setearFecha(int d, int m, int a){
        dia = d;
        mes = m;
        anio = a;
    }

    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAnio() { return anio; }


    void Mostrar() {
        std::cout << "FECHA: " << dia << "/" << mes << "/" << anio << std::endl;
    }

};
