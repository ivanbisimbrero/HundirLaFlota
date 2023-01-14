//
//  Barco.h
//  HundirLaFlota
//
//  Created by Ivan on 4/1/23.
//

#ifndef Barco_h
#define Barco_h

#include <stdio.h>
#include <iostream>
#include "Casilla.h"

using namespace std;

class Barco {
protected:
    bool hundido;
    Casilla coordenadaInicial;
    int longitud;
    Casilla* casillasBarco;
    bool vertical;
public:
    Barco();
    Barco(Casilla, int, bool);
    Barco(const Barco&);
    //TODO: comprobarHundido y getCoordenadaInicial no son polimorfismo
    bool comprobarHundido();
    Barco& operator=(const Barco&);
    void mostrarCasillas();
    virtual string getType() = 0;
    bool isCasillaInBarco(Fila, int);
};

#endif /* Barco_h */
