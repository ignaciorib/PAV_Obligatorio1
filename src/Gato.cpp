#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include "../headers/Genero.h"
#include "../headers/Gato.h"


Gato::Gato() {}

Gato::Gato(string n, float p, int genero, int tP) : Mascota(n, p, genero) {
    
    switch (tP) {
        case 1:
            TipoPeloG = TipoPelo::Corto;
            break;
        case 2:
            TipoPeloG = TipoPelo::Mediano;
            break;
        case 3:
            TipoPeloG = TipoPelo::Largo;
            break;
    }
}

int Gato::getTipoPelo () {
    switch (TipoPeloG) {
        case TipoPelo::Corto:
            return 1;
            break;
        case TipoPelo::Mediano:
            return 2;
            break;
        case TipoPelo::Largo:
            return 3;
            break;
        default:
            return 0;
            break;
    }
}

float Gato::obtenerRD() {
    return getPeso() * 0,015;
}
