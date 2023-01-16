//
//  Submarino.cpp
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#include "Submarino.hpp"

Submarino::Submarino() : Barco(Casilla(0,1), 3, true) {}

Submarino::Submarino(Casilla c, bool vert) : Barco(c, 3, vert) {}

Submarino::Submarino(const Submarino& s) {
    hundido = s.hundido;
    coordenadaInicial = s.coordenadaInicial;
    longitud = s.longitud;
    casillasBarco = new Casilla[longitud];
    for(int i = 0; i < longitud; i++) {
        casillasBarco[i] = s.casillasBarco[i];
    }
    vertical = s.vertical;
}

Submarino& Submarino::operator=(const Submarino& opDrcha) {
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
