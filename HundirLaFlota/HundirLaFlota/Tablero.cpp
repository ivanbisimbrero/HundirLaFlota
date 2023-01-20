//
//  Tablero.cpp
//  HundirLaFlota
//
//  Created by Ivan on 4/1/23.
//

#include "Tablero.hpp"

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

int Tablero::casillasBarco(string tipoBarco) {
    int casillas = 0;
    if(tipoBarco == "Portaaviones") {
        casillas = 5;
    } else if(tipoBarco == "Acorazado") {
        casillas = 4;
    } else if(tipoBarco == "Submarino") {
        casillas = 3;
    } else if(tipoBarco == "Patrullero") {
        casillas = 2;
    } else if(tipoBarco == "Buque") {
        casillas = 1;
    }
    return casillas;
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
        case ERR:
            aux = -1;
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

bool Tablero::fueraTablero(string tipoBarco, Fila coordIniY, int CoordIniX, bool vertical) {
    if(coordIniY == ERR || (CoordIniX-1) < 0 || (CoordIniX-1) > 10) {return true;}
    bool fuera = false;
    int casillas = casillasBarco(tipoBarco)-1;
    if(vertical) {
        if(getIntFila(coordIniY)+casillas > 9) {
            fuera = true;
        }
    }
    else {
        if((CoordIniX-1)+casillas > 9) {
            fuera = true;
        }
    }
    return fuera;
}

bool Tablero::coincideBarco(string tipoBarco, Fila coordIniY, int CoordIniX, bool vertical) {
    bool coincide = false;
    int casillas = casillasBarco(tipoBarco);
    if(vertical) {
        for(int i = 0; i < casillas; i++) {
            if(tablero[getIntFila(coordIniY)+i][CoordIniX-1].comprobarOcupacion()) {
                coincide = true;
            }
        }
    }
    else {
        for(int i = 0; i < casillas; i++) {
            if(tablero[getIntFila(coordIniY)][CoordIniX+i-1].comprobarOcupacion()) {
                coincide = true;
            }
        }
    }
    return coincide;
}

bool Tablero::proximidad(string tipoBarco, Fila coordIniY, int CoordIniX, bool vertical) {
    bool proximo = false;
    int casillas = casillasBarco(tipoBarco);
    int iteracionesY = 0, iteracionesX = 0, coordActualY = 0, coordActualX = 0;
    if(vertical) {
        iteracionesY = casillas + 2;
        iteracionesX = 3;
    }
    else {
        iteracionesY = 3;
        iteracionesX = casillas + 2;
    }
    
    for(int i = 0; i < iteracionesY; i++) {
        coordActualY = getIntFila(coordIniY)-1+i;
        if(coordActualY >= 0 && coordActualY <= 9) {
            for(int j = 0; j < iteracionesX; j++) {
                coordActualX = CoordIniX-2+j;
                if(coordActualX >= 0 && coordActualX <= 9) {
                    if(i == 0 || i == iteracionesY-1) {
                        if(tablero[coordActualY][coordActualX].comprobarOcupacion()) {
                            proximo = true;
                        }
                    }
                    else {
                        if(tablero[coordActualY][CoordIniX-2].comprobarOcupacion()
                           || tablero[coordActualY][CoordIniX-2+(iteracionesX-1)].comprobarOcupacion()) {
                            proximo = true;
                        }
                    }
                }
            }
        }
    }
    
    return proximo;
}

bool Tablero::comprobarColocacion(string tipoBarco, Fila coordIniY, int CoordIniX, bool vertical) {
    return (proximidad(tipoBarco, coordIniY, CoordIniX, vertical) || coincideBarco(tipoBarco, coordIniY, CoordIniX, vertical));
}

void Tablero::colocarBarco(string tipoBarco, Fila coordIniY, int CoordIniX, bool vertical) {
    if(fueraTablero(tipoBarco, coordIniY, CoordIniX, vertical)) {
        throw ExcepcionFueraTablero();
    }
    else if(comprobarColocacion(tipoBarco, coordIniY, CoordIniX, vertical)) {
        throw ExcepcionMalColocado();
    }
    else {
        int casillas = casillasBarco(tipoBarco);
        if(vertical) {
            for(int i = 0; i < casillas; i++) {
                tablero[getIntFila(coordIniY) + i][CoordIniX - 1].setBarco();
            }
        } else {
            for(int i = 0; i < casillas; i++) {
                tablero[getIntFila(coordIniY)][CoordIniX + i - 1].setBarco();
            }
        }
    }
}

void Tablero::establecerTocado(Fila fila, int columna) {
    //Para ello, haremos como si en esa casilla hubiera un barco
    tablero[getIntFila(fila)][columna-1].setBarco();
}

char Tablero::letraFila(int num) {
    char fila;
    char aux = '\0';
    switch (num) {
        case 0:
            aux = 'A';
            break;
        case 1:
            aux = 'B';
            break;
        case 2:
            aux = 'C';
            break;
        case 3:
            aux = 'D';
            break;
        case 4:
            aux = 'E';
            break;
        case 5:
            aux = 'F';
            break;
        case 6:
            aux = 'G';
            break;
        case 7:
            aux = 'H';
            break;
        case 8:
            aux = 'I';
            break;
        case 9:
            aux = 'J';
            break;
    }
    return aux;
}

void Tablero::mostrarTablero() {
    cout << "   1  2  3  4  5  6  7  8  9  10" << endl;
    for(int i = 0; i < 10; i++) {
        cout << letraFila(i) << "  ";
        for(int j = 0; j < 10; j++) {
            cout << tablero[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
