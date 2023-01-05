//
//  Jugador.h
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#ifndef Jugador_h
#define Jugador_h

#include <stdio.h>
#include "Barco.h"
#include "Tablero.h"

class Jugador {
private:
    bool turno;
    Tablero* tablerosJugador;
    Barco* barcos;
public:
    Jugador();
    void disparar(Fila, int);
    void marcarCasilla(Fila, int);
    void colocarBarcos();
    bool comprobarBarcos();
    void setTurno(bool);
};

#endif /* Jugador_h */
