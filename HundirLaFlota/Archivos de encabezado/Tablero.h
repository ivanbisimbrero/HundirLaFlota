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
    void colocarBarco(string, Fila, int, bool);
    void marcarCoordenada(Fila, int);
    bool comprobarCoordenada(Fila, int);
    bool comprobarDisparo(Fila, int);
};


#endif /* Tablero_h */
