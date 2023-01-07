//
//  Portaaviones.h
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#ifndef Portaaviones_h
#define Portaaviones_h

#include <stdio.h>
#include "Barco.h"

class Portaaviones : public Barco {
public:
    Portaaviones();
    Portaaviones(Casilla, bool);
    Portaaviones(const Portaaviones&);
    bool comprobarHundido();
    Casilla getCoordenadaInicial() {return coordenadaInicial;}
    Portaaviones& operator=(const Portaaviones&);
};

#endif /* Portaaviones_h */
