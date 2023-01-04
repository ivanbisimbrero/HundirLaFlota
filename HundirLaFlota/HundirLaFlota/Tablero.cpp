//
//  Tablero.cpp
//  HundirLaFlota
//
//  Created by Ivan on 4/1/23.
//

#include "Tablero.h"

Tablero::Tablero() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tablero[i][j] = Casilla(i, j);
        }
    }
}
