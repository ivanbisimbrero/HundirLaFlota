//
//  Patrullero.cpp
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#include "Patrullero.h"

Patrullero::Patrullero() : Barco(Casilla(0,1), 2, true) {}

Patrullero::Patrullero(Casilla c, bool vert) : Barco(c, 2, vert) {}

Patrullero::Patrullero(const Patrullero& p) {
    hundido = p.hundido;
    coordenadaInicial = p.coordenadaInicial;
    longitud = p.longitud;
    casillasBarco = new Casilla[longitud];
    for(int i = 0; i < longitud; i++) {
        casillasBarco[i] = p.casillasBarco[i];
    }
    vertical = p.vertical;
}

Patrullero& Patrullero::operator=(const Patrullero& opDrcha) {
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
