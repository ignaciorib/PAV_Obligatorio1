#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "../headers/Genero.h"
#include "../headers/DtMascota.h"
#include "../headers/RazaPerro.h"
#include "../headers/DtPerro.h"


DtPerro::DtPerro() {}

DtPerro::DtPerro(RazaPerro r, bool vC) {
    raza = r;
    vacunaCachorro = vC;
}
