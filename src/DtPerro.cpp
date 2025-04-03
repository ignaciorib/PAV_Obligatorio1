#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "Genero.h"
#include "DtMascota.h"
#include "RazaPerro.h"
#include "DtPerro.h"


DtPerro::DtPerro() {}

DtPerro::DtPerro(RazaPerro r, bool vC) {
    raza = r;
    vacunaCachorro = vC;
}
