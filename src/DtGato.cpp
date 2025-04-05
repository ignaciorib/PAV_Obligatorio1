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
            pelo = TipoPelo::Corto;
            break;
        case 2:
            pelo = TipoPelo::Mediano;
            break;
        case 3:
            pelo = TipoPelo::Largo;
            break;
    }
}

int DtGato::getTipoPelo () {
    switch (pelo) {
    case TipoPelo::Corto:
        return 1;
        break;
    case TipoPelo::Mediano:
        return 2;
        break;
    case TipoPelo::Largo:
        return 3;
        break;
    }
    default: 
        return 0;
        break;
}
