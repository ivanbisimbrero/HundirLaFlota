//
//  Buque.cpp
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#include "Buque.h"

Buque::Buque() : Barco(Casilla(0,1), 1, true) {}

Buque::Buque(Casilla c, bool vert) : Barco(c, 1, vert) {}

Buque::Buque(const Buque& b) {
    hundido = b.hundido;
    coordenadaInicial = b.coordenadaInicial;
    longitud = b.longitud;
    casillasBarco = new Casilla[longitud];
    for(int i = 0; i < longitud; i++) {
        casillasBarco[i] = b.casillasBarco[i];
    }
    vertical = b.vertical;
}

bool Buque::comprobarHundido() {
    bool comprobacion = true;
    for(int i = 0; i < longitud; i++) {
        if(!(casillasBarco[i].comprobarDisparo())) {
            comprobacion = false;
        }
    }
    if(comprobacion) {
        hundido = true;
        return hundido;
    }
    else {
        return hundido;
    }
}

Buque& Buque::operator=(const Buque& opDrcha) {
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
