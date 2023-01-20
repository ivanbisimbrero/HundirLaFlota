//
//  Partida.h
//  HundirLaFlota
//
//  Created by Ivan on 16/1/23.
//

#ifndef Partida_hpp
#define Partida_hpp

#include <stdio.h>
#include "Jugador.hpp"

class Partida {
private:
    bool partidaEnCurso;
    bool pause;
    Jugador * jugadores;
public:
    Partida();
    Partida(const Partida&);
    Partida& operator=(const Partida&);
    void iniciarPartida();
    void cargarPartida();
    void guardarPartida();
    void disparar();
    void setPause(bool);
    void abandonar();
    void salirPartida();
    void juego();
};

#endif /* Partida_hpp */
