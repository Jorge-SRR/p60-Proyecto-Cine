#include <iostream>
#include "Sala.h"
#include "Pelicula.h"
#include "Boleto.h"
#include "factura.h"
#include "tienda.h"

#define COMBO1 23.45
#define COMBO2 33.45
#define COMBO3 43.45
#define COMBO4 53.45
#define COMBO5 63.45

#define PRODUCTO1 12.34
#define PRODUCTO2 22.34
#define PRODUCTO3 32.34
#define PRODUCTO4 42.34
#define PRODUCTO5 52.34

#define SALA1 2.34
#define SALA2 3.34
#define SALA3 4.34
#define SALA4 5.34
#define SALA5 6.34

#define SALAVERMEOUTH 3.45

using namespace std;

int main() {
    cout << "Autores: Hanner Joan Delgado Espino\n"
        "         Byron Geovanny Jaramillo Namicela\n"
        "         Tobar Soberon Justin Edu\n"
        "         Jorge Sebastian Reinoso Reyes\n";
    int opcion, numeroSala, posicion, totalBoletos, idBuscar, columna, totalProductos = 0, salaVermeouth, edad;
    char fila;
    int id;
    bool continuar = true;
    int factura = 0;
    char condicion;
    float totalpagar = 0;
    string productos[] = { "Doritos","Papas","Pizza","Coca-Cola","Pepsi" };
    string combos[] = { "Canguil,Coca-Cola,Pizza","Canguil,Papas,Coca-Cola","Canguil,Pizza, Pepsi","Cangil,Pespi,Hot Dog","Canguil,Pepsi,Coca-Cola" };
    int idPelicula[] = { 1, 2, 3, 4, 5 };
    Tienda tienda(productos, combos);
    string hora[] = { "14:30", "16:00", "18:20", "16:15", "11:30" };

    string titulo[] = { "El Rey Leon", "Spiderma: Lejos de Casa", "Annabelle 3: Vuelve a Casa", "Avengers: End Game", "Toy Story 4" };
    string cedula, telefono, correo, direccion;
    int duracion[] = { 117, 130, 106, 188, 104 };

    bool estreno[] = { true, true, false, false, false };

    Sala sala[5];

    Pelicula pelicula(idPelicula, titulo, duracion, estreno, hora);

    Boleto boletos[25];

    float precioBoleto = 0.0, descuentos = 0.0;

    while (continuar) {

        cout << "- - M I   C I N E - -" << endl << endl;

        cout << "--------- MENU PRINCIPAL -----" << endl;
        cout << "1. Mostrar Cartelera\n"
            "2. Mostrar Sala\n "
            "3. Comprar Boletos\n "
            "4. Factura\n"
            "5. Tienda de Productos\n"
            "6. Salir\n" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:

            cout << "\n\n- - C A R T E L E R A - -" << endl << endl;

            pelicula.mostrarPeliculas();

            break;

        case 2:

            cout << "Ingrese el numero de sala: ";
            cin >> numeroSala;

            posicion = pelicula.buscarPelicula(numeroSala);

            if (posicion != -1) {

                pelicula.mostrarPelicula(posicion);

                cout << "\n- - A S I E N T O S - -" << endl;

                sala[posicion].mostrarSala();

            }
            else {

                cout << "No se encontro la sala del cine" << endl;

            }

            break;

        case 3:

            cout << "Ingrese el ID de la pelicula: ";
            cin >> idBuscar;

            do {

                cout << "Ingrese el numero de boletos: ";
                cin >> totalBoletos;

                if (totalBoletos < 1) {

                    cout << "El numero de boletos no pueden ser negativos" << endl;

                }

            } while (totalBoletos < 1);

            posicion = pelicula.buscarPelicula(idBuscar);

            if (posicion != -1) {

                cout << "Desea tener sala vermeouht(si=1): ";
                cin >> salaVermeouth;

                if (salaVermeouth == 1) {

                    totalpagar += SALAVERMEOUTH;

                }

                switch (posicion) {

                case 0: totalpagar += SALA1;  break;
                case 1: totalpagar += SALA2; break;
                case 2: totalpagar += SALA3; break;
                case 3: totalpagar += SALA4; break;
                case 4: totalpagar += SALA5; break;

                }

                cout << "\nSeleccione los asientos" << endl;

                for (int i = 0; i < totalBoletos; i++) {

                    do {

                        cout << "1. Niño\n2. Adulto\n3. Adulto Mayor" << endl;
                        cout << "Elija su edad: ";
                        cin >> edad;

                        switch (edad) {

                        case 1:
                        case 3:

                            descuentos += 0.50;
                            break;

                        }

                    } while (edad < 1 or edad > 3);

                    sala[posicion].modificarSalar();

                    fila = sala[posicion].getFila();

                    columna = sala[posicion].getColumna();

                    boletos[i] = Boleto(idBuscar, pelicula, fila, columna);

                }

                std::cout << "\nTOTAL DE LA COMPRA: " << endl;

                for (int i = 0; i < totalBoletos; i++) {

                    cout << "\n\nBoleto #" << i + 1 << endl;

                    cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;

                    boletos[i].mostrarBoleto();

                    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;

                }
                totalpagar = (totalBoletos * precioBoleto) - ((totalBoletos * precioBoleto) * descuentos);
                cout << "\nTOTAL: " << totalpagar;

            }
            else {

                cout << "No se encontro la sala del cine" << endl;

            }

            break;
        case 4:
            cout << "\n- - F A C T U R A  - -" << endl;
            if (factura == 0) {
                cout << "No se han emitido facturas por el momento\n";
            }
            else {
                Factura factura1[100];

                cout << "Total de factura a realizar: ";
                cin >> factura;

                for (int i = 0; i < factura; i++) {
                    cin.ignore();
                    cout << "Cedula: ";
                    getline(cin, cedula);
                    cout << "Telefono: ";
                    getline(cin, telefono);
                    cout << "Direccion: ";
                    getline(cin, direccion);
                    cout << "Correo: ";
                    getline(cin, correo);

                    factura1[i] = Factura(cedula, telefono, direccion, correo);

                    cout << "Ingrese su monto que pago: ";
                    cin >> totalpagar;

                    factura1[i].calculo(totalpagar);

                }

                for (int i = 0; i < factura; i++) {
                    factura1[i].imprimirfactura();

                    cout << "El total a pagar es de: " << factura1[i].calculo(totalpagar);

                }
            }

            break;
        case 5:
            cout << "- - M I   T I E N D A - -" << endl << endl;

            cout << "--------- MENU PRINCIPAL -----" << endl;
            cout << "1. Mostrar Productos\n"
                "2. Comprar Combo\n "
                "3. Comprar Producto\n "
                "4. Salir" << endl;
            cout << "Ingrese su opcion: ";
            cin >> opcion;
            switch (opcion) {

            case 1:
                tienda.mostrar();
                break;

            case 2:

                tienda.combo();
                do {

                    cout << "Ingrese el id del combo a comprar: ";
                    cin >> id;

                    if (id < 1 or id > 5) {

                        cout << "Error" << endl;

                    }


                } while (id < 1 or id > 5);


                switch (id) {

                case 1: totalpagar = COMBO1; break;
                case 2: totalpagar = COMBO1; break;
                case 3: totalpagar = COMBO1; break;
                case 4: totalpagar = COMBO1; break;
                case 5: totalpagar = COMBO1; break;
                }

                cout << "El total a pagar es de: " << totalpagar;

                break;
            case 3:

                tienda.producto();

                do {

                    cout << "Ingrese el id del combo a comprar: ";
                    cin >> id;

                    if (id < 1 or id > 5) {

                        cout << "Error" << endl;

                    }


                } while (id < 1 or id > 5);

                cout << "Ingrese el total de productos a comprar: ";
                cin >> totalProductos;

                switch (id) {

                case 1: totalpagar = PRODUCTO1 * totalProductos; break;
                case 2: totalpagar = PRODUCTO2 * totalProductos; break;
                case 3: totalpagar = PRODUCTO3 * totalProductos; break;
                case 4: totalpagar = PRODUCTO4 * totalProductos; break;
                case 5: totalpagar = PRODUCTO5 * totalProductos; break;
                }

                cout << "El total a pagar es de: " << totalpagar << endl;

                break;
            }

            break;

        case 6:

            continuar = false;

            cout << "Saliendo del programa" << endl;

            break;

        default:
            cout << "Opcion invalida" << endl;

        }

        if (opcion != 4) {

            cout << endl;
            system("pause");
            system("cls");

        }

    }

}
