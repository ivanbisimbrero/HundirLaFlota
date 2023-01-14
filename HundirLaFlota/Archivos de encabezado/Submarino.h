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
    Submarino(const Submarino&);
    Submarino& operator=(const Submarino&);
    string getType() {return "Submarino";}
};

#endif /* Submarino_h */
