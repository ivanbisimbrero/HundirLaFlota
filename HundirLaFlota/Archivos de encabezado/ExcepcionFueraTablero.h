//
//  ExcepcionFueraTablero.h
//  HundirLaFlota
//
//  Created by Ivan on 14/1/23.
//

#ifndef ExcepcionFueraTablero_h
#define ExcepcionFueraTablero_h
#include <stdio.h>
#include <stdexcept>

using namespace std;

class ExcepcionFueraTablero : public out_of_range {
public:
    ExcepcionFueraTablero() : out_of_range("Excepcion: coordenada introducida fuera del tablero") {}
};

#endif /* ExcepcionFueraTablero_h */
