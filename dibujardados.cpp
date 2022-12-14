#include <iostream>
#include "rlutil.h"
#include "interfaz.h"
#include "dibujardados.h"

void dibujarUno(int posx, int posy) {
    dibujarLinea(posx+3,posy+1,1,char(223));
}

void dibujarDos(int posx, int posy) {
    dibujarLinea(posx+1,posy,1,char(220));
    dibujarLinea(posx+5,posy+1,1,char(220));
}

void dibujarTres(int posx, int posy) {
    dibujarUno(posx, posy);
    dibujarDos(posx, posy);
}

void dibujarCuatro(int posx, int posy) {
    dibujarDos(posx, posy);
    dibujarLinea(posx+5,posy,1,char(220));
    dibujarLinea(posx+1,posy+1,1,char(220));
}

void dibujarCinco(int posx, int posy) {
    dibujarUno(posx, posy);
    dibujarCuatro(posx, posy);
}

void dibujarSeis(int posx, int posy) {
    dibujarCuatro(posx, posy);
    dibujarLinea(posx+3,posy,1,char(220));
    dibujarLinea(posx+3,posy+1,1,char(220));
}

void elegirNumero(int posx, int posy, int num) {
    switch (num) {
        case 1:
            dibujarUno(posx, posy);
            break;
        case 2:
            dibujarDos(posx, posy);
            break;
        case 3:
            dibujarTres(posx, posy);
            break;
        case 4:
            dibujarCuatro(posx, posy);
            break;
        case 5:
            dibujarCinco(posx, posy);
            break;
        case 6:
            dibujarSeis(posx, posy);
            break;
    }
}

void dibujarSombraDado(int posx, int posy) {

    ponerColores(rlutil::CYAN, rlutil::BLACK);
    dibujarLinea(posx,posy+2,1,char(220));


    ponerColores(rlutil::CYAN, rlutil::BLUE);
    dibujarLinea(posx+1,posy+2,6,char(220));


    ponerColores(rlutil::BLACK, rlutil::BLUE);
    dibujarLinea(posx+7,posy,1,char(220));


    rlutil::setBackgroundColor(rlutil::BLUE);
    dibujarLinea(posx+7,posy+1,1,' ');
    dibujarLinea(posx+7,posy+2,1,' ');

}

void dibujarFormaDado(int posx, int posy) {

    rlutil::setBackgroundColor(rlutil::CYAN);

    dibujarLinea(posx,posy,7,char(32));
    dibujarLinea(posx,posy+1,7,char(32));
    dibujarLinea(posx,posy+2,7,char(32));

}

void dibujarDado(int posx, int posy, int num) {

    dibujarFormaDado(posx, posy);
    dibujarSombraDado(posx, posy);

    ponerColores(rlutil::CYAN, rlutil::BLACK);

    elegirNumero(posx, posy, num);

    ponerColores(rlutil::BLACK, rlutil::WHITE);
}

void dibujarDados(int posx, int posy, int vec[], int cantDados) {
    int espacioParaDado=rlutil::tcols()/(cantDados*3);
    int gap = 5;

    for (int i=0; i<cantDados; i++) {

        int inicioEspacio = posx + (espacioParaDado+7) * i;

        int posXdado = (rand()% espacioParaDado) + gap + inicioEspacio;
        int posYdado = rand()%5 + posy;

        dibujarDado(posXdado,posYdado,vec[i]);
    }
}

void borrarDados() {
    for (int i=9; i<18; i++) {
        dibujarLinea(1,i,rlutil::tcols()-5,char(32));
    }
}
