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
    Jugador j1;
    Jugador j2;
public:
    Partida();
    Partida(const Partida&);
    Partida& operator=(const Partida&);
    void iniciarPartida();
    void cargarPartida();
    void guardarPartida();
    void disparar();
    void abandonar();
    void salirPartida();
};

#endif /* Partida_hpp */
