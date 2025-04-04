#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include "../headers/Mascota.h"
#include "../headers/Genero.h"
#include "../headers/Perro.h"
#include "../headers/RazaPerro.h"


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

bool Perro::getVacu() {
    return vacunaCachorro;
}
