//
//  Casilla.h
//  HundirLaFlota
//
//  Created by Ivan on 4/1/23.
//

#ifndef Casilla_h
#define Casilla_h

#include <stdio.h>
#include <iostream>
#include "Fila.h"

using namespace std;

class Casilla {
private:
    bool disparada;
    bool hayBarco;
    Fila coordenadaY;
    int coordenadaX;
public:
    bool comprobarOcupacion() {return hayBarco;}
    void marcarCasillaDisparada();
    bool comprobarDisparo() {return disparada;}
};

#endif /* Casilla_h */
