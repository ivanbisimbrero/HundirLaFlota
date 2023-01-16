//
//  Barco.h
//  HundirLaFlota
//
//  Created by Ivan on 4/1/23.
//

#ifndef Barco_hpp
#define Barco_hpp

#include <stdio.h>
#include <iostream>
#include "Casilla.hpp"

using namespace std;

class Barco {
protected:
    bool hundido;
    Casilla coordenadaInicial;
    int longitud;
    Casilla* casillasBarco;
    bool vertical;
public:
    Barco();
    Barco(Casilla, int, bool);
    Barco(const Barco&);
    bool comprobarHundido();
    Barco& operator=(const Barco&);
    void mostrarCasillas();
    virtual string getType() = 0;
    bool isCasillaInBarco(Fila, int);
    void marcarCoordenada(Fila, int);
};

#endif /* Barco_h */
