//
// Created by Thiago Medeiros on 02/09/21.
//

#ifndef PEDA_AULA_5___FILAS_FILA_H
#define PEDA_AULA_5___FILAS_FILA_H

#include <array>

const int MAXFILA = 10;
using TipoDado = int;

class Fila {
private:
    // Atributos
    // TipoDado dados[MAXPILHA];
    std::array<TipoDado, MAXFILA> dados;
    int _frente, _fim;
public:
    // Métodos
    Fila();
    void insere(TipoDado elemento);
    void insere_pdesc(TipoDado elemento);
    TipoDado frente();
    void remove();
    bool vazia();
    bool cheia();
    void insere_frente(TipoDado elemento);
    void remove_fim();
    TipoDado fim();
    void imprimir();
};


#endif //PEDA_AULA_5___FILAS_FILA_H
