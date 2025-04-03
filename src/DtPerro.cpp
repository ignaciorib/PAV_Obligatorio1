#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "../headers/Genero.h"
#include "../headers/DtMascota.h"
#include "../headers/RazaPerro.h"
#include "../headers/DtPerro.h"


DtPerro::DtPerro() {}

DtPerro::DtPerro(int r, bool vC) {
    switch (r) {
        case 1:
            raza = RazaPerro::labrador;
            break;
        case 2:
            raza = RazaPerro::ovejero;
            break;
        case 3:
            raza = RazaPerro::bulldog;
            break;
        case 4:
            raza = RazaPerro::pitbull;
            break;
        case 5:
            raza = RazaPerro::collie;
            break;
        case 6:
            raza = RazaPerro::pekines;
            break;
        case 7:
            raza = RazaPerro::otro;
            break;
    }
    vacunaCachorro = vC;
}
