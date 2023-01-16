//
//  Portaaviones.hpp
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#ifndef Portaaviones_hpp
#define Portaaviones_hpp

#include <stdio.h>
#include "Barco.hpp"

class Portaaviones : public Barco {
public:
    Portaaviones();
    Portaaviones(Casilla, bool);
    Portaaviones(const Portaaviones&);
    Portaaviones& operator=(const Portaaviones&);
    string getType() {return "Portaaviones";}
};

#endif /* Portaaviones_hpp */
