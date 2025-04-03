#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "Genero.h"
#include "DtMascota.h"
#include "RazaPerro.h"
#include "DtPerro.h"
#include "DtGato.h"

DtGato::DtGato() {}

DtGato::DtGato(TipoPelo tP) {
    pelo = tP;
}
