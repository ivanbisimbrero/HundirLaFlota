//
//  Acorazado.cpp
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#include "Acorazado.h"

Acorazado::Acorazado() : Barco(Casilla(0,1), 4, true) {}

Acorazado::Acorazado(Casilla c, bool vert) : Barco(c, 4, vert) {}

Acorazado::Acorazado(const Acorazado& a) {
    hundido = a.hundido;
    coordenadaInicial = a.coordenadaInicial;
    longitud = a.longitud;
    casillasBarco = new Casilla[longitud];
    for(int i = 0; i < longitud; i++) {
        casillasBarco[i] = a.casillasBarco[i];
    }
    vertical = a.vertical;
}

Acorazado& Acorazado::operator=(const Acorazado& opDrcha) {
    hundido = opDrcha.hundido;
    coordenadaInicial = opDrcha.coordenadaInicial;
    longitud = opDrcha.longitud;
    casillasBarco = new Casilla[longitud];
    for(int i = 0; i < longitud; i++) {
        casillasBarco[i] = opDrcha.casillasBarco[i];
    }
    vertical = opDrcha.vertical;
    
    return *this;
}
