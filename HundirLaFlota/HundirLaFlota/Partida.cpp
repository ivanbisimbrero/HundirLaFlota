//
//  Partida.cpp
//  HundirLaFlota
//
//  Created by Ivan on 16/1/23.
//

#include "Partida.hpp"

Partida::Partida() {
    partidaEnCurso = false;
    pause = false;
    j1.setId(1);
    j2.setId(2);
}

void Partida::iniciarPartida() {
    partidaEnCurso = true;
    j1.colocarBarcos();
    j2.colocarBarcos();
    j1.setTurno(true);
}

void Partida::cargarPartida() {
    //TODO: funcion que cargue la partida desde un fichero
}

void Partida::guardarPartida() {
    
}

void Partida::disparar() {
    Casilla disparo;
    if(j1.getTurno()) {
        while(j1.getTurno()) {
            cout << "Jugador " << j1.getId() << " introduzca la coordenada de disparo:" << endl;
            cin >> disparo;
            j2.disparar(disparo.getFila(), disparo.getColumna());
            j1.marcarCasilla(disparo.getFila(), disparo.getColumna(),
                             j2.isTocado(disparo));
            if(!(j2.isTocado(disparo))) {
                j2.setTurno(true);
                j1.setTurno(false);
            }
        }
    }
    else {
        while(j2.getTurno()) {
            cout << "Jugador " << j2.getId() << " introduzca la coordenada de disparo:" << endl;
            cin >> disparo;
            j1.disparar(disparo.getFila(), disparo.getColumna());
            j2.marcarCasilla(disparo.getFila(), disparo.getColumna(),
                             j1.isTocado(disparo));
            if(!(j1.isTocado(disparo))) {
                j1.setTurno(true);
                j2.setTurno(false);
            }
        }
    }
    /*
    while(jugadores[idAtacante].getTurno()) {
        cout << "Jugador " << jugadores[idAtacante].getId() << " introduzca la coordenada de disparo:" << endl;
        cin >> disparo;
        jugadores[idAtacado].disparar(disparo.getFila(), disparo.getColumna());
        jugadores[idAtacante].marcarCasilla(disparo.getFila(), disparo.getColumna(),
                                            jugadores[idAtacado].isTocado(disparo));
        if(!(jugadores[idAtacado].isTocado(disparo))) {
            jugadores[idAtacado].setTurno(true);
            jugadores[idAtacante].setTurno(false);
        }
    }
     */
}


