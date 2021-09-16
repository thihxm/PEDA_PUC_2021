//
// Created by Thiago Medeiros on 02/09/21.
//

#include "Fila.h"
#include <iostream>
#include <vector>

using namespace std;

int prox(int i);
int anterior(int i);

Fila::Fila() {
    _frente = MAXFILA - 1;
    _fim = MAXFILA - 1;
}

void Fila::insere(TipoDado elemento) {
    if (cheia()) {
        cerr << "Fila cheia!" << endl;
        return;
    }
    _fim = prox(_fim);
    dados[_fim] = elemento;
}

void Fila::insere_pdesc(TipoDado elemento) {
    if (cheia()) {
        cerr << "Fila cheia!" << endl;
        return;
    }
    int pos = prox(_frente);
    while (pos != prox(_fim) && dados[pos] <= elemento) {
        pos = prox(pos);
    }

    _fim = prox(_fim);
    int posAux = _fim;
    while (posAux != pos) {
        dados[posAux] = dados[anterior(posAux)];
        posAux = anterior(posAux);
    }

    dados[pos] = elemento;
}

TipoDado Fila::frente() {
    if (vazia()) {
        cerr << "Fila vazia!" << endl;
        return 0;
    }
    return dados[prox(_frente)];
}

void Fila::remove() {
    if (vazia()) {
        cerr << "Fila vazia!" << endl;
        return;
    }
    _frente = prox(_frente);
}

bool Fila::vazia() {
    return _frente == _fim;
}

bool Fila::cheia() {
    return prox(_fim) == _frente;
}

void Fila::insere_frente(TipoDado elemento) {
    if (cheia()) {
        cerr << "Fila cheia!" << endl;
        return;
    }
    dados[_frente] = elemento;
    _frente = anterior(_frente);
}

void Fila::remove_fim() {
    if (vazia()) {
        cerr << "Fila vazia!" << endl;
        return;
    }
    _fim = anterior(_fim);
}

TipoDado Fila::fim() {
    if (vazia()) {
        cerr << "Fila vazia!" << endl;
        return 0;
    }
    return dados[_fim];
}

void Fila::imprimir() {
    vector<TipoDado> vetorImp;

    for (int i = _fim; i != _frente; i = anterior(i)) {
        vetorImp.push_back(dados[i]);
    }

    for (vector<TipoDado>::reverse_iterator it = vetorImp.rbegin(); it != vetorImp.rend(); ++it) {
        cout << *it << endl;
    }
    vetorImp.clear();
}

int prox(int i) {
    int proximaPosicao = i + 1;
    if (proximaPosicao == MAXFILA) {
        proximaPosicao = 0;
    }
    return proximaPosicao;
}

int anterior(int i) {
    int proximaPosicao = i - 1;
    if (proximaPosicao == -1) {
        proximaPosicao = MAXFILA - 1;
    }
    return proximaPosicao;
}