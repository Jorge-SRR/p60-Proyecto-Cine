#include "factura.h"
#include <iostream>
#include <string>

using namespace std;
Factura::Factura()
{

}
Factura::Factura(string cedula, string telefono, string direccion, string correo) {
    this->cedula = cedula;
    this->telefono = telefono;
    this->direccion = direccion;
    this->correo = correo;
}

void Factura::imprimirfactura() {
    cout << "Mostrando los datos del cliente\n";
    cout << "Cedula:" << cedula << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Correo: " << correo << endl;
}
float Factura::calculo(float total) {
    float subtotal, iva, total1;
    subtotal = total;
    iva = subtotal * 0.12;
    total1 = subtotal + iva;

    return total1;

}
