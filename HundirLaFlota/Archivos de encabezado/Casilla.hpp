//
//  Casilla.hpp
//  HundirLaFlota
//
//  Created by Ivan on 4/1/23.
//

#ifndef Casilla_hpp
#define Casilla_hpp

#include <stdio.h>
#include "Fila.hpp"

using namespace std;

class Casilla {
private:
    bool disparada;
    bool hayBarco;
    Fila coordenadaY;
    int coordenadaX;
public:
    Casilla();
    Casilla(int, int);
    void modificarCoordenadas(int, int);
    bool comprobarOcupacion();
    void marcarCasillaDisparada();
    void setBarco();
    bool comprobarDisparo();
    Fila getFila(int);
    int getIntFila();
    int getColumna();
    Fila getFila() {return coordenadaY;}
    void mostrar();
    friend istream& operator>>(istream&, Casilla&);
    friend ostream& operator<<(ostream&, Casilla&);
};
 
#endif /* Casilla_hpp */
