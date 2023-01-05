//
//  Jugador.cpp
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#include "Jugador.h"

Jugador::Jugador() {
    turno = false;
    tablerosJugador = new Tablero[2];
    barcos = new Barco[5];
}
