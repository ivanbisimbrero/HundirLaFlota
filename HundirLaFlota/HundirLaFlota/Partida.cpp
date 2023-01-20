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
    jugadores = new Jugador[2];
    for(int i = 0; i < 2; i++) {
        jugadores[i].setId(i+1);
    }
}

void Partida::iniciarPartida() {
    partidaEnCurso = true;
    jugadores[0].colocarBarcos();
    jugadores[1].colocarBarcos();
    jugadores[0].setTurno(true);
}

void Partida::cargarPartida() {
    //TODO: funcion que cargue la partida desde un fichero por defecto
}

void Partida::guardarPartida() {
    //TODO: funcion que cargue la partida desde un fichero por defecto
}

void Partida::disparar() {
    int idAtacado = -1, idAtacante = -1;
    Casilla disparo;
    for(int i = 0; i < 2; i++) {
        if(jugadores[i].getTurno()) {
            if(i == 0) {
                idAtacante = 0;
                idAtacado = 1;
            }
            else {
                idAtacante = 1;
                idAtacado = 0;
            }
        }
    }
    
    while(jugadores[idAtacante].getTurno()) {
        try {
            cout << "Jugador " << jugadores[idAtacante].getId() << " introduzca la coordenada de disparo:" << endl;
            cin >> disparo;
            jugadores[idAtacado].disparar(disparo.getFila(), disparo.getColumna());
            jugadores[idAtacante].marcarCasilla(disparo.getFila(), disparo.getColumna(),
                                                jugadores[idAtacado].isTocado(disparo));
            if(!(jugadores[idAtacado].isTocado(disparo))) {
                jugadores[idAtacado].setTurno(true);
                jugadores[idAtacante].setTurno(false);
            }
        } catch (ExcepcionFueraTablero& ex) {
            cout << ex.what() << " Intentelo de nuevo." << endl;
        }
    }
}

void Partida::setPause(bool p) {
    pause = p;
}

void Partida::abandonar() {
    if(jugadores[0].getTurno()) {
        cout << "El Jugador " << jugadores[0].getId() << " se ha rendido" << endl;
        cout << "Jugador " << jugadores[1].getId() << " , enhorabuena, has ganado la partida!!" << endl;
    }
    else {
        cout << "El Jugador " << jugadores[1].getId() << " se ha rendido" << endl;
        cout << "Jugador " << jugadores[0].getId() << " ,enhorabuena, has ganado la partida!!" << endl;
    }
    partidaEnCurso = false;
    pause = false;
}

void Partida::salirPartida() {
    char opcion = '\0';
    cout << "Desea guardar la partida(S/N): " << endl;
    cout << "--> ";
    cin >> opcion;
    switch(opcion) {
        case 'S':
        case 's':
            guardarPartida();
            pause = false;
            partidaEnCurso = false;
        case 'N':
        case 'n':
            pause = false;
            partidaEnCurso = false;
        default:
            cout << "Opcion no valida, intentelo de nuevo." << endl;
    }
}

void Partida::juego() {
    iniciarPartida();
    char opcion = '\0';
    while(partidaEnCurso) {
        if(jugadores[0].getTurno()) {
            cout << "Jugador "<< jugadores[0].getId() <<" que desea hacer: " << endl;
        }
        else {
            cout << "Jugador "<< jugadores[1].getId() <<" que desea hacer: " << endl;
        }
        cout << "-Disparar[D]" << endl;
        cout << "-Pausa[P]" << endl;
        cout << "--> ";
        cin >> opcion;
        switch(opcion) {
            case 'D':
            case 'd':
                disparar();
                break;
            case 'P':
            case 'p':
                setPause(true);
                break;
            default:
                cout << "Opcion no valida, intentelo de nuevo." << endl;
        }
        if(pause) {
            while(pause) {
                cout << "La partida se encuentra en pausa, introduzca una opcion" << endl;
                cout << "-Guardar Partida[G]" << endl;
                cout << "-Aceptar tu derrota[D]" << endl;
                cout << "-Salir de la partida[X]" << endl;
                cout << "-Reanudar partida[R]" << endl;
                cout << "--> ";
                cin >> opcion;
                switch(opcion) {
                    case 'G':
                    case 'g':
                        guardarPartida();
                        break;
                    case 'D':
                    case 'd':
                        abandonar();
                        break;
                    case 'X':
                    case 'x':
                        salirPartida();
                        break;
                    case 'R':
                    case 'r':
                        setPause(false);
                        break;
                    default:
                        cout << "Opcion no valida, intentelo de nuevo." << endl;
                }
            }
        }
    }
    cout << endl << "Gracias por jugar, regrese pronto!!" << endl;
}
