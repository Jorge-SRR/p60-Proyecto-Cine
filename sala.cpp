#include <iostream>
#include <cctype>
#include <iomanip>
#include "Sala.h"
#include <iostream>
using namespace std;
Sala::Sala() {

    for (int i = 0; i <= tamanio; i++) {

        for (int j = 0; j < tamanio; j++) {

            sala[i][j] = 'O';

        }

    }

}

void Sala::mostrarSala() {

    for (int i = 1; i <= tamanio; i++) {

        cout << setw(5) << i;

    }
    cout << endl;

    for (int i = 0; i < tamanio; i++) {

        cout << ((char)(65 + i));

        for (int j = 0; j < tamanio; j++) {

            cout << setw(5) << sala[i][j];

        }

        cout << "\n";
        cout << endl;

    }

}

int Sala::obtenerFila(char fila) {

    int filaPosicion;

    switch (fila) {


    case 'A': filaPosicion = 1;
        break;

    case 'B': filaPosicion = 2;
        break;

    case 'C': filaPosicion = 3;
        break;

    case 'D': filaPosicion = 4;
        break;

    case 'E': filaPosicion = 5;
        break;
    }

    return filaPosicion;

}

void Sala::modificarSalar() {

    int filaPosicion;

    do {

        do {

            cout << "Ingrese el asiento: ";
            cin >> fila >> columna;

            if (fila < 'A' or fila > 'D' or columna < 1 or columna > 5) {

                cout << "El lugar que esta eligiendo no existe" << endl;

            }

        } while (fila < 'A' or fila > 'E' or columna < 1 or columna > 5);

        columna = -1;

        filaPosicion = obtenerFila(fila);

        if (sala[filaPosicion][columna] == 'X') {

            cout << "El asiento ya esta ocupado" << endl;

        }

    } while (sala[filaPosicion][columna] == 'X');

    sala[filaPosicion][columna] = 'X';

}

int Sala::getColumna() {

    return columna - 1;

}

char Sala::getFila() {

    return fila;

}
