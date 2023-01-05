//
//  Tablero.h
//  HundirLaFlota
//
//  Created by Ivan on 4/1/23.
//

#ifndef Tablero_h
#define Tablero_h

#include <stdio.h>
#include "Casilla.h"

class Tablero {
private:
    Casilla tablero[10][10];
public:
    Tablero();
    Tablero(const Tablero&);
    bool comprobarProximidad(string, Fila, int, bool);
    void colocarBarco(string, Fila, int, bool);
    void marcarCoordenada(Fila, int);
    bool comprobarCoordenada(Fila, int);
    bool comprobarDisparo(Fila, int);
    int getIntFila(Fila);
    Tablero& operator=(const Tablero&);
};


#endif /* Tablero_h */
