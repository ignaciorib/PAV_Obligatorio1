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

DtGato::DtGato(TipoPelo tP) {
    pelo = tP;
}
