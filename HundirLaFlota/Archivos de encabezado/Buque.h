//
//  Buque.h
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#ifndef Buque_h
#define Buque_h

#include <stdio.h>
#include "Barco.h"

class Buque : public Barco {
public:
    Buque();
    Buque(Casilla, bool);
    bool comprobarHundido();
};

#endif /* Buque_h */
