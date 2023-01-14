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
#include "ExcepcionFueraTablero.h"
#include "ExcepcionMalColocado.h"

class Tablero {
private:
    Casilla tablero[10][10];
    bool proximidad(string, Fila, int, bool);
    bool fueraTablero(string, Fila, int, bool);
    bool coincideBarco(string, Fila, int, bool);
    int casillasBarco(string);
    bool comprobarColocacion(string, Fila, int, bool);
public:
    Tablero();
    Tablero(const Tablero&);
    void colocarBarco(string, Fila, int, bool);
    void marcarCoordenada(Fila, int);
    bool comprobarCoordenada(Fila, int);
    bool comprobarDisparo(Fila, int);
    int getIntFila(Fila);
    Tablero& operator=(const Tablero&);
};


#endif /* Tablero_h */
