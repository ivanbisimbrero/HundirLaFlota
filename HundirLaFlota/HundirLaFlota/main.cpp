//
//  main.cpp
//  HundirLaFlota
//
//  Created by Ivan on 4/1/23.
//

#include <iostream>
#include "Tablero.h"
#include "Jugador.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Tablero miTablero;
    Casilla aux(1, 2);
    //Barco prueba(aux, 4, true);
    //prueba.mostrarCasillas();
    try {
        miTablero.colocarBarco("Submarino", A, 7, false);
        miTablero.colocarBarco("Buque", B, 5, false);
    } catch(ExcepcionMalColocado& ex) {
        cout << ex.what() << endl;
    } catch(ExcepcionFueraTablero& ex) {
        cout << ex.what() << endl;
    }
    //cout << "Buenas tardes" << endl;
    //cin >> aux;
    Jugador miOscar;
    miOscar.colocarBarcos();
    return 0;
}
