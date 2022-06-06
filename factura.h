#pragma once
#ifndef FACTURA_H
#define FACTURA_H
#include <string>
using namespace std;

class Factura
{
private:
    string cedula;
    string telefono;
    string direccion;
    string correo;
public:
    Factura();
    Factura(string, string, string, string);
    float calculo(float);
    void imprimirfactura();

};

#endif // FACTURA_H
