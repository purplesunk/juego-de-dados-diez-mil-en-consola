#include <iostream>
#include <cstring>
#include <stdio.h>
#include "funciones.h"


void cargarVectorRandom(int vec[], int tam, int limite) {

    for (int i=0; i<tam; i++) {

        vec[i]=(rand()%limite)+1;

    }

}

void mostrarVec(int vec[], int tam) {
    for (int i=0; i<tam; i++) {

        std::cout << vec[i] << "\t";

    }

    std::cout << "\n";
}

int maxVector(int vec[], int tam) {
    int maximo = vec[0];

    for (int i=1; i<tam; i++) {

        if (vec[i]>maximo) {

            maximo=vec[i];
        }

    }

    return maximo;
}

int posMaxVector(int vec[], int tam) {

    int maximo = vec[0];
    int pos = 1;

    for (int i=1; i<tam; i++) {

        if ( vec[i] > maximo) {

            maximo=vec[i];

            pos=i+1;

        }
    }

    return pos;
}

bool hayCeros(int vec[], int tam){

    bool hayCero = false;

    for (int i=0;i<tam;i++) {

        if(vec[i]==0) {

            hayCero = true;

        }

    }

    return hayCero;

}

void cargarCadena(char *palabra, int tamano) {

    int i=0;

    fflush(stdin);

    for (i=0; i<tamano; i++){

        palabra[i]=std::cin.get();

        if (palabra[i]=='\n'){

            break;

        }

    }

    palabra[i]='\0';

    fflush(stdin);


}

void copiarCadenaHasta(char *copia, int tamanoCopia, char *original, int empezarEn, char caracter) {

    for (int i=0; i<tamanoCopia; i++) {

        copia[i] = original[empezarEn];

        empezarEn++;

        if (original[empezarEn] == caracter) {

            copia[i+1]='\0';

            empezarEn++;

            break;
        }

        if (i == tamanoCopia-1) {

            copia[i]='\0';

            break;
        }

    }

}

void separarNombre(char *nombreCompleto, char *nombre, int tamNombre) {

    copiarCadenaHasta(nombre, tamNombre, nombreCompleto, 0, char(32));

}


void cambiarMejorPuntaje(int mejorPuntaje[], int puntaje, int ronda, int lanzamiento) {

    mejorPuntaje[0] = puntaje;
    mejorPuntaje[1] = ronda;
    mejorPuntaje[2] = lanzamiento;

}

void compararMejorPuntaje(char *nombreMejorPuntaje, int mejorPuntaje[], char *nombreJugador, int  puntaje, int ronda, int lanzamiento) {

    if (puntaje > mejorPuntaje[0]) {

        cambiarMejorPuntaje(mejorPuntaje, puntaje, ronda, lanzamiento);
        strcpy(nombreMejorPuntaje, nombreJugador);

    }
    else if (puntaje == mejorPuntaje[0]) {

        if (ronda < mejorPuntaje[1]) {

            cambiarMejorPuntaje(mejorPuntaje, puntaje, ronda, lanzamiento);
            strcpy(nombreMejorPuntaje, nombreJugador);

        }

        else if (ronda == mejorPuntaje[1]) {

            if (lanzamiento < mejorPuntaje[2]) {

                cambiarMejorPuntaje(mejorPuntaje, puntaje, ronda, lanzamiento);
                strcpy(nombreMejorPuntaje, nombreJugador);

            }

        }

    }
}

