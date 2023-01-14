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
#include "Portaaviones.h"
#include "Acorazado.h"
#include "Submarino.h"
#include "Patrullero.h"
#include "Buque.h"
#include "Tablero.h"
#include "ExcepcionFueraTablero.h"

class Jugador {
private:
    bool turno;
    Tablero* tablerosJugador;
    Barco* barcos[5];
public:
    Jugador();
    Jugador(const Jugador&);
    Jugador& operator=(const Jugador&);
    bool comprobarBarcos();
    void disparar(Fila, int);
    void marcarCasilla(Fila, int);
    void setTurno(bool);
    void colocarBarcos();
private:
    bool comprobarDatos(char);
};

#endif /* Jugador_h */
