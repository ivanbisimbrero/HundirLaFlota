//
//  Casilla.h
//  HundirLaFlota
//
//  Created by Ivan on 4/1/23.
//

#ifndef Casilla_h
#define Casilla_h

#include <stdio.h>
#include "Fila.h"

using namespace std;

class Casilla {
private:
    bool disparada;
    bool hayBarco;
    Fila coordenadaY;
    int coordenadaX;
public:
    Casilla();
    Casilla(int, int);
    Casilla(const Casilla&);
    void modificarCoordenadas(int, int);
    bool comprobarOcupacion() {return hayBarco;}
    void marcarCasillaDisparada();
    void setBarco();
    bool comprobarDisparo() {return disparada;}
    Casilla& operator=(const Casilla&);
    Fila getFila(int);
};

#endif /* Casilla_h */
