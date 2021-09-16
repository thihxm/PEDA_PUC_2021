#include <iostream>
#include <array>
#include "Fila.h"

using namespace std;

int main() {
    array<Fila, 3> filas;
    Fila fila;
    fila.insere(1);
    fila.insere(4);
    fila.insere(6);
    fila.insere(10);
    fila.insere(15);
    fila.imprimir();

    fila.insere_frente(9);
    cout << "--------------------------------" << endl;

    fila.insere_pdesc(11);
    fila.imprimir();
    cout << "--------------------------------" << endl;

    fila.remove_fim();
    while (!fila.vazia()) {
        cout << fila.frente() << endl;
        fila.remove();
    }
    cout << "--------------------------------" << endl;

    return 0;
}