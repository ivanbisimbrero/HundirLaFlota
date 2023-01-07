//
//  Acorazado.h
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#ifndef Acorazado_h
#define Acorazado_h

#include <stdio.h>
#include "Barco.h"

class Acorazado : public Barco {
public:
    Acorazado();
    Acorazado(Casilla, bool);
    Acorazado(const Acorazado&);
    bool comprobarHundido();
    Casilla getCoordenadaInicial() {return coordenadaInicial;}
    Acorazado& operator=(const Acorazado&);
};

#endif /* Acorazado_h */
