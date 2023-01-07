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
    Buque(const Buque&);
    bool comprobarHundido();
    Casilla getCoordenadaInicial() {return coordenadaInicial;}
    Buque& operator=(const Buque&);
};

#endif /* Buque_h */
