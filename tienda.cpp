#include "tienda.h"
#include <string>
#include <iostream>
using namespace std;
Tienda::Tienda()
{

}
Tienda::Tienda(string productos[], string combos[]) {
    for (int i = 0; i < 5; i++) {
        this->productos[i] = productos[i];
        this->combos[i] = combos[i];
    }
}
void Tienda::mostrar() {
    for (int i = 0; i < 5; i++) {

        cout << i + 1 << ". " << productos[i] << endl;

    }
    for (int i = 0; i < 5; i++) {

        cout << i + 1 << ". " << combos[i] << endl;

    }
}
void Tienda::producto() {
    for (int i = 0; i < 5; i++) {

        cout << i + 1 << ". " << productos[i] << endl;

    }
}
void Tienda::combo() {
    for (int i = 0; i < 5; i++) {

        cout << i + 1 << ". " << combos[i] << endl;

    }
}
