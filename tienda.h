#pragma once
#ifndef TIENDA_H
#define TIENDA_H

#include <string>

using namespace std;

class Tienda
{
private:
    string productos[5];
    string combos[5];
public:
    Tienda();
    Tienda(string[], string[]);
    void mostrar();
    void producto();
    void combo();
};

#endif // TIENDA_H
