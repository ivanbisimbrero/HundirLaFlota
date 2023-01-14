//
//  Casilla.cpp
//  HundirLaFlota
//
//  Created by Ivan on 4/1/23.
//

#include "Casilla.h"

Casilla::Casilla() {
    disparada = false;
    hayBarco = false;
    coordenadaY = A;
    coordenadaX = 0;
}

Casilla::Casilla(int f, int col) {
    disparada = false;
    hayBarco = false;
    coordenadaY = getFila(f);
    coordenadaX = col;
}

void Casilla::modificarCoordenadas(int f, int col) {
    coordenadaY = getFila(f);
    coordenadaX = col;
}

void Casilla::marcarCasillaDisparada() {
    disparada = true;
}

void Casilla::setBarco() {
    hayBarco = true;
}

Fila Casilla::getFila(int num) {
    Fila aux = A;
    switch (num) {
        case 0:
            aux = A;
            break;
        case 1:
            aux = B;
            break;
        case 2:
            aux = C;
            break;
        case 3:
            aux = D;
            break;
        case 4:
            aux = E;
            break;
        case 5:
            aux = F;
            break;
        case 6:
            aux = G;
            break;
        case 7:
            aux = H;
            break;
        case 8:
            aux = I;
            break;
        case 9:
            aux = J;
            break;
        default:
            aux = ERR;
    }
    return aux;
}

int Casilla::getIntFila() {
    int aux;
    switch(coordenadaY) {
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
        case ERR:
            aux = 10;
            break;
    }
    return aux;
}



int Casilla::getColumna() {
    return coordenadaX;
}

void Casilla::mostrar() {
    cout << "(" << getIntFila() << " ," << coordenadaX << ")" << endl;
}

istream& operator>>(istream& is, Casilla& c) {
    char charFila;
    cout << "Introduzca la coordenada del eje Y: " << endl;
    is >> charFila;
    switch (charFila) {
        case 'A':
            c.coordenadaY = A;
            break;
        case 'B':
            c.coordenadaY = B;
            break;
        case 'C':
            c.coordenadaY = C;
            break;
        case 'D':
            c.coordenadaY = D;
            break;
        case 'E':
            c.coordenadaY = E;
            break;
        case 'F':
            c.coordenadaY = F;
            break;
        case 'G':
            c.coordenadaY = G;
            break;
        case 'H':
            c.coordenadaY = H;
            break;
        case 'I':
            c.coordenadaY = I;
            break;
        case 'J':
            c.coordenadaY = J;
            break;
        default:
            c.coordenadaY = ERR;
            break;
    }
    cout << "Introduzca la coordenada del eje X: " << endl;
    is >> c.coordenadaX;
    return is;
}
