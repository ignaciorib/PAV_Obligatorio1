#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include "Mascota.h"
#include "Genero.h"
#include "Perro.h"
#include "RazaPerro.h"


Perro::Perro() {}


Perro::Perro(RazaPerro r, bool v) {
    raza = r;
    vacunaCachorro = v;
}

float Perro::obtenerRD() {
    return getPeso() * 0,025;
}

RazaPerro Perro::getRazaP() {
    return raza;
}

bool Perro::vacu() {
    return vacunaCachorro;
}
