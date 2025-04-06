#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "../headers/Genero.h"
#include "../headers/DtMascota.h"
#include "../headers/RazaPerro.h"
#include "../headers/DtPerro.h"
#include "../headers/DtGato.h"

DtGato::DtGato() {}

DtGato::DtGato(string n, int g, float p, int p_g, int tP) {
    DtMascota(n, g, p, p_g);
    switch (tP) {
        case 1:
            pelo = tipoPelo::Corto;
            break;
        case 2:
            pelo = tipoPelo::Mediano;
            break;
        case 3:
            pelo = tipoPelo::Largo;
            break;
    }
}

int DtGato::getTipoPelo () {
    switch (pelo) {
    case tipoPelo::Corto:
        return 1;
        break;
    case tipoPelo::Mediano:
        return 2;
        break;
    case tipoPelo::Largo:
        return 3;
        break;
    default: 
    }
}

void DtGato::setTipoPelo(int x){ // por que a mi me sirve el punto y coma pero arriba no(?)
    switch (x) {
        case 1:
        pelo = tipoPelo::Corto;
        break;
        case 2:
        pelo = tipoPelo::Mediano;
        break;
        case 3:
        pelo = tipoPelo::Largo;
        break;
        default: 
        }
}
