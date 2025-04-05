#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include "../headers/Mascota.h"
#include "../headers/Genero.h"
#include "../headers/Perro.h"
#include "../headers/RazaPerro.h"


Perro::Perro() {}


Perro::Perro(string n, float p, int genero, int raza, bool v) : Mascota(n, p, genero) {
    switch (raza) {
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
