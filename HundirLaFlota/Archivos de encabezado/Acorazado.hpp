//
//  Acorazado.hpp
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#ifndef Acorazado_hpp
#define Acorazado_hpp

#include <stdio.h>
#include "Barco.hpp"

class Acorazado : public Barco {
public:
    Acorazado();
    Acorazado(Casilla, bool);
    Acorazado(const Acorazado&);
    Acorazado& operator=(const Acorazado&);
    string getType() {return "Acorazado";}
};

#endif /* Acorazado_hpp */
