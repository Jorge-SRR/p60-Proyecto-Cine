#pragma once
#ifndef SALA_H

#define SALA_H

#define tamanio 5

class Sala {

private:
    char sala[tamanio][tamanio];
    int columna;
    char fila;

public:

    Sala();
    void mostrarSala();
    void modificarSalar();
    int obtenerFila(char);
    char getFila();
    int getColumna();

};

#endif // !SALA_H
