//
//  ExcepcionMalColocado.h
//  HundirLaFlota
//
//  Created by Ivan on 14/1/23.
//

#ifndef ExcepcionMalColocado_h
#define ExcepcionMalColocado_h
#include <stdio.h>
#include <stdexcept>

using namespace std;

class ExcepcionMalColocado : public invalid_argument {
public:
    ExcepcionMalColocado() : invalid_argument("Excepcion: el barco no respeta la casilla de perimetro o coincide con otro barco") {}
};


#endif /* ExcepcionMalColocado_h */
