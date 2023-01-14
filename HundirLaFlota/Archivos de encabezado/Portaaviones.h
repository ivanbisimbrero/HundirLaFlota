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
    Portaaviones& operator=(const Portaaviones&);
    string getType() {return "Portaaviones";}
};

#endif /* Portaaviones_h */
