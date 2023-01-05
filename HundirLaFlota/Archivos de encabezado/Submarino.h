//
//  Submarino.h
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#ifndef Submarino_h
#define Submarino_h

#include <stdio.h>
#include "Barco.h"

class Submarino : public Barco {
public:
    Submarino();
    Submarino(Casilla, bool);
    bool comprobarHundido();
};

#endif /* Submarino_h */
