//
//  Jugador.cpp
//  HundirLaFlota
//
//  Created by Ivan on 5/1/23.
//

#include "Jugador.hpp"

Jugador::Jugador() {
    turno = false;
    tablerosJugador = new Tablero[2]; //Posicion 0 --> Barcos, Posicion 1 --> Disparos
    for(int i = 0; i < 5; i++) {
        switch (i) {
            case 0:
                barcos[i] = new Portaaviones();
                break;
            case 1:
                barcos[i] = new Acorazado();
                break;
            case 2:
                barcos[i] = new Submarino();
                break;
            case 3:
                barcos[i] = new Patrullero();
                break;
            case 4:
                barcos[i] = new Buque();
                break;
        }
    }
    identifier = 0;
}

Jugador::Jugador(const Jugador& j) {
    turno = j.turno;
    tablerosJugador = new Tablero[2];
    for(int i = 0; i < 2; i++) {
        tablerosJugador[i] = j.tablerosJugador[i];
    }
    for(int i = 0; i < 5; i++) {
        barcos[i] = j.barcos[i];
    }
    identifier = j.identifier;
}

Jugador& Jugador::operator=(const Jugador& opDrcha) {
    turno = opDrcha.turno;
    tablerosJugador = new Tablero[2];
    for(int i = 0; i < 2; i++) {
        tablerosJugador[i] = opDrcha.tablerosJugador[i];
    }
    for(int i = 0; i < 5; i++) {
        barcos[i] = opDrcha.barcos[i];
    }
    identifier = opDrcha.identifier;
    return *this;
}

void Jugador::setId(int id) {
    identifier = id;
}

bool Jugador::comprobarBarcos() {
    bool flotaHundida = true;
    for(int i = 0; i < 5; i++) {
        if(!(barcos[i]->comprobarHundido())) {
            flotaHundida = false;
        }
    }
    return flotaHundida;
}

void Jugador::disparar(Fila fila, int columna) {
    if(fila == ERR || columna < 0 || columna > 10) {
        throw ExcepcionFueraTablero();
    }
    else {
        if(!(tablerosJugador[0].comprobarDisparo(fila, columna))) {
            tablerosJugador[0].marcarCoordenada(fila, columna);
            for(int i = 0; i < 5; i++) {
                barcos[i]->marcarCoordenada(fila, columna);
            }
            if(tablerosJugador[0].comprobarCoordenada(fila, columna)) {
                cout << "Tocado";
                
                if(comprobarBarcos()) {
                    cout << ", hundido y flota destruida";
                }
                else  {
                    for(int i = 0; i < 5; i++) {
                        if(barcos[i]->isCasillaInBarco(fila, columna)) {
                            if(barcos[i]->comprobarHundido()) {
                                cout << " y hundido";
                            }
                        }
                    }
                }
                cout << endl;
            }
            else {
                cout << "Agua" << endl;
            }
        }
        else {
            cout << "La coordenada introducida ya ha sido disparada, intentelo de nuevo." << endl;
        }
    }
}

void Jugador::marcarCasilla(Fila fila, int columna, bool tocado) {
    tablerosJugador[1].marcarCoordenada(fila, columna);
    if(tocado) {
        tablerosJugador[1].establecerTocado(fila, columna);
    }
}

void Jugador::setTurno(bool turno) {
    this->turno = turno;
}

bool Jugador::comprobarDatos(char datoIntroducido) {
    switch(datoIntroducido) {
        case '0':
            return false;
        case '1':
            return true;
        default:
            throw invalid_argument("Excepcion: Argumento introducido no valido");
    }
}

void Jugador::colocarBarcos() {
    bool colocados = false, orientacion;
    int counter = 0;
    Casilla casillaAux;
    char cOrientacion;
    while(!colocados) {
        //TODO: mostrar tablero --> hacer en windows
        cout << "Jugador " << identifier << " introduzca las coordenadas del " << barcos[counter]->getType() << endl;
        cout << "A continuacion tendra que introducir la coordenada inicial que desee: " << endl;
        cin >> casillaAux;
        cout << "Quieres colocarlo horizontalmente(0) o verticalmente(1): " << endl;
        cin >> cOrientacion;
        try {
            orientacion = comprobarDatos(cOrientacion);
            try {
                tablerosJugador[0].colocarBarco(barcos[counter]->getType(), casillaAux.getFila(), casillaAux.getColumna(), orientacion);
                switch (counter) {
                    case 0:
                        barcos[counter] = new Portaaviones(casillaAux, orientacion);
                        break;
                    case 1:
                        barcos[counter] = new Acorazado(casillaAux, orientacion);
                        break;
                    case 2:
                        barcos[counter] = new Submarino(casillaAux, orientacion);
                        break;
                    case 3:
                        barcos[counter] = new Patrullero(casillaAux, orientacion);
                        break;
                    case 4:
                        barcos[counter] = new Buque(casillaAux, orientacion);
                        break;
                }
                counter++;
            } catch(ExcepcionMalColocado& ex) {
                cout << ex.what() << endl;
            } catch(ExcepcionFueraTablero& ex) {
                cout << ex.what() << endl;
            }
        } catch(invalid_argument& ex) {
            cout << ex.what() << endl;
        }
        if(counter == 5) {
            colocados = true;
        }
        //TODO: Add system cls in windows
    }
    
}

bool Jugador::isTocado(Casilla c) {
    if(tablerosJugador[0].comprobarDisparo(c.getFila(), c.getColumna()) &&
       tablerosJugador[0].comprobarCoordenada(c.getFila(), c.getColumna())) {return true;}
    else {return false;}
}
