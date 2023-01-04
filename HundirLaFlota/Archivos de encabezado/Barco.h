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
    Casilla* casillasBarco;
    int longitud;
    bool vertical;
public:
    bool comprobarHundido();
};

#endif /* Barco_h */
