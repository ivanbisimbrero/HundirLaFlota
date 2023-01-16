//
//  Submarino.hpp
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#ifndef Submarino_hpp
#define Submarino_hpp

#include <stdio.h>
#include "Barco.hpp"

class Submarino : public Barco {
public:
    Submarino();
    Submarino(Casilla, bool);
    Submarino(const Submarino&);
    Submarino& operator=(const Submarino&);
    string getType() {return "Submarino";}
};

#endif /* Submarino_hpp */
