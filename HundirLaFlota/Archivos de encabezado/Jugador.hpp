//
//  Jugador.hpp
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#ifndef Jugador_hpp
#define Jugador_hpp

#include <stdio.h>
#include "Barco.hpp"
#include "Portaaviones.hpp"
#include "Acorazado.hpp"
#include "Submarino.hpp"
#include "Patrullero.hpp"
#include "Buque.hpp"
#include "Tablero.hpp"
#include "ExcepcionFueraTablero.hpp"

class Jugador {
private:
    bool turno;
    Tablero* tablerosJugador;
    Barco* barcos[5];
    int identifier;
public:
    Jugador();
    Jugador(int);
    Jugador(const Jugador&);
    Jugador& operator=(const Jugador&);
    void setId(int);
    int getId() {return identifier;}
    bool getTurno() {return turno;}
    bool comprobarBarcos();
    void disparar(Fila, int);
    void marcarCasilla(Fila, int, bool);
    void setTurno(bool);
    void colocarBarcos();
    bool isTocado(Casilla);
private:
    bool comprobarDatos(char);
};

#endif /* Jugador_hpp */
