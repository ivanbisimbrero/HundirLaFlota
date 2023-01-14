//
//  Portaaviones.cpp
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#include "Portaaviones.h"

Portaaviones::Portaaviones() : Barco(Casilla(0,1), 5, true) {}

Portaaviones::Portaaviones(Casilla c, bool vert) : Barco(c, 5, vert) {}

Portaaviones::Portaaviones(const Portaaviones& p) {
    hundido = p.hundido;
    coordenadaInicial = p.coordenadaInicial;
    longitud = p.longitud;
    casillasBarco = new Casilla[longitud];
    for(int i = 0; i < longitud; i++) {
        casillasBarco[i] = p.casillasBarco[i];
    }
    vertical = p.vertical;
}

Portaaviones& Portaaviones::operator=(const Portaaviones& opDrcha) {
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
