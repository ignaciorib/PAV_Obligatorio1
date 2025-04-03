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

DtGato::DtGato(int tP) {
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
