//
//  Tablero.cpp
//  HundirLaFlota
//
//  Created by Ivan on 4/1/23.
//

#include "Tablero.h"

Tablero::Tablero() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tablero[i][j] = Casilla(i, j+1);
        }
    }
}

Tablero::Tablero(const Tablero& t) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tablero[i][j] = t.tablero[i][j];
        }
    }
}

bool Tablero::comprobarProximidad(string tipoBarco, Fila coordIniY, int CoordIniX, bool vertical) {
    bool barcoProximo = false;
    //TODO: funcion que comprueba con perimetro de 1 casilla alrededor de un barco
    return barcoProximo;
}

void Tablero::colocarBarco(string tipoBarco, Fila coordIniY, int CoordIniX, bool vertical) {
    //TODO: colocar barco en el tablero
}

void Tablero::marcarCoordenada(Fila f, int col) {
    int filaAux = getIntFila(f);
    tablero[filaAux][col-1].marcarCasillaDisparada();
}

bool Tablero::comprobarCoordenada(Fila f, int col) {
    int filaAux = getIntFila(f);
    return (tablero[filaAux][col-1].comprobarOcupacion());
}

bool Tablero::comprobarDisparo(Fila f, int col) {
    int filaAux = getIntFila(f);
    return (tablero[filaAux][col-1].comprobarDisparo());
}

int Tablero::getIntFila(Fila f) {
    int aux;
    switch(f) {
        case A:
            aux = 0;
            break;
        case B:
            aux = 1;
            break;
        case C:
            aux = 2;
            break;
        case D:
            aux = 3;
            break;
        case E:
            aux = 4;
            break;
        case F:
            aux = 5;
            break;
        case G:
            aux = 6;
            break;
        case H:
            aux = 7;
            break;
        case I:
            aux = 8;
            break;
        case J:
            aux = 9;
            break;
    }
    return aux;
}

Tablero& Tablero::operator=(const Tablero& opDrcha) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tablero[i][j] = opDrcha.tablero[i][j];
        }
    }
    return *this;
}
