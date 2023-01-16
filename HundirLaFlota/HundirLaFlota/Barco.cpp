//
//  Barco.cpp
//  HundirLaFlota
//
//  Created by Ivan on 4/1/23.
//

#include "Barco.hpp"
Barco::Barco() {
    hundido = false;
    coordenadaInicial = Casilla(0, 1);
    coordenadaInicial.setBarco();
    longitud = 1;
    casillasBarco = new Casilla[1];
    vertical = true;
}

Barco::Barco(Casilla ini, int lon, bool vert) {
    hundido = false;
    coordenadaInicial = ini;
    coordenadaInicial.setBarco();
    longitud = lon;
    casillasBarco = new Casilla[longitud];
    vertical = vert;
    //Creamos variables auxiliares
    int fila = coordenadaInicial.getIntFila(), columna = coordenadaInicial.getColumna();
    if(vertical) {
        for(int i = 0; i < longitud; i++) {
            casillasBarco[i] = Casilla(fila + i, columna);
            casillasBarco[i].setBarco();
        }
    }
    else {
        for(int i = 0; i < longitud; i++) {
            casillasBarco[i] = Casilla(fila, columna + i);
            casillasBarco[i].setBarco();
        }
    }
}

Barco::Barco(const Barco& b) {
    hundido = b.hundido;
    coordenadaInicial = b.coordenadaInicial;
    longitud = b.longitud;
    casillasBarco = new Casilla[longitud];
    for(int i = 0; i < longitud; i++) {
        casillasBarco[i] = b.casillasBarco[i];
    }
    vertical = b.vertical;
}

bool Barco::comprobarHundido() {
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

Barco& Barco::operator=(const Barco& opDrcha) {
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

void Barco::mostrarCasillas() {
    for(int i = 0; i < longitud; i++) {
        casillasBarco[i].mostrar();
    }
}

bool Barco::isCasillaInBarco(Fila fila, int columna) {
    for(int i = 0; i < longitud; i++) {
        if(casillasBarco[i].getColumna() == columna && casillasBarco[i].getFila() == fila) {
            return true;
        }
    }
    return false;
}

void Barco::marcarCoordenada(Fila fila, int columna) {
    if(isCasillaInBarco(fila, columna)) {
        for(int i = 0; i < longitud; i++) {
            if(casillasBarco[i].getFila() == fila && casillasBarco[i].getColumna() == columna) {
                casillasBarco[i].marcarCasillaDisparada();
            }
        }
    }
}
