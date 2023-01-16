//
//  Tablero.hpp
//  HundirLaFlota
//
//  Created by Ivan on 4/1/23.
//

#ifndef Tablero_hpp
#define Tablero_hpp

#include <stdio.h>
#include "Casilla.hpp"
#include "ExcepcionFueraTablero.hpp"
#include "ExcepcionMalColocado.hpp"

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
    void establecerTocado(Fila, int);
    void mostrarTablero();
};


#endif /* Tablero_hpp */
