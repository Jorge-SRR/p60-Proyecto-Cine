#ifndef PELICULA_H

#define PELICULA_H

#define tamanio 5
#include <iostream>

using namespace std;

class Pelicula {

private:

    int idPelicula[tamanio];
    string titulo[tamanio];
    float duracion[tamanio];
    bool estreno[tamanio];
    string hora[tamanio];

public:

    Pelicula();
    Pelicula(int[], string[], int[], bool[], string[]);
    int buscarPelicula(int);
    void mostrarPelicula(int);
    void mostrarPeliculas();
    string getTitulo(int);
    string getHora(int);
};


#endif // PELICULA_H
