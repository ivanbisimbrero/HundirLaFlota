//
//  Buque.h
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#ifndef Buque_hpp
#define Buque_hpp

#include <stdio.h>
#include "Barco.hpp"

class Buque : public Barco {
public:
    Buque();
    Buque(Casilla, bool);
    Buque(const Buque&);
    Buque& operator=(const Buque&);
    string getType() {return "Buque";}
};

#endif /* Buque_hpp */
