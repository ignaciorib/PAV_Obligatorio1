#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include "Genero.h"
#include "Gato.h"


Gato::Gato() {}

Gato::Gato(TipoPelo t) {
    TipoPeloG = t;
}

float Gato::obtenerRD() {
    return getPeso() * 0,015;
}
