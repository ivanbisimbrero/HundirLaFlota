//
//  main.cpp
//  HundirLaFlota
//
//  Created by Ivan on 4/1/23.
//

#include <iostream>
#include "Partida.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    //Casilla aux(6, 3);
    //Buque prueba(aux, true);
    //prueba.mostrarCasillas();
    /*
    try {
        miTablero.colocarBarco("Submarino", A, 7, false);
        miTablero.colocarBarco("Buque", B, 5, false);
    } catch(ExcepcionMalColocado& ex) {
        cout << ex.what() << endl;
    } catch(ExcepcionFueraTablero& ex) {
        cout << ex.what() << endl;
    }
     */
    //cout << "Buenas tardes" << endl;
    //cin >> aux;
    Partida hundirLaFlota;
    hundirLaFlota.juego();
    return 0;
}
