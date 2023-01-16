//
//  Patrullero.hpp
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#ifndef Patrullero_hpp
#define Patrullero_hpp

#include <stdio.h>
#include "Barco.hpp"

class Patrullero : public Barco {
public:
    Patrullero();
    Patrullero(Casilla, bool);
    Patrullero(const Patrullero&);
    Patrullero& operator=(const Patrullero&);
    string getType() {return "Patrullero";}
};

#endif /* Patrullero_hpp */
