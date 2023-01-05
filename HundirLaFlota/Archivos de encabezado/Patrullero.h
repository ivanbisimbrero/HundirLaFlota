//
//  Patrullero.h
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#ifndef Patrullero_h
#define Patrullero_h

#include <stdio.h>
#include "Barco.h"

class Patrullero : public Barco {
public:
    Patrullero();
    Patrullero(Casilla, bool);
    bool comprobarHundido();
};

#endif /* Patrullero_h */
